#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <iomanip>
#include <cstdio>
#include <set>
#include <map>
#include <list>
#include <cstdlib>
#include <queue>
#include <stack>
#include <bitset>

using namespace std;

#define MOD 998244353
#define PI 3.1415926535897932
#define INF 1e9
#define rep(i, n) for (int i = 0; i < n; i++)
#define repe(i, j, n) for (int i = j; i < n; i++)
#define repi(i, n) for (int i = 0; i <= n; i++)
#define repie(i, j, n) for (int i = j; i <= n; i++)
#define all(x) x.begin(), x.end()
#define println() cout << endl
#define P pair<int, int>
#define fi first
#define se second


typedef long long ll;
using Graph = vector<vector<ll>>;

void solve1() {
    int n, k; cin >> n >> k;
    cin.ignore();
    vector<vector<char>> c(k+1, vector<char>(2*n-1));

    rep(i, k+1) {
        string s; 
        getline(cin, s);

        rep(j, (int)s.size()) {
            c[i][j] = s[j];
        }

      
    }

    rep(i, n) {
        int h = 0;
        int w = 2*i;
        //cout << i << h << w << endl;
        while(h < k) {
        
        if(w+1 < 2*n-1 && c[h][w+1]=='-') {
            w += 2;
        } else if(w-1 > 0 && c[h][w-1]=='-') {
            w -= 2;
        }

        h++;

         //cout << i << h << w << endl;
        }

        //cout << i << h << w << endl;
        //cout << endl;

        if(c[h][w]=='o') {
            cout << i +1 << endl;
            return;
        }
    }
}

int main()
{
    solve1();
}

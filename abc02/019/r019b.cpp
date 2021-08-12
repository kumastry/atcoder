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

#define MOD 1000000007
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
using Graph = vector<vector<int>>;

typedef long long ll;


void solve1() {
    string s; cin >> s;
    int cnt = 1;
    if(s.size() == 1) {
        cout << s[0] << 1 << endl;
        return;
    } 
    for(int i = 0; i < (int)s.size()-1; i++) {
        if(i != (int)s.size() - 2) {
            if(s[i] == s[i+1]) {
                cnt ++;
            } else {
                cout << s[i] << cnt;
                cnt = 1;
            }
        } else {
            if(s[i] == s[i+1]) {
                cnt ++;
                cout << s[i] << cnt;
            } else {
                cout << s[i] << cnt << s[i+1] << 1;
            }
        }
    }

    cout << endl;
}

int main()
{
    solve1();
}

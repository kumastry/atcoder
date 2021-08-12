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
    ll n; string t;
    cin >> n >> t;

    if(n == 1) {
        if(t[0] == '1') {
            cout << 20000000000 << endl;
        } else {
            cout << 10000000000 << endl;
        }
    } else if(n== 2) {
        if(t == "10" || t == "11") {
            cout << 10000000000 << endl;
        } else if(t == "01") {
            cout << 9999999999 << endl;
        } else {
            cout << 0 << endl;
        }
    } else {
        int s;
        if(t[0]+t[1] == '11') {
            s = 0;
        } else if(t[0]+t[1] == '10') {
            s = 2;
        } else if(t[0]+t[1] == '01') {
            s = 1;
        } else {
            cout << 0 << endl;
            return;
        }

        int idx = 0;
        for(int i = s; i < n; i++) {
            if(idx%3 < 2 && t[i] == '0') {
                cout << 0 << endl;
                return;
            } 

            if(idx%3 == 2 && t[i] == '1') {
                cout << 0 << endl;
                return;
            }
            idx ++; 
        }

        if(s == 0) {
            int size = (int)t.size();
            cout << 10000000000 - floor(size/3.0)+1;
        } else if(s == 1) {
            int size = (int)t.size();
            cout << 10000000000 - floor((size-2)/3.0)+1;
        } else {
            int size = (int)t.size();
            cout << 10000000000 - floor((size-1)/3.0)+1;
        }
    }
}

int main()
{
    solve1();
}

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

typedef long long ll;

ll modinv(ll a, ll m)
{
    ll b = m, u = 1, v = 0;
    while (b)
    {
        ll t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }

    u %= m;
    if (u < 0)
        u += m;
    return u;
}

using G = vector<vector<int>>;


void solve1() {
    int n; cin >> n;
    vector<vector<char>> s(2, vector<char>(n));

    rep(i, 2) {
        rep(j, n) {
            cin >> s[i][j];
        }
    }

    ll ans = 1;
    int i = 0;
    while(i < n) {
       
        if(i == 0) {
            ans *= 3;

            if(s[0][i] == s[0][i+1]) {
                i += 2;
            } else if(s[0][i] == s[1][i]) {
                i ++;
            }

        } else if(i != n-1){
            ans *= 2;
            //ans %= MOD;

            if(s[0][i] == s[0][i+1]) {
                i += 2;
            } else if(s[0][i] == s[1][i]) {
                i ++;
            }

            
        } else {
            ans *= 2;
            //ans %= MOD;
            i ++;
        }

        
    }

    cout << ans << endl;
}

int main()
{
    solve1();
}

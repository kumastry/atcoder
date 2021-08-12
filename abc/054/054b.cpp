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
    int n, m; cin >> n >> m;
    vector<string> s(n);
    vector<string> t(m);

    rep(i, n) {
        cin >> s[i];
    }

    rep(j, m) {
        cin >> t[j];
    }

    string ans = "No";
    for(int i = 0; i < n - m + 1; i++) {
        for(int j = 0; j < n - m + 1; j++) {
            bool f = true;
            bool ff = false;

            rep(k, m) {
                rep(l, m) {
                    if(t[k][l] != s[i+k][j+l]) {
                        f = false;
                    }
                }
            }


            if(f) {
                ff = true;
            }
            

            if(ff) {
                ans = "Yes";
                break;
            }
        }
    }

    cout << ans << endl;
}

int main()
{
    solve1();
}

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




void solve1() {
    int n, m; cin >> n >> m;

    vector<vector<ll>> dist(n, vector<ll>(n, (ll)1e18));

    rep(i, n) {
        rep(j, n) {
            if(i == j) {
                dist[i][j] = 0;
            }
        }
    }
    
    rep(i, m) {
        int a, b, c; cin >> a >> b >> c;
        a--; b--;
        dist[a][b] = c;
        dist[b][a] = c;
    }


    rep(k, n) {
        rep(i, n) {
            rep(j, n) {
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }

    ll ans = 1e18;
    for(int i = 0; i < n; i++) {
        ll tmp = -1;
        for(int j = 0; j < n; j++) {
           
            if(dist[i][j] != 1e18) {
                tmp = max(tmp, dist[i][j]);
            }
        }

        ans = min(ans, tmp);
    }

     
    cout << ans << endl;

}

int main()
{
    solve1();
}

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

long long modinv(long long a, long long m)
{
    long long b = m, u = 1, v = 0;
    while (b)
    {
        long long t = a / b;
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
    ll n, m; cin >> n >> m;
    vector<ll> w(n), v(n);
    rep(i, n) {
        cin >> w[i] >> v[i];
    }

   int k = w[0];

    m -= w[0];
    rep(i, n) {
        w[i] -= w[0];
    }

    vector<vector<ll>> dp(n+1, vector<ll>(3*n+1));
    for(int i = 0; i <= 3*n; i++) {
        dp[0][i] = 0;
    }

    for(int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= 3*n; j++) {
            if(j >= w[i]) {
                dp[i+1][j] = max(dp[i][j], dp[i][j-w[i]] + v[i]);
            } else {
                dp[i+1][j] = dp[i][j];
            }

            cout << i+1 << " " << j+n*k << " " << dp[i+1][j] << endl;
        }
    }

    ll ans = 0;
    for(int i = 0; i <= 3*n; i++) {
        if(i <= m) {
          ans = max(ans, dp[n][i]);
        } else {
            break;
        }
    }
    cout << ans << endl;
  
}

int main()
{
    solve1();
}

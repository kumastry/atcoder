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
#define INF 1e18
#define rep(i, n) for (int i = 0; i < n; i++)
#define repe(i, j, n) for (int i = j; i < n; i++)
#define repi(i, n) for (int i = 0; i <= n; i++)
#define repie(i, j, n) for (int i = j; i <= n; i++)
#define all(x) x.begin(), x.end()
#define println() cout << endl

#define fi first
#define se second

typedef long long ll;
#define P pair<ll, ll>

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

bool f(P a, P b) {
    if(a.fi == b.fi) {
        return a.se < b.se;
    } else {
        return a.fi < b.fi;
    }
}

void solve1() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, W; cin >> n >> W;
    vector<ll> v(n), w(n);
    ll mv = -1, mw = -1;
    ll V = 0;
    rep(i, n) {
        cin >> v[i] >> w[i];
        mv = max(mv, v[i]);
        V += v[i];
        mw = max(mw, w[i]);
    }

    if(n <= 30) {
        P s[500000];
    
        int h = n/2;
        for(int i = 0; i < ( 1 << h); i++) {
            ll sumv = 0, sumw = 0;
            for(int j = 0; j < h; j++) {
                if((i >> j) & 1 ) {
                    sumv += v[j];
                    sumw += w[j];
                }
            }
            //cout << i  << endl;
            s[i] = P(sumw, sumv);
        }

       
        sort(s, s+(1 << h));
        ll m = 1;
        for(int i = 0; i < (1 << (n-h)); i++) {
            if(s[m-1].se < s[i].se) {
                s[m++] = s[i];
            }
        }

        

    vector<P> d;
    ll ans = 0;
    for(int i = 0;i < (1 << (n-h)); i++) {
        ll sumw = 0, sumv = 0;
        for(int j = 0; j < n-h; j++) {
            if(i & (1 << j)) {
                sumw += w[h+j];
                sumv += v[h+j];
            }
        }

        if(sumw <=W) {
             ll tv = (lower_bound(s, s+m, make_pair(W-sumw, 1ll<<55))-1)->second;
             ans = max(ans, sumv+tv);
        }
    }

    cout << ans << endl;
        
    } else if(mw <= 1000) {
        W = min(W, mw*n);
        vector<vector<ll>> dp(n+1, vector<ll>(W+1));
        for(int i = 0; i < W + 1; i++) {
            dp[0][i] = 0;
        }

        for(int i = 0; i < n + 1; i++) {
            dp[i][0] = 0;
        }
        

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < W + 1; j++) {
                if(j >= w[i]) {
                    dp[i+1][j] = max(dp[i][j], dp[i][j-w[i]]+v[i]);
                } else {
                    dp[i+1][j] = dp[i][j];
                }
            }
        }

        cout << dp[n][W] << endl;
   } else {
       vector<vector<ll>> dp(n+1, vector<ll>(V+1));
        for(int i = 0; i < V + 1; i++) {
            dp[0][i] = INF;
        }

        dp[0][0] = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < V+1; j ++) {
                if(j >= v[i]) {
                    dp[i+1][j] = min(dp[i][j], dp[i][j-v[i]]+w[i]);
                } else {
                    dp[i+1][j] = dp[i][j];
                }
            }
        }

        ll ans = -1;
        for(ll i = 0; i <= V; i++) {
            if(dp[n][i] <= W) {
                ans = max(ans, i);
            }
        }

        cout << ans << endl;
   }
}

int main()
{
    solve1();
}

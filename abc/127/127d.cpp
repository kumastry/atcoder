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

ll f(ll x) {
    if(x < 10) {
        return x;
    }

    return x%10 + f(x/10);
}

bool sec(pair<ll, ll> a, pair<ll, ll> b) {
    if(a.se == b.se) {
        return a.fi > b.fi;
    } else {
        return a.se > b.se;
    }
}

void solve1() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    ll ans = 0;
    rep(i, n) {
        cin >> a[i];
        ans += a[i];
    }

    vector<pair<ll, ll>> bc(k);
    rep(i, k) {
        cin >> bc[i].fi >> bc[i].se;
    }

    sort(all(a));
    sort(all(bc), sec);


    vector<ll> sums(n+1);
    sums[0] = 0;
    for(ll i = 0; i < n; i++) {
        sums[i+1] = sums[i] + a[i];
    }

    ll rn = 0;
    for(ll i = 0; i < k; i++) {
        if(bc[i].fi + rn < n) {
          if(a[bc[i].fi + rn] < bc[i].se) {
              ans -= sums[rn+bc[i].fi] - sums[rn];
              ans += bc[i].fi * bc[i].se;
              rn += bc[i].fi;
          } else {
              while(a[bc[i].fi + rn] >= bc[i].se && bc[i].fi >= 0) {
                  bc[i].fi --;
              }

              if(bc[i].fi <= 0) {
                  break;
              }

              bc[i].fi ++;

              ans -= sums[rn+bc[i].fi] - sums[rn];
              ans += bc[i].fi * bc[i].se;
              break;
          }
        } else {
            
            if(a[n-1] < bc[i].se) {
               ans -= sums[n-1] - sums[rn];
               ans += bc[i].fi * bc[i].se;
            } else {
                ll m = n - 1;
                while(a[m] >= bc[i].se) {
                    m --;
                }

                if(m < rn) {
                    break;
                }
                
                ans -= sums[m] - sums[rn];
                ans += bc[i].fi * bc[i].se;
            }
        }

     
    }

    cout << ans << endl;
}

int main()
{
    solve1();
}

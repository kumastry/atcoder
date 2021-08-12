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
#include <unordered_map>
#include <unordered_set>
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


template< typename T >
T mod_pow(T x, T n, const T &p) {
  T ret = 1;
  while(n > 0) {
    if(n & 1) (ret *= x) %= p;
    (x *= x) %= p;
    n >>= 1;
  }
  return ret;
} 

void solve1() {
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i, n) {
        cin >> a[i];
    }

    sort(all(a), greater<ll>());
    ll sum = a[0];
    for(int i = 1; i < n; i++) {
        sum = (sum+(a[i]*mod_pow<ll>(2, i-1, MOD)%MOD))%MOD;
        cout << sum << endl;
    }

    ll ans = 0;
    rep(i, n) {
        if(i == 0) {
            ans += a[i]*sum;
        } else {
            sum = (sum-(a[n-1]+1)*mod_pow<ll>(2, n-i-1, MOD))%MOD;
            if(sum < 0) {
                sum += MOD;
            }
            cout << "#### " << " " << sum  << " " <<  mod_pow<ll>(2, n-i-1, MOD) << endl;

            ans = (ans + (a[i]*sum)%MOD)%MOD;
        }

        cout << a[i] << " " << sum  << " " << ans << endl;
    }

    cout << ans << endl;

}

int main()
{
    solve1();
}

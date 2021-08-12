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

#define MOD 1000000007
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
    ll ma = -1;
    ll mi = 1e10;
    rep(i, n) {
        cin >> a[i];
        ma = max(ma, a[i]);
        mi = min(mi, a[i]);
    }

    mi ++;
    sort(all(a));
    cout << mod_pow<ll>(2, ma, 1000000007) -  mod_pow<ll>(2, mi, 1000000007) << endl;
}

int main()
{
    solve1();
}

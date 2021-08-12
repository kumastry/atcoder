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

void solve1() {
    ll n, t; cin >> n >> t;
    vector<ll> a(n);
    rep(i, n) {
        cin >> a[i];
    }

    ll h = n/2;
    vector<ll> r, l;
    for(ll bit = 0; bit < (1 << h); bit++) {
        ll sum = 0;
        for(int i = 0; i < h; i++) {
            if(bit & (1 << i)) {
                sum += a[i];
            }
        }
        r.push_back(sum);
    }

    if(n%2==0) {
       for(ll bit = 0; bit < (1 << h); bit++) {
        ll sum = 0;
        for(int i = 0; i < h; i++) {
            if(bit & (1 << i)) {
                sum += a[i+h];
            }
        }
        l.push_back(sum);
       }
    } else {
        h ++;
       for(ll bit = 0; bit < (1 << h); bit++) {
        ll sum = 0;
        for(int i = 0; i < h; i++) {
            if(bit & (1 << i)) {
                sum += a[i+h-1];
            }
        }
        l.push_back(sum);
       }
    }

    sort(all(r)); sort(all(l));

    ll ans = 0;
  

    rep(i, (int)r.size()) {
        ll num = t - r[i];
        auto L = lower_bound(all(l), num);
        if(*L + r[i] != t) {
          L--;
        }

        if(*L + r[i] <= t) {
            ans = max(ans, *L + r[i]);
        }
    }

    cout << ans << endl;
}

int main()
{
    solve1();
}

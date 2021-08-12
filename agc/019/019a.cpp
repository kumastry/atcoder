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


void solve1() {
    ll q, h, s, d; cin >> q >> h >> s >> d;
    ll n; cin >> n;
    
    ll qu = 4*q, hu = 2*h, su = s;
    double du = d /2.0;
    ll ans = 0;
    if(n > 2) {
        if(du < min({qu, hu, su})) {
            ll numd = n / 2;
            n -= 2*(n/2);
            ans += numd*d;

            if(n == 1) {
                ans += min({qu, hu, su});
            }

        } else {
            ans += min({n*qu, n*hu, n*su});
        }
    } else {
        ans += min({qu, hu, su});
    }

    cout << ans << endl;
}

int main()
{
    solve1();
}

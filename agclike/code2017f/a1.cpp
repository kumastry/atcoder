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

ll fact(ll n) {
    ll k = 1;
    for(int i = 1; i <= n; i++) {
        k *= i;
        k %= MOD;
    }

    return k;
}


void solve1() {
    ll a, b, m; cin >> a >> b >> m;
    vector<ll> aa(a), bb(b);

    ll mina = 1e18, minb = 1e18;

    rep(i, a) {
        cin >> aa[i];
        mina = min(aa[i], mina);
    }


    rep(i, b) {
        cin >> bb[i];
        minb = min(bb[i], minb);
    }

    vector<ll> x(m), y(m), c(m);
    rep(i, m) {
        cin >> x[i] >> y[i] >> c[i];
    }

    ll ans = 1e18;
    rep(i, m) {
        ll price = aa[x[i]-1] + bb[y[i]-1] - c[i];
        ans = min(ans, price); 
    }

    cout << min(ans, mina+minb) << endl;
}

int main()
{
    solve1();
}

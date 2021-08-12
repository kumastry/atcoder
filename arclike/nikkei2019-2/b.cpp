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

#define MOD 998244353
#define PI 3.1415926535897932
#define INF 1e9
#define rep(i, n) for (int i = 0; i < n; i++)
#define repe(i, j, n) for (int i = j; i < n; i++)
#define repi(i, n) for (int i = 0; i <= n; i++)
#define repie(i, j, n) for (int i = j; i <= n; i++)
#define all(x) x.begin(), x.end()
#define println() cout << endl
#define P pair<ll, ll>
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
    ll n; cin >> n;
    vector<ll> d(n);
    map<ll, ll> m;
    ll maxD = -1;
    rep(i, n) {
        cin >> d[i];
        maxD = max(maxD, d[i]);
        m[d[i]] ++;
    }

    if(m[0] != 1 || d[0] != 0) {
        cout << 0 << endl;
        return;
    }

    ll ans = 1;
    for(ll i = 1; i <= maxD; i++) {
        for(ll j = 0; j < m[i]; j++) {
            ans = (ans*m[i-1])%MOD;
            ans %= MOD;
            //cout << ans << endl;
        }
    }

    cout << ans%MOD << endl;
}


int main()
{
    solve1();
}

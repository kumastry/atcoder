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
    vector<ll> x(n), y(m);
    ll xma=-1e9, xmi = 1e9, yma=-1e9, ymi = 1e9;
    rep(i, n) {
        cin >> x[i];
        xma = max(x[i], xma);
        xmi = min(x[i], xmi);
    }

    rep(i, m) {
        cin >> y[i];
        yma = max(y[i], yma);
        ymi = min(y[i], ymi);
    }

    ll ans = abs(xma-xmi)*abs(yma-ymi)%MOD;
    ans = ans * (n-1)%MOD;
    ans = ans * (m-1)%MOD;

    cout << ans << endl;
}

int main()
{
    solve1();
}

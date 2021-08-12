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
    ll l, x, y, s, d; cin >> l >> x >> y >> s >> d;
    ll t = x + y;
    ll rt = y - x;

    if(rt <= 0) {
        rt = 0.1;
    }

    ll p, rp;
    if(s > d) {
        p = l - s + d;
        rp = l - p;
    } else {
        p = d - s;
        rp = l - p;
    }

    double ans = min(1.0*p / t, 1.0*rp / rt);
    cout << fixed << setprecision(10) << ans << endl; 
}

int main()
{
    solve1();
}

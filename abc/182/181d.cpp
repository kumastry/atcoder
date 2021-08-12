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
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i, n) {
        cin >> a[i];
    }

    vector<ll>sum(n+1);
    vector<ll> pl(n+1);
    vector<ll> sums(n+1);
    sum[0] = 0;
    pl[0] = 0;
    sums[0] = 0;
    for(int i = 0; i < n; i++) {
        sum[i+1] += sum[i] + a[i];

        pl[i+1] = max(pl[i], sum[i+1]);
    }

    for(int i = 0; i < n; i++) {
        sums[i+1] += sums[i] + sum[i+1];
    }


    ll ans = -1e9;

    for(int i = 0; i < n; i++) {
        ll val = sums[i] + pl[i];
        /*cout << sum[i] << " " << sums[i] << " " << pl[i] << endl; */
        ans = max(ans, val);
    }

    /*cout << sum[n] << " " << sums[n] << " " << pl[n] << endl; */
    ans = max(ans, sums[n]);

    cout << ans << endl;


}

int main()
{
    solve1();
}

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
    ll n, m; cin >> n >> m;
    ll k; cin >> k;
    vector<ll> a(n), b(m);
    rep(i, n) {
        cin >> a[i];
    }

    rep(i, m) {
        cin >> b[i];
    }

    ll ans1 = 0, ans2 = 0;
    vector<ll> sa(n+1), sb(m+1);
    sa[0] = 0;
    rep(i, n) {
        sa[i+1] = a[i] + sa[i];
    }

    sb[0] = 0;
    rep(i, m) {
        sb[i+1] = b[i] + sb[i];
    }

    ll ans = 0;
    for(ll i = 0; i < n+1; i++) {
        ll tmp = k-sa[i];
        ll cnt = i;

        if(tmp < 0) {
            cnt = 0;
        }

        cnt += upper_bound(all(sb), tmp)-sb.begin()-1;
        //cout << i << ":"<<cnt << endl;
        ans = max(cnt, ans);
    }

    cout << ans << endl;

}

int main()
{
    solve1();
}

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
#define INF 1e18
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

bool f(ll m, vector<ll> h, vector<ll> s) {
    ll n = (ll)h.size();
    vector<ll> t(n);
    for(int i = 0; i < n; i++) {
        ll diff = m - h[i];
        if(diff < 0) {
            return false;
        }
        t[i] = diff / s[i];
    }

    sort(all(t));
    rep(i, n) {
        if(t[i] < i) {
            return false;
        }
    }

    return true;
}

void solve1()
{
    ll R, C, k; cin >> R >> C >> k;
    ll n; cin >> n;
    vector<ll> r(n), c(n);
    rep(i, n) {
        cin >> r[i] >> c[i];
    }
}

int main()
{
    solve1();
}

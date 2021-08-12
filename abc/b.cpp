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
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    map<ll, ll> m;
    rep(i, n) {
        cin >> a[i];
    }

    ll ans = 0;
    ll rv = 0;

       for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < n; j++) {
            if(a[i] > a[j]) {
                m[a[i]] ++;
            }
        }
    }


    for(ll i = 0; i < n; i++) {
        for(ll j = i + 1; j < n; j++) {
            if(a[i] > a[j]) {
                rv ++;
            }
        }
    }

    ans += rv*k%MOD;
    for(auto itr = m.begin(); itr != m.end(); itr++) {
        ll num = k*(k-1)%MOD;
        num = num*modinv(2, MOD);
        num %= MOD;
        ans += itr->second*num%MOD;
        ans %= MOD;
    }

    cout << ans%MOD << endl;
}

int main()
{
    solve1();
}

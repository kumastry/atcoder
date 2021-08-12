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
    vector<bool> a(n+1, true);
    rep(i, m) {
        int in; cin >> in;
        a[in] = false;
    }

    vector<ll> dp(n+1);
    dp[0] = 1;
    dp[1] = a[1]?1:0;
    for(ll i = 2; i <= n; i++) {
        if(a[i]) {
          dp[i] = dp[i-1] + dp[i-2];
          dp[i] %= MOD;
        }
    }

 
    cout << dp[n]%MOD << endl;
}

int main()
{
    solve1();
}

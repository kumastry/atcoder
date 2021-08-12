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
#include <tuple>

using namespace std;

#define PI 3.1415926535897932
#define INF 1e18
#define MOD 1000000007
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



void solve1()
{
    ll n, m; cin >> n >> m;
    vector<ll> a(m);
    vector<bool> b(n, 0);
    rep(i, m) {
        cin >> a[i];
        b[a[i]] = true;
    }
    vector<ll> dp(n+1, INF);
    dp[0] = 1, dp[1] = 1;
    if(b[1]) {
        dp[1] = 0;
    }

    for(int i = 2; i <= n; i++) {
        if(b[i]) {
            dp[i] = 0;
            continue;
        }
        dp[i] = (dp[i-1] + dp[i-2])%MOD;
    }

    cout << dp[n]%MOD << endl;
}

int main()
{
    solve1();
}

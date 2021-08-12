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

long dp[2000][2000];

long nCr(int n, int r)
{
       if(n==r) return dp[n][r] = 1;
       if(r==0) return dp[n][r] = 1;
       if(r==1) return dp[n][r] = n%MOD;
       if(dp[n][r]) return dp[n][r]%MOD;
       return dp[n][r] = nCr(n-1,r)%MOD + nCr(n-1,r-1)%MOD;
}

ll H(ll n, ll r) {
    return nCr(n+r-1, r)%MOD;
}

void solve1() {
    int n; cin >> n;
    ll ans = 0;
    ll i = 1;
    while(1) {
        ll num = n-3*i;
        if(num < 0) {
            break;
        }

        ans = (ans+H(i, num))%MOD;
        //cout << i << ":" << H(i, num) << endl;
        ans %= MOD;
        i++;
    }

    cout << ans%MOD << endl;
}

int main()
{
    solve1();
}

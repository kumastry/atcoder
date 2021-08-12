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
    ll n, x; cin >> n >> x;
    vector<ll> a(n);
    vector<ll> sum(n-1);

    rep(i, n) {
        cin >> a[i];
    }

    rep(i, n-1) {
        sum[i] = a[i] + a[i+1];
    }

    ll ans = 0;
    rep(i, n-1) {
        if(i != n-2) {
            if(sum[i] > x) {
                ll diff = sum[i]-x;
                sum[i] -= diff;
                sum[i+1] -= min(a[i+1], diff);
                ans += diff;
            }
        } else {
            ans += max(sum[i]-x, 0LL);
            sum[i] -= sum[i]-x;
        }
    }


    /*rep(i, n-1) {
        cout << sum[i] << " ";
    }*/

   // cout << endl;

    cout << ans << endl;
}

int main()
{
    solve1();
}

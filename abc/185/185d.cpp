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
    vector<ll> a(m);

    for(ll i = 0; i < m; i++) {
        cin >> a[i];
    }

    if(m == 0) {
        cout << 1 << endl;
        return;
    }
   
    sort(all(a));

    ll k = 1e15;
    vector<ll> d;
    if(a[0]-1 > 0) {
      k = abs(a[0] - 1);
      d.push_back(a[0]-1);
    }

    for(ll i = 0; i < m-1; i++) {
        ll diff = abs(a[i]-a[i+1])-1;
        if(diff > 0) {
           k = min(k, diff);
           d.push_back(diff);
        }
    }

    if(abs(a[m-1]-n) > 0) {
       d.push_back(abs(a[m-1]-n));
       k = min(k, abs(a[m-1]-n));
    }

    if(k != 1e15) {
        ll ans =0;
        for(ll i = 0; i < (ll)d.size(); i++) {
            ans += ceil(1.0*d[i] / k);
            //cout << d[i] << endl;
        }

        cout << ans << endl;
    } else {
        cout << 0 << endl;
    }


}

int main()
{
    solve1();
}

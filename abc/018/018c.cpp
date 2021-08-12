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
    ll rr, cc, k; cin >> rr>> cc >> k;
    ll n; cin >> n;
    vector<ll> r(n), c(n);
    vector<ll> h(rr, 0), w(cc, 0);
    rep(i, n) {
        cin >> r[i] >> c[i];
        h[r[i]-1]++;
        w[c[i]-1]++;
    }

    ll ans = 0;
    sort(all(w));
    for(ll i = 0; i < rr; i++) {
        ll res = k - h[i+1];
        if(res < 0) continue;
        ll num = w.end() - lower_bound(all(w), res);
        if(res == num) {
            ans ++;
        }
    }

    cout << ans << endl;
    for(int i = 0; i < n; i++) {
        if(h[r[i]-1]+w[c[i]-1] == k+1) {
                ans ++;
        }
    }

    cout << ans << endl;


}

int main()
{
    solve1();
}

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
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cstdlib>
#include <queue>
#include <stack>
#include <bitset>

using namespace std;
typedef long long ll;
#define MOD 1000000007
#define PI 3.1415926535897932
#define INF 1e18
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repe(i, j, n) for (ll i = j; i < n; i++)
#define repi(i, n) for (ll i = 0; i <= n; i++)
#define repie(i, j, n) for (ll i = j; i <= n; i++)
#define all(x) x.begin(), x.end()
#define println() cout << endl
#define P pair<ll, ll>
#define fi first
#define se second
using Graph = vector<vector<ll>>;

void solve1() {
    ll n, D, H; cin >> n >> D >> H;
    vector<ll> d(n), h(n);
    ll mad = -1, mah = -1;
    rep(i, n) {
        cin >> d[i] >> h[i];
        if(h[i] > mah) {
            mah = h[i];
            mad = d[i];
        }
    }

    double ans = 0.0;
    for(int i = 0; i < n; i++) {
        bool f = true;
        for(int j = 0; j < n; j++) {
            ll hei = ((1.0*(h[i]-H)) / (d[i] - D))*(d[j]-D) + H;
            if(i != j) {
                if(hei < h[j]) {
                    f = false;
                }
            }
        }

        //cout << ((1.0*(h[i]-H)) / (d[i] - D))*(0-D) + H << endl;
        if(f) {
            ans = max(((1.0*(h[i]-H)) / (d[i] - D))*(0-D) + H, 0.0);
        }
    }
   
    cout << fixed << setprecision(15) << ans << endl;

}

int main()
{
    solve1();
}

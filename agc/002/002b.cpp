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

ll modinv(ll a, ll m)
{
    ll b = m, u = 1, v = 0;
    while (b)
    {
        ll t = a / b;
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
  
    int n, m; cin >> n >> m;
    vector<P> x(m);
    vector<int> box(n, 1);
    vector<bool> red(n, false);

    red[0] = true;

    rep(i, m) {
        cin >> x[i].fi >> x[i].se;
    }

    rep(i, m) {
        if(red[x[i].fi-1] == true && box[x[i].fi-1] == 1) {
            red[x[i].fi-1] = false;
            red[x[i].se-1] = true;
        } else if(red[x[i].fi-1] == true) {
            red[x[i].se-1] = true;
        }

        box[x[i].fi-1]--;
        box[x[i].se-1]++;
    }

    int ans = 0;
    rep(i, n) {
        if(red[i] == true && box[i] > 0) {
            ans ++;
        }
    }

    cout << ans << endl;

}

int main()
{
    solve1();
}

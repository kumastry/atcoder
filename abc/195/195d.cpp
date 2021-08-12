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
using Graph = vector<vector<ll>>;


bool bf(P a, P b) {
    if(a.se == b.se) {
        return a.fi < b.fi;
    } else {
        return a.se > b.se;
    }
}

void solve1() {
    ll n, m, q; cin >> n >> m >> q;
    vector<P> wv(n);
    rep(i, n) {
        cin >> wv[i].fi >> wv[i].se;
    }

    vector<ll> x(m);
    rep(i, m) {
        cin >> x[i];
    }

    sort(all(wv), bf);
    vector<ll> anss(q);
    rep(i, q) {
        ll ans = 0;
        ll l, r; cin >> l >> r;

        vector<ll> nw;
        rep(j, m) {
            if(j+1 >= l && j+1 <= r) {
                continue;
            }
            nw.push_back(x[j]);
        }

        sort(all(nw));
        vector<bool> fs(n, true);
        for(int j = 0; j < nw.size(); j++) {
            for(int k = 0; k < n; k++) {
                if(fs[k] && wv[k].fi <= nw[j]) {
                    ans += wv[k].se;
                    fs[k] = false;
                    break;
                }
            }
        }

        anss[i] = ans;
    }

    rep(i, q) {
        cout << anss[i] << endl;
    }
}

int main()
{
    solve1();
}

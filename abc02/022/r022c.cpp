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
    ll n, m; cin >> n >> m;
    vector<vector<ll>> dist(n, vector<ll>(n, INF));
    vector<vector<ll>> dis(n, vector<ll>(n, INF) );
    vector<ll> ni;
    rep(i, m) {
        ll a, b, c; cin >> a >> b >> c;
        if(a == 1) {
            ni.push_back(b);
            dis[a-1][b-1] = c;
            dis[b-1][a-1] = c;
            continue;
        }

        if(b == 1) {
            ni.push_back(a);
            dis[a-1][b-1] = c;
            dis[b-1][a-1] = c;
            continue;
        }

        a--; b--;
        dist[a][b] = c;
        dist[b][a] = c;
    }

    rep(i, n) {
        rep(j, n) {
            if(i == j) {
                dist[i][j] = 0;
            }
        }
    }

    ll ans = INF;
    for(ll k = 0; k < n; k++) {
        for(ll i = 0; i < n; i++) {
            for(ll j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }

    ll num = (ll)ni.size();
    if(num < 2) {
        cout << -1 << endl;
        return;
    }
    vector<bool> v(num, false);
    ll r = 2;
    fill(v.end() - r, v.end(), true);
    do {
        vector<ll> res;
        for(ll i = 0; i < num; i++){
            if(v[i]){
                res.push_back(ni[i]);
                //cout << ni[i] << " ";
            }
        }
        //cout << endl;
        ll aa = res[0]-1, bb = res[1]-1;
        ans = min(ans, dist[aa][bb]+dis[0][aa]+dis[0][bb]);
        //cout << "## " << dist[aa][bb]+dist[0][aa]+dist[0][bb] << endl;

    } while(next_permutation(v.begin(), v.end()));

    if(ans == INF) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

}

int main()
{
    solve1();
}

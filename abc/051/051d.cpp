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
/* warshall_floyd(dist,prev)
    入力：初期化した dist, prev
    計算量：O(|V|^3)
    副作用：dis[i][j]にiからjへの最短路のコストを格納、prev[i][j]にiからjへの最短路でのjの1つ前の点を格納
*/
void warshall_floyd(vector<vector<long long>> &dist, vector<vector<long long>> &prev) {
    int V = dist.size();
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    prev[i][j] = prev[k][j];
                }
            }
        }
    }
}

/* get_path(prev, s, t)
    入力：warshall_floyd で得た prev, スタート s, ゴール t
    出力：s から t への最短路のパス
*/
vector<int> get_path(const vector<vector<long long>> &prev, int s, int t) {
    vector<int> path;
    for (int cur = t; cur != s; cur = prev[s][cur]) {
        path.push_back(cur);
    }
    path.push_back(s);
    reverse(path.begin(), path.end());
    return path;
}

int n, m; 
void solve1() {
    cin >> n >> m;
    vector<vector<ll>> dist(n, vector<ll>(n, INF)), prev(n, vector<ll>(n));
    rep(i, n) {
        rep(j, n) {
            if(i == j) {
                dist[i][j] = 0;
            }
        }
    }
    vector<ll> aa(m), bb(m);
    rep(i, m) {
        int a, b, c; cin >> a >> b >> c;
        aa[i] = a; bb[i] = b;
        dist[a-1][b-1] = c;
        dist[b-1][a-1] = c;

    }

    warshall_floyd(dist, prev);
    set<P> s;
    rep(i, n) {
        rep(j, n) {
            if(i != j) {
                vector<int> path = get_path(prev, i, j);

                for(int i = 0; i < (int)path.size()-1; i++) {
                    int mi = min(path[i], path[i+1]);
                    int mx = max(path[i], path[i+1]);
                    s.insert(P(mi, mx));
                }
            }
        }
    }

    ll ans = 0;
    rep(i, m) {
        bool f = false;
        for(auto itr = s.begin(); itr!=s.end(); itr++) {
            if((itr->fi == aa[i]-1 && itr->se == bb[i]-1) || (itr->se == aa[i]-1 && itr->fi == bb[i]-1)) {
                f = true;
            }
        }

        if(!f) {
            ans ++;
        }
    }
}

int main()
{
    solve1();
}

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
#define P pair<int, int>
#define fi first
#define se second

typedef long long ll;
struct edge {
    ll to; ll cost;

    edge(ll to, ll cost) {
        this->to = to;
        this->cost = cost;
    }
};
using Graph = vector<vector<edge>>;


ll h, w, t, num, s, e;
void dijkstra(const Graph &G, int s, vector<long long> &dis) {
    int N = G.size();
    dis.resize(N, INF);
    priority_queue<P, vector<P>, greater<P>> pq;  // 「仮の最短距離, 頂点」が小さい順に並ぶ
    dis[s] = 0;
    pq.emplace(dis[s], s);
    while (!pq.empty()) {
        P p = pq.top();
        pq.pop();
        int v = p.second;
        if (dis[v] < p.first) {  // 最短距離で無ければ無視
            continue;
        }
        for (auto &e : G[v]) {
            if (dis[e.to] > dis[v] + e.cost) {  // 最短距離候補なら priority_queue に追加
                dis[e.to] = dis[v] + e.cost;
                pq.emplace(dis[e.to], e.to);
            }
        }
    }
}

ll f(ll mid, Graph g,  vector<vector<pair<char, int> >> d) {
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            ll co1, co2;
            if(j != w-1) {
                if(d[i][j+1].fi == '#') {
                    co1 = mid;
                } else {
                    co1 = 1;
                }

                g[d[i][j].se].push_back(edge(d[i][j+1].se, co1));

                if(d[i][j].fi == '#') {
                    co1 = mid;
                } else {
                    co1 = 1;
                }

                g[d[i][j+1].se].push_back(edge(d[i][j].se, co1));
            }


            if(i != h-1) {
                if(d[i+1][j].fi == '#') {
                    co2 = mid;
                } else {
                    co2 = 1;
                }
                g[d[i][j].se].push_back(edge(d[i+1][j].se, co2));

                if(d[i][j].fi == '#') {
                    co2 = mid;
                } else {
                    co2 = 1;
                }

                g[d[i+1][j].se].push_back(edge(d[i][j].se, co2));
            }

        }
    }

    vector<ll> dis;
    dijkstra(g, s, dis);
    if(dis[e] <= t) {
        return true;
    }

    return false;

}

void solve1() {
    cin >> h >> w >> t;
    vector<vector<pair<char, int> >> d(h, vector<pair<char, int>>(w));
    Graph g(h*w);
    
    rep(i, h) {
        rep(j, w) {
            cin >> d[i][j].fi;
            if(d[i][j].fi == 'S') {
                s = num;
            } else if(d[i][j].fi == 'G') {
                e = num;
            }

            d[i][j].se = num;
            num++;
        }
    }

    ll r = INF, l = 0;
    while(r - l > 1) {
        ll mid = (r+l) / 2;
        if(f(mid, g, d)) {
            r = mid;
        } else {
            l = mid;
        }
      
      //cout << r << " " << l  << endl;
    }
  
  cout << l << endl;
}

int main()
{
    solve1();
}

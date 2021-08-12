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
#define INF 1e17
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
    ll to;
    ll cost;

    edge(ll to, ll cost) {
        this->to = to;
        this->cost = cost;
    }
};
using Graph = vector<vector<edge>>;
vector<ll> dis;
vector<ll> dis2;
void dijkstra(Graph G, int s, int n) {
    int N = n;
    dis.assign(N, INF);
    dis2.assign(N, INF);
    priority_queue<P, vector<P>, greater<P>> pq;  // 「仮の最短距離, 頂点」が小さい順に並ぶ
    dis[s] = 0;
    pq.push(P(dis[s], s));

    while (!pq.empty()) {
        P p = pq.top(); pq.pop();
        ll v = p.second; ll d = p.first;
        if (dis2[v] < d) {  // 最短距離で無ければ無視
            continue;
        }
        for(int i = 0;i < (int)G[v].size(); i++) {

            edge e = G[v][i];
            ll d2 = d+e.cost;
            if(dis[e.to] > d2) {
                swap(dis[e.to], d2);
                pq.push(P(dis[e.to], e.to));
            }
            

            if(dis2[e.to] > d2 && dis[e.to] < d2) {
                dis2[e.to] = d2;
                pq.push(P(dis2[e.to], e.to));
            }             
        }
    }
}

void solve1() {
    ll n, m; cin >> n >> m;
    Graph g(n);

    rep(i, m) {
        ll a, b, c; cin >> a >> b >> c;
        g[a-1].push_back(edge(b-1, c));
    }


    rep(i, n) {
        ll ans = INF;

        dijkstra(g, i, n);
        ans = dis2[i];
        if(ans == INF) {
            cout << -1 << endl;
        } else {
            cout << ans << endl;
        }
    }
    

}

int main()
{
    solve1();
}

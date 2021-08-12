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
typedef long long ll;
struct edge {
    ll to;
    ll cost;

    edge(ll to, ll cost) {
        this->to = to;
        this->cost = cost;
    }
};

#define MOD 1000000007
#define PI 3.1415926535897932
#define INF 1e19
#define rep(i, n) for (int i = 0; i < n; i++)
#define repe(i, j, n) for (int i = j; i < n; i++)
#define repi(i, n) for (int i = 0; i <= n; i++)
#define repie(i, j, n) for (int i = j; i <= n; i++)
#define all(x) x.begin(), x.end()
#define println() cout << endl
#define P pair<ll, ll>
#define fi first
#define se second
using Graph = vector<vector<edge>>;



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

ll n, m, s, t; 
ll dist[2000];

void dijstra(ll s, Graph g) {
    priority_queue<P, vector<P>, greater<P> > que;
    fill(dist, dist+n, INF);
    dist[s] = 0;
    que.push(P(0, s));

    while(que.size()) {
        P p = que.top(); que.pop();
        ll v = p.se;
        if(dist[v] < p.fi) continue;
        for(ll i = 0; i < (int)g[v].size(); i++) {
            edge e = g[v][i];
            if(dist[e.to] > dist[v] + e.cost) {
                dist[e.to] = dist[v] + e.cost;
                que.push(P(dist[e.to], e.to));
            }
        }
    }
}

void solve1() {
    cin >> n >> m >> s >> t;
    Graph g(n);
    s--; t--;
    for(ll i = 0; i < m; i++) {
        ll a, b; cin >> a >> b;
        ll d; cin >> d;
        a--; b--;
        g[a].push_back(edge(b, d));
        g[b].push_back(edge(a, d));
    }

    ll ans = -1;
    for(ll i = 0; i < n; i++) {
        if(i != s && i != t) {
            dijstra(i, g);
            //cout << "$$$" <<  i << " " << s << " " << t << endl;
            /*rep(j, n) {
                cout << dist[j] << endl;
            }*/
            ll r = dist[s];
            ll l = dist[t];
            //cout << l << " " << r << endl;
            if(r == l) {
                ans = i+1;
                break;
            }
        }
    }

    cout << ans << endl;
    
}

int main()
{
    solve1();
}

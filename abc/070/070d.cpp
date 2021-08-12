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

struct edge {
    ll to;
    ll cost;

    edge(ll t, ll c):to(t), cost(c) {}
};

ll N;
vector<ll> d;

void dijkstra(ll s, vector<vector<edge>> &G) {
    priority_queue<P, vector<P>, greater<P> > que;

    d[s] = 0;
    que.push(P(0, s));

    while(!que.empty()) {
        P p = que.top(); que.pop();
        ll v = p.second;
        if(d[v] < p.first) continue;
        for(int i = 0; i < (int)G[v].size(); i++) {
            edge e = G[v][i];
            if(d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

void solve1() {
    cin >> N;
    vector<vector<edge>> G(N);
    d.assign(N, 1e18);
   
    for(int i = 0; i < N-1; i++) {
        ll a, b, c; cin >> a >> b >> c;
        a--; b--;
        G[a].push_back(edge(b, c));
        G[b].push_back(edge(a, c));
    }

    ll q, k; cin >> q >> k;
    k --;
    vector<int> x(q), y(q);
    dijkstra(k, G);
    rep(i, q) {
        cin >> x[i] >> y[i];
    }

    rep(i, q) {
        cout << d[x[i]-1] + d[y[i]-1] << endl;
    }

}

int main()
{
    solve1();
}

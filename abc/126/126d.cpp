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
#include <math.h>    // for fabs()
#include <stdio.h>   // for printf()
typedef long long ll;
struct edge {
    ll to;
    ll cost;

    edge(ll to, ll cost) {
        this->to = to;
        this->cost =cost;
    }
};

using namespace std;

#define MOD 1000000007
#define PI 3.1415926535897932
#define INF 1e17
#define max 1e3                //最大繰り返し回数
#define eps 1.0e-6              //収束条件
#define rep(i, n) for (int i = 0; i < n; i++)
#define repe(i, j, n) for (int i = j; i < n; i++)
#define repi(i, n) for (int i = 0; i <= n; i++)
#define repie(i, j, n) for (int i = j; i <= n; i++)
#define all(x) x.begin(), x.end()
#define println() cout << endl
#define P pair<int, int>
#define fi first
#define se second

using Graph = vector<vector<edge>>;

vector<ll> dist;
void bfs(Graph g, ll p, ll v) {
    queue<ll> que;
    que.push(0);
    while(que.size()) {
        ll f = que.front(); que.pop();
        for(int i = 0;i < (int)g[f].size(); i++) {
            if(dist[g[f][i].to]==INF) {
                dist[g[f][i].to] = dist[f] + g[f][i].cost;
                que.push(g[f][i].to);
            }
        }
    }
}

void solve1() {
    ll n; cin >> n;
    Graph g(n);
    rep(i, n-1) {
        ll a, b, c; cin >> a >> b >> c;
        a--; b--;
        if(c%2) {
            c = 1;
        } else {
            c = 0;
        }

        g[a].push_back(edge(b, c));
        g[b].push_back(edge(a, c));
    }

    dist.assign(n, INF);
    dist[0] = 0;
    bfs(g, -1, 0);
    rep(i, n) {
        if(dist[i]%2==0) {
            cout << 0 << endl;
        } else {
            cout << 1 << endl;
        }
    }
}

int main()
{
    solve1();
}



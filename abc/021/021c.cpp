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

using Graph = vector<vector<ll>>;


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

ll n, a, b, m;
vector<ll> dist;
void bfs(Graph g, Graph &dag) {
    queue<ll> que;
    que.push(a);
    dist.assign(n, -1);
    dist[a] = 0;
    while(que.size()) {
        ll f = que.front(); que.pop();
        for(ll i = 0; i < g[f].size(); i++) {
            if(dist[g[f][i]] == -1) {
                dist[g[f][i]] = dist[f] + 1;
                que.push(g[f][i]);
            }
        }
    }
  
  que.push(a);
  set<ll> st; st.insert(a);
  while(que.size()) {
    ll f = que.front(); que.pop(); st.erase(f);
    for(int i = 0; i < g[f].size(); i++) {
      if(dist[g[f][i]] - dist[f] == 1) {
        dag[f].push_back(g[f][i]);
        if(st.find(g[f][i]) == st.end()) {
        	que.push(g[f][i]);
            st.insert(g[f][i]);
        }
      }
    }
  }
}

vector<ll> dp;
ll rec(ll s, Graph dag) {
    if(dp[s] != -1) return dp[s];
    ll ret = 0;

    for(ll i = 0; i < dag[s].size(); i++) {
        ret = (ret+rec(dag[s][i] ,dag))%MOD;
    }

    return dp[s] = ret;
}

void solve1() {
   cin >> n >> a >> b >> m;
   a--; b--;
   Graph g(n);
   Graph dag(n);
   rep(i, m) {
       ll x, y; cin >> x >> y;
       x--; y--;
       g[x].push_back(y);
       g[y].push_back(x);
    }

    bfs(g, dag);
   /* for(int i = 0; i < n; i++) {
        cout << i+1 << " : ";
        for(int j = 0; j < dag[i].size(); j++) {
            cout << dag[i][j] + 1 << " ";
        }

        cout << endl;
    } */

    dp.assign(n, -1);
    dp[b] = 1;
    cout << rec(a, dag) << endl;
}

int main()
{
    solve1();
}

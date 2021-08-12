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
#define P pair<ll, ll>
#define fi first
#define se second
typedef long long ll;
struct egde {
    ll to;
    ll wei;

    egde(ll to, ll wei) {
        this->to = to;
        this->wei = wei;
    }
};
using Graph = vector<vector<egde>>;

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

ll dp[2000][2000];
ll nCr(ll n, ll r)
{
       if(n==r) return dp[n][r] = 1;
       if(r==0) return dp[n][r] = 1;
       if(r==1) return dp[n][r] = n%MOD;
       if(dp[n][r]) return dp[n][r]%MOD;
       return dp[n][r] = nCr(n-1,r)%MOD + nCr(n-1,r-1)%MOD;
}


vector<bool> seen;
P bfs(Graph g, int v) {
    if(seen[v]) {
        return P(-1, 0);
    }
    seen[v] = true;
    queue<ll> que; que.push(v);
    ll res = v;
    ll num= 1;
    while(que.size()) {
        ll f = que.front(); que.pop();
        for(int i = 0; i<(int)g[f].size(); i++) {
            if(!seen[g[f][i].to]) {
                seen[g[f][i].to] = true;
                que.push(g[f][i].to);
                res = min(res, g[f][i].to);
                num++;
            }
        }
    }

    return P(res, num);
}

vector<ll> d;
ll n, m;

void dijkstra(ll s, Graph &G, ll n) {
    priority_queue<P, vector<P>, greater<P> > que;
    d.assign(n, 1e18);
    d[s] = 0;
    que.push(P(0, s));
 
    while(!que.empty()) {
        P p = que.top(); que.pop();
        ll v = p.second;
        if(d[v] < p.first) continue;
        for(int i = 0; i < (int)G[v].size(); i++) {
            egde e = G[v][i];
            if(d[e.to] > d[v] + e.wei) {
                d[e.to] = d[v] + e.wei;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

void solve1() {
     cin >> n >> m;
     vector<ll> a(n);
     rep(i, n) {
         cin >> a[i];
     }

     bool f = false;
     vector<ll> x(m), y(m);
     rep(i, m) {
         cin >> x[i] >> y[i];
         if(a[x[i]-1] <= a[y[i]-1]){
             f = true;
         }
     }
a
     if(f) {a
         Graph g(n);
         rep(i, m) {
             g[x[i]-1].push_back(egde(y[i]-1, min(0LL, a[x[i]-1]-a[y[i]-1])));
         }

         vector<P> cat;
         seen.assign(n, false);
         for(int i = 0; i < n; i++) {
            P minv = bfs(g, i);
            if(minv.fi == -1) continue;
            cat.push_back(minv);
        }

        ll ans = -1;
        rep(i, (int)cat.size()) {
            dijkstra(cat[i].fi, g, cat[i].se);
            rep(j, cat[i].se) {
               // cout << d[j] << endl;
                ans = max(ans, -d[j]);
            }
        }

        cout << ans << endl;
        //cout << 1111 << endl;

     } else {
         Graph g(n);
         rep(i, m) {
             g[x[i]-1].push_back(egde(y[i]-1, a[y[i]-1]-a[x[i]-1]));
         }
         vector<P> cat;
         seen.assign(n, false);
         for(int i = 0; i < n; i++) {
            P minv = bfs(g, i);
            if(minv.fi == -1) continue;
            cat.push_back(minv);
        }

        ll ans = -1e18;

        rep(i, (int)cat.size()) {
            ll maxw = -1e18;
            for(int j = 0; j < g[cat[i].fi].size(); j++) {
                maxw = max(maxw, g[cat[i].fi][j].wei);
            } 
            ans = max(ans, maxw);
        }

        cout << ans << endl;
     }


}

int main()
{
    solve1();
}

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
typedef long long ll;
#define MOD 1000000007
#define PI 3.1415926535897932
#define INF 1e18
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repe(i, j, n) for (ll i = j; i < n; i++)
#define repi(i, n) for (ll i = 0; i <= n; i++)
#define repie(i, j, n) for (ll i = j; i <= n; i++)
#define all(x) x.begin(), x.end()
#define println() cout << endl
#define P pair<ll, ll>
#define fi first
#define se second
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

ll dp[2000][2000];
ll nCr(ll n, ll r)
{
       if(n==r) return dp[n][r] = 1;
       if(r==0) return dp[n][r] = 1;
       if(r==1) return dp[n][r] = n%MOD;
       if(dp[n][r]) return dp[n][r]%MOD;
       return dp[n][r] = nCr(n-1,r)%MOD + nCr(n-1,r-1)%MOD;
}
 
ll H(ll n, ll r) {
    return nCr(n+r-1, r)%MOD;
}


struct UnionFind {
	//自身が親であれば、その集合に属する頂点数に-1を掛けたもの
	//そうでなければ親のid
	vector<ll> r;
	UnionFind(ll N) {
		r = vector<ll>(N, -1);
	}
	ll root(ll x) {
		if (r[x] < 0) return x;
		return r[x] = root(r[x]);
	}
	bool unite(ll x, ll y) {
		x = root(x);
		y = root(y);
		if (x == y) return false;
		if (r[x] > r[y]) swap(x, y);
		r[x] += r[y];
		r[y] = x;
		return true;
	}
	ll size(ll x) {
		return -r[root(x)];
	}
 
    bool same(ll x, ll y) { // 2つのデータx, yが属する木が同じならtrueを返す
        ll rx = root(x);
        ll ry = root(y);
        return rx == ry;
    }
};

ll n;
Graph g;
vector<ll> c;
set<ll> cl;
vector<bool> seen;
vector<ll> ans;

void bfs() {
    int s = 0;
    queue<ll> que; que.push(s);
   
    ans.push_back(s+1);
    seen[s] = true;
    while(que.size()) {
        ll f = que.front(); que.pop();
        cl.insert(c[f]);
        for(int i = 0; i < g[f].size(); i++) {
            
            if(!seen[g[f][i]]) {
                //cout << g[f][i]+1 << " ";
                seen[g[f][i]] = true;
                if(cl.find(c[g[f][i]]) == cl.end()) {
                    ans.push_back(g[f][i]+1);
                }
                que.push(g[f][i]);
            }
        }  
    }
}


void solve1() {
    cin >> n;
    c.resize(n);
    rep(i, n) {
        cin >> c[i];
    }
    seen.resize(n, false);
    g.resize(n);

    rep(i, n-1) {
        ll a, b; cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    bfs();
    sort(all(ans));
    set<ll> an;
    rep(i, ans.size()) {
        an.insert(ans[i]);
    }

    for(auto itr = an.begin(); itr!=an.end(); itr++) {
        cout << *itr << endl;
    }
}

int main()
{
    solve1();
}

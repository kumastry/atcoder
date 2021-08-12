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

ll n, m; 


bool hasloop(Graph g, ll r) {
    vector<ll> seen(n, false);
    queue<ll> que;
    que.push(r);
    seen[r] = true;
    while(que.size()) {
        ll f = que.front(); que.pop();
        for(ll i = 0; i < (ll)g[f].size(); i++) {
            if(g[f][i] == f) continue;
            if(seen[g[f][i]]) {
              return true;
            }
            seen[g[f][i]] = true;
            que.push(g[f][i]);
        }
    }

    return false;
}

void solve1() {
    cin >> n >> m;
    Graph g(n);
    UnionFind uf(n);
    rep(i, m) {
        ll a, b; cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
        uf.unite(a, b);
    }

  
    for(ll i = 0; i < n; i++) {
        if(g[i].size() >= 3) {
            cout << 0 << endl;
            return;
        }
    }

   
    vector<ll> roots;
    set<ll> st;
    for(ll i = 0; i < n; i++) {
        st.insert(uf.root(i));
    }

    for(auto itr = st.begin(); itr != st.end(); itr++) {
        roots.push_back(*itr);
    }
  
    ll ans = 1;
    //out << "#### " << roots.size() << endl; 
    for(ll i = 0; i < (ll)roots.size(); i++) {
        ll num = roots[i];
        //cout << num + 1 << ":" << uf.size(num) << endl;
        if(uf.size(num) == 1) {
            ans *= 3;
            continue;
        }

        if(hasloop(g, num)) {
            ans *= 3*pow(2, uf.size(num)-2);
            //cout << "33 " <<  roots[i] << endl;
        } else {
            ans *= 3*pow(2, uf.size(num)-1);
        }

        //cout << ans << endl;
    }

    cout << ans << endl;
}

int main()
{
    solve1();
}

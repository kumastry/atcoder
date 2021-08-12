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

#define fi first
#define se second
typedef long long ll;
struct edge {
    ll from;
    ll to;
    ll cost;

    edge(ll from ,ll to, ll cost) {
        this->from = from;
        this->to = to;
        this->cost = cost;
    }
};

#define P pair<ll, ll>


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

bool f1(pair<P, ll> a, pair<P, ll> b) {
    if(a.fi.fi == b.fi.fi) {
        return a.fi.se < b.fi.se;
    } else {
        return a.fi.fi < b.fi.fi;
    }
}

bool f2(pair<P, ll> a, pair<P, ll> b) {
    if(a.fi.se == b.fi.se) {
        return a.fi.fi < b.fi.fi;
    } else {
        return a.fi.se < b.fi.se;
    }
}


bool f3(edge a, edge b) {
    return a.cost < b.cost;
}

void solve1() {
    ll n; cin >> n;
    vector<pair<P, ll>> xy(n);

    rep(i, n) {
        cin >> xy[i].fi.fi >> xy[i].fi.se;
        xy[i].se = i;
    }
    vector<pair<P, ll>> x(xy), y(xy);

    sort(all(x), f1);
    sort(all(y), f2);

    vector<edge> e;
    for(int i = 0; i < n-1; i++) {
        e.push_back(edge(x[i].se, x[i+1].se, abs(x[i+1].fi.fi-x[i].fi.fi) ));
    }

    for(int i = 0; i < n-1; i++) {
        e.push_back(edge(y[i].se, y[i+1].se, abs(y[i+1].fi.se-y[i].fi.se)));
    }

    sort(all(e), f3);
    UnionFind uf(n);
    ll ans = 0;
    for(int i = 0; i < ll(e.size()); i++) {
        if(!uf.same(e[i].from, e[i].to)) {
            uf.unite(e[i].from, e[i].to);
            ans += e[i].cost;
        }
    }

    cout << ans << endl;

}

int main()
{
    solve1();
}

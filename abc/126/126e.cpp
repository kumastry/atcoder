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

void solve1() {
    ll n, m; cin >> n >> m;
    vector<ll> x(n), y(n), z(n);
    UnionFind uf(n);
    rep(i, m) {
        int xx, yy, zz;
        cin >> xx >> yy >> zz;
        uf.unite(xx-1, yy-1);
    }

    set<ll> s;
    for(int i = 0; i < n; i++) {
        s.insert(uf.root(i));
    }

    cout << s.size() << endl;
}

int main()
{
    solve1();
}



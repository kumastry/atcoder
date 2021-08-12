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

using namespace std;

#define MOD 1000000007
#define PI 3.1415926535897932
#define INF 1e9
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
typedef long long ll;
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


void solve1() {
    ll n, m; cin >> n >> m;
    vector<ll> a(m), b(m);

    rep(i,m) {
        cin >> a[i] >> b[i];
    }

    UnionFind uf(1e6);
    ll ans = n*(n-1) / 2;
    vector<ll> anss(m, -1);
    for(int i = m-1; i >= 0; i--) {
        ll aa = a[i]-1;
        ll bb = b[i]-1;

        //cout << ans << endl;
        anss[i] = ans;
        if(ans != 0) {
            if(!uf.same(aa, bb)) {
                ans += uf.size(aa)*(uf.size(aa)-1) / 2;
                ans += uf.size(bb)*(uf.size(bb)-1) / 2;
                uf.unite(aa, bb);
                ans -= uf.size(aa)*(uf.size(aa)-1) / 2;
            } else {
                uf.unite(aa, bb);
            }
        }
    }
    
    for(int i = 0; i < m; i++) {
        cout << anss[i] << endl;
    }
}

int main()
{
    solve1();
}



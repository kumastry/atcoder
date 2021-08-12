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

struct UnionFind {
	//自身が親であれば、その集合に属する頂点数に-1を掛けたもの
	//そうでなければ親のid
	vector<int> r;
	UnionFind(int N) {
		r = vector<int>(N, -1);
	}
	int root(int x) {
		if (r[x] < 0) return x;
		return r[x] = root(r[x]);
	}
	bool unite(int x, int y) {
		x = root(x);
		y = root(y);
		if (x == y) return false;
		if (r[x] > r[y]) swap(x, y);
		r[x] += r[y];
		r[y] = x;
		return true;
	}
	int size(int x) {
		return -r[root(x)];
	}

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

using Graph = vector<vector<int>>;

void solve1() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(m), b(m);
    vector<int> c(k), d(k);
    UnionFind uf(n);
    Graph g(n);

    rep(i, m) {
        cin >> a[i] >> b[i];
        uf.unite(a[i]-1, b[i]-1);
        g[a[i]-1].push_back(b[i]-1);
        g[b[i]-1].push_back(a[i]-1);
    }

    rep(i, k) {
        cin >> c[i] >> d[i];
    }

    vector<int> ans(n, 0);

    rep(i, n) {
        ans[i] = uf.size(i) - 1 - (int)g[i].size();
    }

    rep(i, k) {
        if(uf.same(c[i]-1, d[i]-1)) {
            ans[c[i]-1]--;
            ans[d[i]-1]--;
        }
    }

    rep(i, n) {
        if(i != n-1) {
            cout << ans[i] << " ";
        } else {
            cout << ans[i] << endl;
        }
    }
}

int main()
{
    solve1();
}

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

template <typename T>
pair<T, int> dfs(const Graph &G, int u, int par) {  // 最遠点間距離と最遠点を求める
    pair<T, int> ret = make_pair((T)0, u);
    for (auto e : G[u]) {
        if (e == par) continue;
        auto next = dfs<T>(G, e, u);
        next.first += 1;
        ret = max(ret, next);
    }
    return ret;
}

template <typename T>
T tree_diamiter(const Graph &G) {
    pair<T, int> p = dfs<T>(G, 0, -1);
    cout << p.second+1 << " ";
    pair<T, int> q = dfs<T>(G, p.second, -1);
    cout << q.second+1 << endl;
    return q.first;
}

void solve1() {
    ll n; cin >> n;
    Graph g(n);
    rep(i, n-1) {
        ll a, b; cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    tree_diamiter<int>(g);
}

int main()
{
    solve1();
}

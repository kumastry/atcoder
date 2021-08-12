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
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

    UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) par[i] = i;
    }

    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

using G = vector<vector<int>>;
 
void solve1()
{
    int n, m; cin >> n >> m;
    UnionFind uf(10000000);
    vector<ll> a(n), b(n);
    rep(i, n) {
        cin >> a[i];
    }

    rep(i,n) {
        cin >> b[i];
    }

    for(int i = 0; i < m; i++) {
        int aa, bb; cin >> aa >> bb;
        uf.unite(aa, bb);
    }

    bool f = true;
    map<ll, ll> am,bm;
    rep(i, n) {
        am[uf.root(i+1)] += a[i];
        bm[uf.root(i+1)] += b[i];
    }

    vector<ll> suma;
    vector<ll> sumb;
    for(auto itr = am.begin(); itr != am.end(); itr++) {
        suma.push_back(itr->second);
    }

    for(auto itr = bm.begin(); itr != bm.end(); itr++) {
        sumb.push_back(itr->second);
    }

    rep(i, (int)suma.size()) {
        if(suma[i] != sumb[i]) {
            f = false;
        }
    }

    if(f) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

int main()
{
    solve1();
}

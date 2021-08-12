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

#define MOD 998244353
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



void solve1() {

}

int main()
{
    solve1();
}

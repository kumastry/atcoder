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
using Graph = vector<vector<int>>;
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

int prime[10000000];
bool is_prime[100000000 + 1];
int sieve(int n ) {
    int pcnt = 0;
    for(int i = 0; i <= n; i++) {
        is_prime[i] = true;
    }
 
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i <= n; i++) {
        if(is_prime[i]) {
            prime[pcnt++] = i;
            for(int j = 2*j; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
 
    return pcnt;
}

ll gcd(ll a, ll b) {
    if(a%b) {
        return gcd(b, a%b);
    } else {
        return b;
    }
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

void solve1() {
    ll n; cin >> n;

    if(n == 2) {
        cout << 3 << endl;
    } else {
        ll ans = 2;
        for(ll i = 3; i <= n ; i++) {
            ans = lcm(ans, i);
        }

        cout << ans + 1 << endl;
    }

}

int main()
{
    solve1();
}

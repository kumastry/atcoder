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
#define P pair<ll, ll>
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

int prime[10000000];
bool is_prime[100000000 + 1];
 
int sieve(int n) {
    int pcnt = 0;
    for(int i = 0; i <= n; i++) {
        is_prime[i] = true;
    }
 
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i <= n; i++) {
        if(is_prime[i]) {
            prime[pcnt++] = i;
            for(int j = 2*i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
 
    return pcnt;
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

bool f(P a, P b) {
    if(a.fi == b.fi) {
        return a.se < b.se;
    } else {
        return a.fi < b.fi;
    }
}

void solve1() {
    ll n, C; cin >> n >> C;
    vector<ll> a(n), b(n), c(n);
    vector<P> ac(n), bc(n);
    set<ll> s;
    rep(i, n) {
        cin >> a[i] >> b[i] >> c[i];
        ac[i] = P(a[i], c[i]);
        bc[i] = P(b[i], c[i]);
        s.insert(a[i]); s.insert(b[i]+1);
    }

    ll temp = 0;
    for(int i = 0; i < n; i++) {
        temp += abs(a[i]-b[i])*c[i];
        cout << temp << endl;
    }

    ll ans = 0;
    sort(all(ac), f);
    sort(all(bc), f);
    vector<ll> suma(n+1), sumb(n+1);
    suma[0] = 0; sumb[0] = 0;
    rep(i, n) {
        suma[i+1] = suma[i] + ac[i].se;
        sumb[i+1] = sumb[i]+ bc[i].se;
    }

    rep(i, n) {
        a[i] = ac[i].fi;
        b[i] = bc[i].fi+1;
    }

    rep(i, n) {
        cout << a[i] << " " << b[i] << endl;
    }


    ll val = 0, val1 = 0, val2 = 0;
    for(auto itr = s.begin(); itr != s.end(); itr++) {
        ll num = *itr;
        ll numn = next(itr) == s.end()?*itr:*next(itr);
        ll diff = abs(num-numn);
        val1 += (ll)(upper_bound(all(a), *itr) - lower_bound(all(a), *itr));
        val2 += (ll)(upper_bound(all(b), *itr) - lower_bound(all(b), *itr));

        val += abs(val1-val2);
        ll vala = suma[upper_bound(all(a), *itr) - a.begin()]-suma[lower_bound(all(a), *itr)-a.begin()];
        ll valb = sumb[upper_bound(all(b), *itr)-b.begin()]-sumb[lower_bound(all(b), *itr)-b.begin()];

        ll V = abs(val1*vala - val2*valb);

        ans += diff*min(V, C);
        /*cout << "a" << *itr << " " <<  upper_bound(all(a), *itr) - lower_bound(all(a), *itr)  << " " << vala << endl;
        cout << "b" << *itr << " " <<  upper_bound(all(b), *itr) - lower_bound(all(b), *itr)  << " " << valb << endl; */
        cout << *itr << ":" << val1 << " " << val2 << endl;
        cout << ans << endl;

    }

  

    cout << ans << endl;

}

int main()
{
    solve1();
}

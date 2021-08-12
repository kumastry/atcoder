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

set <ll> divs(ll n, ll m) {
    set<ll> res;
    set<ll> ret;
    for(ll i = 1; i * i <= n; i++) {
        if(n%i == 0) {
            res.insert(i);
            res.insert(n/i);
        }
    }

    for(int i = 1; i * i <= m; i++) {
        if(m%i == 0 && res.find(i) != res.end()) {
            ret.insert(i);

            if(res.find(m/i) != res.end()) {
                ret.insert(m/i);
            }
        }
    }

    return ret;
}

ll gcd(ll a, ll b) {
    if(a%b) {
        return gcd(b, a%b);
    } else {
        return b;
    }
}

void solve1() {
    ll n, m; cin >> n >> m;
    vector<ll> x(n), y(n), z(n);
    rep(i,n) {
        cin >> x[i] >> y[i] >> z[i];
    }

    vector<vector<ll>> dp(n+1, vector<ll>(m+1));
    
}

int main()
{
    solve1();
}

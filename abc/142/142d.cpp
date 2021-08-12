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

ll modinv(ll a, ll m)
{
    ll b = m, u = 1, v = 0;
    while (b)
    {
        ll t = a / b;
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

ll gcd(ll n, ll m) {
    if(n%m) {
        return gcd(m, n%m);
    } else {
        return m;
    }
}


map<ll, ll> divs(ll n) {
    map<ll, ll> ret;
    for(ll i = 2; i*i <= n; i++) {
        while(n%i == 0) {
            n /= i;
            ret[i]++;
        }
    }

    if(n != 1) ret[n]++;
    return ret;
}

void solve1() {
    ll a, b; cin >> a >> b;
    ll gc = gcd(a, b);

    map<ll, ll> div = divs(gc);

    cout << (ll)div.size() + 1 << endl;

}

int main()
{
    solve1();
}

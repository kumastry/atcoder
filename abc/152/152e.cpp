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
typedef long long ll;
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


ll gcd(ll a, ll b) {
    if(a%b) {
        return gcd(b, a%b);
    } else {
        return b;
    }
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b)*b;
}

void solve1() {
    ll n; cin >> n;
    vector<ll> a(n); 
    rep(i, n) {
        cin >> a[i];
    }

    if(n == 1) {
        cout << a[0] << endl;
    } else if(n == 2) {
        cout << a[0] + a[1] << endl;
    } else {
        ll lc = lcm(a[1], a[2]);
        for(int i = 3; i < n; i++) {
            lc = lcm(lc, a[i]);
        }

        vector<ll> b(n);
        b[0] = lc / a[0];
    }
}

int main()
{
    solve1();
}






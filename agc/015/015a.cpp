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


void solve1() {
    ll n, a, b; cin >> n >> a >> b;

    if(b <= a) {
        if(b < a) {
            cout << 0 << endl;
        } else {
            cout << 1 << endl;
        }
        
    } else {
        ll val1, val2;
        if(n > 1) {
          val1 = a+b + a*(n-2);
          val2 = a+b + b*(n-2);
        } else {
            val1 = 2;
            val2 = 1;
        }

        cout << max(val2 - val1 + 1, 0LL) << endl;
    }
}

int main()
{
    solve1();
}

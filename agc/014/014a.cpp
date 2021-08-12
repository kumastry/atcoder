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
    ll a, b, c; cin >> a >> b >> c;
    ll ans = 0;
    if(a%2 || b%2 || c%2) {
        cout << 0 << endl;
        return;
    }else if(a == b && b == c) {
        cout << -1 << endl;
        return;
    }
     
    while(1) {
        ll aa = b/2 + c /2;
        ll bb = a/2 + c /2;
        ll cc = b/2 + a /2;

        a = aa, b = bb, c = cc;
        ans ++;
        if(a%2 || b%2 || c%2) {
            cout << ans << endl;
            return;
        }
    }
}

int main()
{
    solve1();
}

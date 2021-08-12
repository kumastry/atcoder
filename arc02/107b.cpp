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

#define fi first
#define se second

typedef long long ll;
#define P pair<ll, ll>

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



void solve1() {
    ll n, k; cin >> n >> k;
    vector<P> p;
    for(ll i = 2; i <= 2*n; i++) {
        ll y = i+k;
        if(y >= 2 && y <= 2*n) {
            p.push_back(P(i, y));
        }
    }

    ll ans1 = 0, ans2 = 0;
    ll ans = 0;
    for(int i = 0; i < (int)p.size(); i++) {
        
    }

    cout << ans << endl;

}

int main()
{
    solve1();
}

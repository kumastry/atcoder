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
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repe(i, j, n) for (ll i = j; i < n; i++)
#define repi(i, n) for (ll i = 0; i <= n; i++)
#define repie(i, j, n) for (ll i = j; i <= n; i++)
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



void solve1() {
    ll n, t; cin >> n >> t; 
    vector<ll> a(n);
    rep(i, n) {
        cin >> a[i];
    }

    ll num = t / 2;
    ll mav = -1, miv = 1e10;
    for(int i = 0; i < n; i++) {
        if(miv > a[i]) {
            miv = a[i];
        }

        mav = max(a[i] - miv, mav);
    }

    num *= mav;
    //cout << mav << endl;
    ll cnt = 0;
    miv = 1e10;
    for(int i = 0; i < n; i++) {
        if(miv > a[i]) {
            miv = a[i];
        }

        //cout << i + 1 << " " << a[i]-miv << endl;
        if(a[i]-miv == mav) {
            cnt ++;
        }        
    }

    cout << cnt << endl;
}

int main()
{
    solve1();
}

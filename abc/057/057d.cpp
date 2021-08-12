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


ll n, a, b;

bool f(ll mid, vector<ll> h) {
    for(ll i = 0; i < n; i++) {
        h[i] -= mid*b;
    }



    sort(all(h), greater<ll>());
    for(int i = 0; i < n; i++) {
        if(h[i] > 0) {
            mid -= ceil(1.0*h[i] / (a-b) );
        } else {
            break;
        }
    }
    if(mid >= 0) {
        //cout << lo << " T" << endl;
        return true;
    } else {
        //cout << lo << " F" << endl;
        return false;
    }
}

void solve1() {
    cin >> n >> a >> b;
    vector<ll> h(n);

    rep(i, n) {
        cin >> h[i];
    }

    ll r = 1000000000, l = 0;
    while(r-l > 1) {
        ll mid = (r+l)/2;
        if(f(mid, h)) {
            r = mid;
        } else {
            l = mid;
        }

        
    }

    cout << r << endl;
}

int main()
{
    solve1();
}

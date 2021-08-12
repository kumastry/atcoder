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


void solve1() {
    ll n, m, t; cin >> n >> m >> t;
    vector<ll> a(m), b(m);

    ll sum = n;
    rep(i, m) {
        cin >> a[i] >> b[i];
    }

    bool f = true;
    sum -= a[0];
    if(sum <= 0) {
        f = false;
       // cout << sum << endl;
    }

    rep(i, m) {
        sum += abs(a[i]-b[i]);
        sum = min(sum, n);
        if(i != m-1) {
            sum -= abs(b[i]-a[i+1]);
            if(sum <= 0) {
               f = false;
              // cout << sum << endl;
            }
        }
    }

    sum -= abs(b[m-1]-t);
    if(sum <= 0) {
       f = false;
    }

  //  cout << sum << endl;

    if(f) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }


}

int main()
{
    solve1();
}

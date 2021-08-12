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
    int n; cin >> n;
    vector<ll> a(n), b(n), c(n);
    rep(i, n) {
        cin >> a[i];
    }

    rep(i, n) {
        cin >> b[i];
    }

    rep(i, n) {
        cin >> c[i];
    }

    sort(all(a)); sort(all(b)); sort(all(c));
    ll ans = 0;
    ll ans1 = 0;

    vector<ll> tmp(n);
    rep(i, n) {
        int num = n - ( upper_bound(all(c), b[i]) - c.begin());
        tmp[i] = num;
    }

    vector<ll> sumt(n+1);
    sumt[0] = 0;

    for(int i = 0; i < n; i++) {
        sumt[i+1] = sumt[i] + tmp[i];
    }

    /*rep(i, n) {
        cout << tmp[i] << " ";
    }

    cout << endl; */

  /*  rep(i, n+1) {
        cout << sumt[i] << " ";
    }

    cout << endl; */

    rep(i, n) {
        int begin = upper_bound(all(b), a[i]) - b.begin();
        int end = n;

        if(begin < 0) {
            begin = 0;
        }

       // cout << sumt[end] - sumt[begin] << " ";

        ans += sumt[end] - sumt[begin];

    }

 
    cout << ans << endl;

}

int main()
{
    solve1();
}

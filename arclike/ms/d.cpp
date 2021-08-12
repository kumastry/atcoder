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
    vector<int> a(n), b(n);

    rep(i, n) {
        cin >> a[i];
    }

    rep(i, n) {
        cin >> b[i];
    }

    ll dif = 0;
    ll df = 0;
    int ans = 0;
    rep(i, n) {
        if(b[i] > a[i]) {
            dif += b[i]-a[i];
            ans++;
        }

        if(a[i] > b[i]) {
            df += a[i] - b[i];
        }
    }

    if(dif == 0) {
        cout << 0 << endl;
    } else if(dif > df){
        cout << -1 << endl;
    } else {
        vector<ll> D;
        rep(i, n) {
            if(a[i] > b[i]) {
                D.push_back(a[i]-b[i]);
            }
        }

        sort(all(D), greater<ll>());
        
        int i = 0;
        while(dif > 0) {
            dif -= D[i];
            ans ++;
            i++;
        }

        cout << ans << endl;
    }

}

int main()
{
    solve1();
}
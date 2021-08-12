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
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i, n) {
        cin >> a[i];
    }

    int r = 0, l = 0;
    map<int, int> m;
    int ans = -1;
    while(r < n || l < n) {
        if(m[a[r]] >= 1) {
            while(l < r && a[l] != a[r]) {
                m[a[l]]--;
                l++;
            }
            m[a[l]]--;
            l++;
        } else {
            m[a[r]]++;
            r++;
        }

        
        //cout << r << " " << l << endl;
        ans = max(ans, abs(r-l));
        if(r >= n || l >= n) {
            break;
        }
    }

    cout << ans << endl;
}

int main()
{
    solve1();
}

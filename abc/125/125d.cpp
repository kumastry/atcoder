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

bool sec(P a, P b) {
    if(a.se == b.se) {
        return a.fi < b.fi;
    } else {
        return a.se < b.se;
    }
}

void solve1() {
    ll n; cin >> n;
    vector<int> a(n);
    vector<int> ab(n);
    ll sum = 0;
    int mcnt = 0;
    rep(i, n) {
        cin >> a[i];
        if(a[i] <= 0) {
            mcnt ++;
        }

        sum += abs(a[i]);
        ab[i] = abs(a[i]);
    }

    if(mcnt%2) {
        sum = 0;
        ll minabs = *min_element(all(ab));

        rep(i, n) {
            if(minabs == abs(a[i])) {
                sum += -abs(a[i]);
            } else {
                sum += abs(a[i]);
            }
        }
    }

    cout << sum << endl;

}

int main()
{
    solve1();
}

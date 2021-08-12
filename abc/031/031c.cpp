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

bool f(P a, P b) {
    if(abs(a.fi-a.se) == abs(b.fi-b.se)) {
        return a.fi > b.fi;
    } else {
        return abs(a.fi-a.se) < abs(b.fi-b.se);
    }
}


void solve1() {
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int summin = 100000000;
    int tasum = -1;
    vector<P> p;
    for(int i = 0; i < n; i++) {
        for(int j = n -1; j >= 0 && i < j; j--) {
            int tsum = 0;
            int asum = 0;
            for(int k = i; k <= j; k+=2) {
                tsum += a[k];
            }

            for(int k = i + 1; k <= j; k+=2) {
                asum += a[k];
            }

            p.push_back(make_pair(tsum, asum));
        }
    }

    sort(all(p), f);

    int ans = p[0].fi;
    rep(i, (int)p.size()) {
        cout << p[i].fi << " " << p[i].se << endl;
        if(p[i].fi > ans) {
            ans = p[i].fi;
            break;
        }
    }

    cout << ans << endl;
}

int main()
{
    solve1();
}

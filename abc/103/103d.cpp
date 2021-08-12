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

bool by(P a, P b) {
    if(a.se == b.se) {
        return a.fi < b.fi;
    } else {
        return a.se < b.se;
    }
}

void solve1() {
    int n, m; cin >> n >> m;
    vector<P> p(m);

    rep(i,m) {
        cin >> p[i].fi >> p[i].se;
    }

    sort(all(p), by);

    int ans = 1;
    int end = p[0].se;
    for(int i = 1; i < m; i++) {
        if(end > p[i].fi && end <= p[i].se) {
            //cout << 1 << endl;
        } else {
            ans ++;
            end = p[i].se;
        }

        //cout << p[i].fi << " " << p[i].se << endl;
    }

    cout << ans << endl;
}

int main()
{
    solve1();
}

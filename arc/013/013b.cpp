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
    int c; cin >> c;
    vector<int> n(c), m(c), l(c);
    rep(i, c) {
        cin >> n[i] >> m[i] >> l[i];
    }

    int maxfis = -1;
    int maxsec = -1;
    int maxth = -1;
    rep(i, c) {
        int fis = min({n[i], m[i], l[i]});
        int th = max({n[i], m[i], l[i]});
        int sec = n[i] + m[i] + l[i] - fis - th;

        maxfis = max(maxfis, fis);
        maxsec = max(maxsec, sec);
        maxth = max(maxth, th);
    }

    cout << maxfis*maxsec*maxth << endl;

}

int main()
{
    solve1();
}

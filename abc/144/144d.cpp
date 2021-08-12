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




long double f(long double a, long double b, long double theta) {
    if(theta > PI / 2.0 - EPS) {
        return 0.0;
    }
    long double ret;
    if(a * tan(theta) <= b) {
        ret = a * a * b - a * a * a * tan(theta) / 2.0;
    } else {
        ret = b * b / tan(theta) * a / 2.0;
    }
    return ret;
}


void solve1() {
    int a, b, x; cin >> a >> b >> x;

    double l = 0;
    double r = 90;

    for(int i = 0; i < 100; i++) {
        double mid = (r+l)/2.0;

        if(f(mid, a, b, x)) {
            l = mid;
        } else {
            r = mid;
        }

        cout << l << " " << r << endl;
    }

    cout << fixed << setprecision(15) << l << endl;
}

int main()
{
    solve1();
}

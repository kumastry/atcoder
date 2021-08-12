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
    double a, b, c; cin >> a >> b >> c;

    int numa = 100-a;
    int numb = 100-b;
    int numc = 100-c;

    double dp[101][101][101];
    rep(i, 102) {
        rep(j, 102) {
            dp[i][j][0] = 1.0;
        }
    }

    rep(i, 102) {
        rep(j, 102) {
            dp[i][0][j] = 1.0;
        }
    }

    rep(i, 102) {
        rep(j, 102) {
            dp[0][i][j] = 1.0;
        }
    }

    for(int i = 1; i <= numa; i++) {
        for(int j = 1; j <= numb; j++) {
            for(int m = 1; m <= numc; m++) {
                ll n = 300 - i - j - m;
                dp[i][j][m] = ((100 - i) /(1.0*n))*dp[i-1][j][m]
                 + ((100 - j) /(1.0*n))*dp[i][j-1][m]
                 + ((100 - m) /(1.0*n))*dp[i][j][m-1];
            }
        }
    }

    cout << dp[numa][numb][numc] << endl;
}

int main()
{
    solve1();
}

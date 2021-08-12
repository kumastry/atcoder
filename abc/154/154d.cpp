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
#define rep(i, j, n) for (int i = j; i < n; i++)
#define repi(i, j, n) for (int i = j; i <= n; i++)
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

ll combi(ll n) {
    return  n*(n-1) / 2;
}

void solve1() {
   int n, k; cin >> n >> k;
   vector<int> p(n);
   rep(i, 0, n) {
       cin >> p[i];
   }

   vector<double> sum(n+1);
   sum[0] = 0.0;
   for(int i = 0; i < n + 1; i++) {
       sum [i+1] = sum[i] + p[i]*(p[i]+1) / 2.0 / p[i];
   }

   double ans = -1.0;
   for(int i = 0; i < n - k + 1; i++) {
       ans = max(ans, sum[i+k]-sum[i]);
   }

   cout << fixed << setprecision(10) << ans << endl;
}

int main()
{
    solve1();
}

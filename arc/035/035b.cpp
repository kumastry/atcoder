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

ll fuctorial(ll n) {
    ll ret = 1;
    for(int i = 1; i <= n; i++) {
        ret *= i;
        ret %= MOD;
    }

    return ret;
}

void solve1()  {
   int n; cin >> n;
   vector<ll> t(n);
   map<int, ll> m;
   rep(i, n) {
       cin >> t[i];
       m[t[i]] ++;
   }

   sort(all(t));
   vector<ll> sum(n+1);
   sum[0] = 0;
   ll sums = 0;
   ll ans = 1;

   for(int i = 0; i < n; i++) {
       sum[i+1] = sum[i]+t[i];
       sums += sum[i+1];
   }

   for(auto itr = m.begin(); itr != m.end(); itr++) {
       ans *= fuctorial(itr->second); 
       ans %= MOD;
   }

   cout << sums << endl;
   cout << ans << endl;
}

int main()
{
    solve1();
}

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
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cstdlib>
#include <queue>
#include <stack>
#include <bitset>

using namespace std;
typedef long long ll;
#define MOD 1000000007
#define PI 3.1415926535897932
#define INF 1e18
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repe(i, j, n) for (ll i = j; i < n; i++)
#define repi(i, n) for (ll i = 0; i <= n; i++)
#define repie(i, j, n) for (ll i = j; i <= n; i++)
#define all(x) x.begin(), x.end()
#define println() cout << endl
#define P pair<ll, ll>
#define fi first
#define se second
using Graph = vector<vector<ll>>;

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

ll dp[2000][2000];
ll nCr(ll n, ll r)
{
       if(n==r) return dp[n][r] = 1;
       if(r==0) return dp[n][r] = 1;
       if(r==1) return dp[n][r] = n;
       if(dp[n][r]) return dp[n][r];
       return dp[n][r] = nCr(n-1,r) + nCr(n-1,r-1);
}
 

void solve1() {
    ll a, b, k; cin >> a >> b >> k;
    ll s = a+b;
    string ans = "";
    ll num = 0;
    for(ll i = 0; i < s; i++) {
        if(a == 0 || b == 0) {
            break;
        }

       ll t = num;
       t += nCr(a+b-1,a-1);
       if(t >= k) {
           ans += 'a';
           a -- ;
       } else if(t < k) {
           ans += 'b';
           b --;
           num = t;
       }
    }

    //cout << ans << endl;

    for(int i = 0; i < a; i++) {
        ans += 'a';
    }

    for(int i = 0; i < b; i++) {
        ans += 'b';
    }

    cout << ans << endl;
   
}

int main()
{
    solve1();
}

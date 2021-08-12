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
#include <math.h>    // for fabs()
#include <stdio.h>   // for printf()

using namespace std;

#define MOD 1000000007
#define PI 3.1415926535897932
#define INF 1e9
#define max 1e3                //最大繰り返し回数
#define eps 1.0e-6              //収束条件
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
using Graph = vector<vector<ll>>;


ll dp[2500][2500];

ll nCr(ll n, ll r)
{
       if(n==r) return dp[n][r] = 1;
       if(r==0) return dp[n][r] = 1;
       if(r==1) return dp[n][r] = n%MOD;
       if(dp[n][r]) return dp[n][r]%MOD;
       return dp[n][r] = nCr(n-1,r)%MOD + nCr(n-1,r-1)%MOD;
}
 
ll H(ll n, ll r) {
    return nCr(n+r-1, r)%MOD;
}

void solve1() {
    ll n, k; cin >> n >> k;
    ll red = n-k+1;
    //cout << dp[4][5] << endl;
    for(int i = 1; i <= k; i++) {
        ll nk = k-i;
        ll ans = H(i,nk)%MOD;
        //cout << red << " " << i << endl;
        if(red < i) {
            cout << 0 << endl;
        } else {
          ans = (ans*nCr(red, i))%MOD;
          cout << ans << endl;
        }
    }
}

int main()
{
    solve1();
}

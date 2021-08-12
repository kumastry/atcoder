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

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int h, w; 
vector<vector<ll>> dp, a;

ll rec(ll i, ll j) {
    if(dp[i][j] != -1) {
        return dp[i][j];
    }

  
    ll res = 0;
    for(int k = 0;k < 4; k++) {
        ll x = j + dx[k],y = i + dy[k];
        if(x > w || x <= 0 || y > h || y <= 0) continue;
        if(a[y-1][x-1] > a[i-1][j-1]) {
            res = (res+rec(y,x))%MOD;
        }
    }

    return dp[i][j] = (res+1)%MOD;
}

void solve1() {
    cin >> h >> w;
     a.resize(h,vector<ll>(w));
     dp.resize(h+1,vector<ll>(w+1,-1));
    rep(i, h) {
        rep(j, w) {
            cin >> a[i][j];
        }
    }


    ll sum = 0;
    /*rec(1, 1, dp, a);

    for(int i = 1; i <= h; i++) {
        for(int j = 1; j <= w; j++) {
            cout << dp[i][j] << " ";
        }

        cout << endl;
    }+*/

   for(int i = 1; i <= h; i++) {
        for(int j = 1; j <= w; j++) {
            sum = (sum+rec(i, j))%MOD;
            sum %= MOD;
        }
    }




    cout << sum << endl;
}

int main()
{
    solve1();
}

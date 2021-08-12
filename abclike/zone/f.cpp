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

ll r, c; 
vector<vector<ll>> a, b;
ll memo(vector<vector<ll>>dp, ll i, ll j) {
    if(i == 1 && j == 1) return dp[i][j] = 0;
    if(dp[i][j] != 0) return dp[i][j];
    ll res = 1e18;

    res = min(res, dp[r][c-1]+a[i-1][j-2]);
    res = min(res, dp[r][c+1]+a[i-1][j-1]);
    res = min(res, dp[r-1][c]+b[i-2][j-1]);

    for(int k = 1; k <= r; k++) {
        res = min(res, dp[r+k][c]+1+i);
    }

    return dp[i][j] = res;
}

void solve1() {
    cin >> r >> c;
    
    a.resize(r, vector<ll>(c-1)), b.resize(r-1, vector<ll>(c));
    rep(i, r) {
        rep(j, c-1) {
            cin >> a[i][j];
        }
    }

    rep(i, r-1) {
        rep(j, c) {
            cin >> b[i][j];
        }
    }


    vector<vector<ll>> dp(r+1, vector<ll>(c+1));
    cout << memo(dp, r, c) << endl;
}

int main()
{
    solve1();
}

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
using Graph = vector<vector<ll>>;
ll w, n, k; 
vector<ll> a, b;
ll dp[60][10010][60];   

ll rec(ll i, ll j, ll m) {
    if(i == 0 || j == 0 || m == 0) return 0;
    if(dp[i][j][m]) return dp[i][j][m];

    if(n>1 && j >= a[i] && m-1) {
        return dp[i][j][m] = max()
    }
}
void solve1() {
    cin >> w >> n >> k;
    a.assign(n, 0); b.assign(n, 0);
    rep(i, n) {
        cin >> a[i] >> b[i];
    }

    cout << rec(n, w, k) << endl;
}

int main()
{
    solve1();
}

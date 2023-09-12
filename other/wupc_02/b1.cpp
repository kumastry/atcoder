#include <bits/stdc++.h>

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

void solve1() {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> dp(n);
    dp[0] = 0;

    if(s[1] == 'X') {
        dp[1] = 1;
    } else {
        dp[1] = 0;
    }

    if(s[2] == 'X') {
        dp[2] = 1;
    } else {
        dp[2] = 0;
    }

    for(int i = 3; i < n; i++) {
         dp[i] = min({dp[i-1], dp[i-2], dp[i-3]});
        if(s[i] == 'X') {
           dp[i] += 1;
        }
    }
    cout << dp[n-1] << endl;
}

int main()
{
    solve1();
}

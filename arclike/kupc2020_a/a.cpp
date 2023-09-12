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
    vector<int> x(n), y(n);
    rep(i, n) {
        cin >> x[i] >> y[i];
    }

    int ans = 0;

    for(int i = 0; i < n-1; i++) {
        ans += abs(x[i]-x[i+1]) + abs(y[i]-y[i+1]);
    }

    cout << ans << endl;
}

int main()
{
    solve1();
}

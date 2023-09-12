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
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i, n) {
        cin >> a[i];
    }

    vector<ll> ans;

    ll q; cin >> q;
    ll padding_num = 0;
    rep(i, q) {
        ll q1; cin >> q1;

        if(q1 == 3 ) {
            ll i; cin >> i;
            ans.push_back(a[i]);
        } else if(q1 == 2) {
            ll i, x; cin >> i >> x;
            a[i] += x;
        } else {
            ll x; cin >> x;
            padding_num =
        }
    }

    rep(i,ans.size()) {
        cout << ans[i] << endl;
    }
}

int main()
{
    solve1();
}

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
    ll ans = n;

    set<ll> st;
    for(ll i = 2; i * i <= n; i++) {
        ll base = i;
        ll num = i;
        while(num * base <= n) {
            num *= base;
            if(st.find(num) == st.end()) {
                st.insert(num);
                //cout << num << endl;
                ans --;
            }

        }


    }

    cout << ans << endl;
}

int main()
{
    solve1();
}

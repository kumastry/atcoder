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
#define P pair<ll, ll>
#define fi first
#define se second
typedef long long ll;
using Graph = vector<vector<ll>>;

void solve1() {
    ll n, q; cin >> n >> q;
    vector<ll> a(n);
    ll max_val = -1;
    rep(i, n) {
        cin >> a[i];
        max_val = max(a[i], max_val);
    }

    map<ll, ll> cnts;

    // 上から見た方がよい
    map<P, ll> mp;
    for(ll i = 0; i < n; i++) {
        mp.insert(make_pair(
            make_pair(a[i], cnts[a[i]-1]++),
            i
        ));
    }


    // for(auto itr = cnts.begin(); itr != cnts.end(); itr++) {
    //     cout << itr->first << " " << itr->second << endl;
    // }

    for(ll i = 0; i < q; i++) {
        ll x, k; cin >> x >> k;
        //cout << cnts[x - 1] << " " <<  k << endl;
        if(x > max_val) {
            cout << -1 << endl;
            continue;
        }
        if(cnts[x - 1] >= k) {
          cout << mp[make_pair(x, k-1)] + 1  << endl;
        } else {
          cout << -1 << endl;
        }
    }
}

int main()
{
    solve1();
}

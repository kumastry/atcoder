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

    ll ans = 1e10;
    for (ll bit = 0; bit < (1<<(n-1)); ++bit) {
 
        vector<bool> seen(n-1, false);
        for (ll i = 0; i < n-1; ++i) {
            if (bit & (1<<i)) { // 列挙に i が含まれるか
                seen[i];
            }
        }

        ll of = a[0];
        for(int i = 1; i < n; i++) {
            if(seen[i-1]) {
                of ^= a[i];
            } else {
                of |= a[i];
            }
        }
        ans = min(ans, of);
    }

    cout << ans << endl;

}

int main()
{
    solve1();
}

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


bool f(ll d, string x, ll m) {

    ll n = (int)x.size();
    ll val = 0;
    ll base = 1;
    rep(j, n) {
        val += (ll)(x[n-j-1]-'0')*base;
        base *= d;
        if(base < 0) {
            return false;
        }
        cout << val << endl;
        if(val < 0) {
            return false;
        }
    }

    if(val <= m) {
        return true;
    } else {
        return false;
    }
}

void solve1() {
    string x; cin >> x;
    ll m; cin >> m;

    ll mv = -1;
    rep(i, (int)x.size()) {
        if(mv < x[i]-'0') {
            mv = x[i]-'0';
        }
    }

    ll d = mv+1;
    ll i = d;
    ll n = (int)x.size();
    ll ans = 0;
    ll pre = -1;

    ll r = 1e18,  l = d;
    while(r-l >1 ) {

        ll mid = (r+l)/2;
        if(f(mid, x, m)) {
            l = mid;
        } else {
            r  = mid;
        }
        //cout << l << " " << r << endl;
        //cout << mid << endl;
    }

    //cout << l << " " << r << endl;

    cout << l - mv << endl;


}

int main()
{
    solve1();
}

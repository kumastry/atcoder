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
#define P pair<ll, ll>
#define fi first
#define se second
typedef long long ll;
using Graph = vector<vector<ll>>;


ll anum = 0;
ll tnum = 0;
bool by1(P a, P b) {
    return 2*a.fi + a.se > 2*b.fi + b.se;
}

void solve1() {
    ll n; cin >> n;
    vector<P> a(n);
    
    rep(i, n) {
        cin >> a[i].fi >> a[i].se;
        anum += a[i].fi;
    }

    

    sort(all(a), by1);

    
    ll ans = 0;
    rep(i, n) {
        if(tnum > anum) {
            break;
        }
        tnum += a[i].fi + a[i].se;
        anum -= a[i].fi;
        ans ++;
    }

  /* rep(i, n) {
        cout << a[i].fi <<  " " << a[i].se << endl;
    }
    cout << anum << " " << tnum << endl; */
    cout << ans << endl;

}

int main()
{
    solve1();
}

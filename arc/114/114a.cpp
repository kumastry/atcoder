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

ll gcd(ll a, ll b) {
    if(a%b) {
        return gcd(b, a%b);
    } else {
        return b;
    }
}

void solve1() {
    ll n; cin >> n;
    vector<ll> x(n);
   
    rep(i, n) {
        cin >> x[i];
    }

    vector<ll> p = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
    int num = (int)p.size();
    ll ans = 1e18;
    for(int bit = 0; bit < (1 << num); bit++) {
        ll tmp = 1;
        for(int i = 0; i < num; i++) {
            if(bit & (1 << i)) {
                tmp *= p[i];
                cout << p[i] << endl;
            }
        }

        bool f = true;
        for(int i = 0; i < n; i++) {
            if(gcd(x[i], tmp) == 1) {
                f = false;
            }
        }

       
        if(f) {
            ans = min(ans, tmp);
        }
    }
    cout << ans << endl;

    
}

int main()
{
    solve1();
}

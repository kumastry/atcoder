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

#define MOD 998244353
#define PI 3.1415926535897932
#define INF 1e9
#define rep(i, n) for (int i = 0; i < n; i++)
#define repe(i, j, n) for (int i = j; i < n; i++)
#define repi(i, n) for (int i = 0; i <= n; i++)
#define repie(i, j, n) for (int i = j; i <= n; i++)
#define all(x) x.begin(), x.end()
#define println() cout << endl

#define fi first
#define se second


typedef long long ll;
using Graph = vector<vector<ll>>;
#define P pair<ll, ll>
bool f(P a, P b) {
    return a.fi + a.se > b.fi + b.se;
}
void solve1() {
    ll n; cin >> n;
    vector<P> p(n);
    rep(i, n) {
        cin >> p[i].fi >> p[i].se; 
    }

    sort(all(p), f);

    ll t = 0, a = 0;
    rep(i, n) {
        if(i%2==0) {
            t += p[i].fi;
        } else {
            a += p[i].se;
        }
    }

    cout << t-a << endl;
}

int main()
{
    solve1();
}

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
#define INF 1e18
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


void solve1() {
    ll n, m; cin >> n >> m;
    vector<ll> l(m), r(m), d(m);
    rep(i, m) {
        cin >> l[i] >> r[i] >> d[i];
    }

    if(m == 0) {
        cout << "Yes" << endl;
        return;
    }

    map<P, ll> mp;
    set<ll> st;
    for(int i = 0; i < n; i ++) {
        
    }

    cout << "Yes" << endl;
}

int main()
{
    solve1();
}

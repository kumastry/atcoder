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
#include <tuple>

using namespace std;

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



void solve1()
{
    ll n, m; cin >> n >> m;
    vector<ll> t(m+2, 0);
    ll sum = 0;
    rep(i, n) {
        ll r, l, c; cin >> l >> r >> c;
        t[l] += c;
        t[r+1] -= c;   
        sum += c; 
    }  

  
    for (int i = 0; i <= m; i++) {

        if (0 < i) t[i] += t[i - 1];
    }

    ll mi = INF;
    for(int i = 1; i <= m; i++) {
        mi = min(mi, t[i]);
    }

    cout << sum-mi << endl;
}

int main()
{
    solve1();
}

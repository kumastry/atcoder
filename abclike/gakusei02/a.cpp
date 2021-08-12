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
typedef long long ll;
#define MOD 1000000007
#define PI 3.1415926535897932
#define INF 1e18
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repe(i, j, n) for (ll i = j; i < n; i++)
#define repi(i, n) for (ll i = 0; i <= n; i++)
#define repie(i, j, n) for (ll i = j; i <= n; i++)
#define all(x) x.begin(), x.end()
#define println() cout << endl
#define P pair<ll, ll>
#define fi first
#define se second
using Graph = vector<vector<ll>>;


void solve1() {
    ll x, y, z; cin >> x >> y >> z;
    double t = (1.0* y / x) * z;
  	if(y % x == 0) {
      cout << t << endl;
    } else {
      cout << floor(t) << endl;
    }
}

int main()
{
    solve1();
}

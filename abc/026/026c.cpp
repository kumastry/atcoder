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



ll recur(Graph g, int nw) {

    if(g[nw].size() == 0) {
        return 1LL;
    }

    ll maxV = -1, minV = 1e18;
    for(int i = 0; i < (int)g[nw].size(); i++) {
        //cout << nw +1 << " " <<g[nw][i] +1 << endl;
        minV = min(recur(g, g[nw][i]), minV);
        maxV = max(recur(g, g[nw][i]), maxV);
    }

    return maxV + minV + 1;
}

void solve1() {
    int n; cin >> n;

    Graph g(n);

    rep(i, n-1) {
        int a; cin >> a;
        a--;
        g[a].push_back(i+1);
    }

    cout << recur(g, 0) << endl;
}

int main()
{
    solve1();
}

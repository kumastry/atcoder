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
#define P pair<int, int>
#define fi first
#define se second


typedef long long ll;
using Graph = vector<vector<ll>>;
ll n; 
vector<bool> seen;
vector<ll> c;
vector<ll> bfs(Graph g) {
    vector<ll> t(n);

    queue<ll> que;
    seen[0] = true;
    que.push(0);
    int idx = 0;
    while(que.size()) {
        ll f = que.front();
        t[idx] = c[idx];
        idx++;
        que.pop();
        for(int i = 0; i < (int)g[f].size(); i++) {
            if(seen[g[f][i]]) continue;
            seen[g[f][i]] = true;
            que.push(g[f][i]);
        }
    }

    return t;
}

void solve1() {
    cin >> n;
    Graph g(n);
    c.assign(n, 0);
    vector<ll> aa(n), bb(n);
    rep(i, n-1) {
        ll a, b; cin >> a >> b;
        aa[i] = a; bb[i] = b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }

    rep(i, n) {
        cin >> c[i];
    }

    sort(all(c), greater<ll>());
    ll ans = 0;

    seen.assign(n, false);
    vector<ll> t = bfs(g);

    rep(i, n-1) {
        ans += min(t[aa[i]-1], t[bb[i]-1]);
    }

    cout << ans << endl;
    rep(i, n) {
        if(i != n-1) {
            cout << t[i] << " ";
        } else {
            cout << t[i] << endl;
        }
    }
}

int main()
{
    solve1();
}

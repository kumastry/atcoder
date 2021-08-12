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
using Graph = vector<vector<int>>;

typedef long long ll;

long long modinv(long long a, long long m)
{
    long long b = m, u = 1, v = 0;
    while (b)
    {
        long long t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= m;
    if (u < 0)
        u += m;
    return u;
}

vector<bool> seen;

int bfs(Graph g, int s) {
    if(seen[s]) {
        return 0;
    } else {
        seen[s] = true;
    }

    queue<int> que; que.push(s);
    int degree = (int)g[s].size();
    int nodenum = 1;

    while(que.size()) {
        int f = que.front(); que.pop();

        for(int i = 0; i < (int)g[f].size(); i++) {
            if(!seen[g[f][i]]) {
                seen[g[f][i]] = true;
                degree += (int)g[g[f][i]].size();
                que.push(g[f][i]);
                nodenum ++;
            } 
        }

    }

    nodenum--;

    return degree == 2*nodenum?1:0;
}

void solve1()  {
    int n, m; cin >> n >> m;
    Graph g(n);
    seen.assign(n, false);

    rep(i, m) {
        int a, b; cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a); 
    }

    int ans = 0;

    for(int i = 0; i < n; i++) {
        ans += bfs(g, i);
    }

    cout << ans << endl;
}

int main()
{
    solve1();
}

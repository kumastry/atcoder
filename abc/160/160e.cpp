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


using G = vector<vector<int>>;

void bfs(G g, vector<int>& d, vector<bool>& seen) {
    int s = 0;
    seen[s] = true;
    queue<int> que;
    que.push(s);

    while(que.size()) {
        int f = que.front(); que.pop();
        for(int i = 0; i < (int)g[f].size(); i++) {
            if(!seen[g[f][i]]){
               d[g[f][i]] = d[f] + 1;
               que.push(g[f][i]);
               seen[g[f][i]] = true;
            }
        }
    }
}

void solve1() {
    int n, x, y; cin >> n >> x >> y;

    G g(n);
    for(int i=0; i < n-1; i++) {
        g[i].push_back(i+1);
        g[i+1].push_back(i);
    }

    g[x-1].push_back(y-1);
    g[y-1].push_back(x-1);
    vector<int> d(n);
    vector<bool> seen(n, false);
    bfs(g, d, seen);

    vector<int> dist;
    map<int, int> ans;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int len = min(abs(j-i), abs(x -(i+1), ));

            ans[len] ++;

        }
    }

    for(int i = 1; i <= n-1; i++) {
        cout << ans[i] << endl;
    }
}

int main()
{
    solve1();
}

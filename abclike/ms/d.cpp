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

ll modinv(ll a, ll m)
{
    ll b = m, u = 1, v = 0;
    while (b)
    {
        ll t = a / b;
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

using PP = pair<P, int>;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int h, w; 

queue<PP> que;

int bfs(vector<vector<char>> a, int cnt) {
    set<int> range;
    while(que.size()) {
        PP f = que.front(); que.pop();
        range.insert(f.se);

        if(cnt == h*w) {
            break;
        }

        for(int i = 0; i < 4; i++) {
            int x = f.fi.se + dx[i];
            int y = f.fi.fi + dy[i];

            if(x >= 0 && x < w && y >= 0 && y < h && a[y][x] != '#') {
                a[y][x] = '#';
                que.push(PP( P(y, x), f.se+1));
                cnt ++;
            }
        }

        if(cnt == h*w) {
            break;
        }

       
    }    

    return *range.rbegin() + 1;
}

void solve1() {
    int n; cin >> n;
    Graph g(n);
    rep(i, n-1) {
        int a, b; cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    
}

int main()
{
    solve1();
}

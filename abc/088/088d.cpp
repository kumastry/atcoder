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

vector<vector<int>> dist;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void bfs(vector<vector<char>> g, int h, int w) {
    queue<P> que;
    que.push(make_pair(0, 0));
    dist[0][0] = 0;

    while(que.size()) {
        P fr = que.front(); que.pop();
        
        for(int i = 0; i < 4; i++) {
            int x = fr.se;
            int y = fr.fi;
            x += dx[i]; y += dy[i];
            if(x >= 0 && x < w && y >= 0 && y < h && g[y][x] != '#' && dist[y][x] == -1) {
                que.push(make_pair(y, x));
                dist[y][x] = dist[fr.fi][fr.se] + 1;
            }
        }
    }
    
}

void solve1()
{
    int h, w; cin >> h >> w;
    vector<vector<char>> g(h, vector<char>(w));
    dist.assign(h, vector<int>(w));
    int bcnt = 0;
    rep(i, h) {
        rep(j, w) {
            cin >> g[i][j];
            if(g[i][j] == '#') {
                bcnt ++;
            }

            dist[i][j] = -1;
        }
    }

    bfs(g, h, w);
    if(dist[h-1][w-1] != -1) {
        cout << h*w - bcnt - dist[h-1][w-1] - 1 << endl;
    } else {
        cout << -1 << endl;
    }
}

int main()
{
    solve1();
}

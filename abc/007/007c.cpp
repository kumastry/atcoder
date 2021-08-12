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
int h, w, sy, sx, gy, gx;
vector<vector<char>> c;
vector<vector<int>> dist;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void bfs(int sy, int sx) {
    dist[sy][sx] = 0;
    queue<P> que;
    que.push(P(sy, sx));

    while(que.size()) {
        P f = que.front(); que.pop();

        for(int i = 0;i< 4;i++) {
            int x = f.second + dx[i], y = f.first + dy[i];
            if(x < 0 || x >= w || y < 0 || y >= h || c[y][x] == '#' ||dist[y][x] != -1) continue;
            que.push(P(y, x));
            dist[y][x] = dist[f.first][f.second] + 1;
        }
    }
}

void solve1() {
    cin >> h >> w >> sy >> sx >> gy >> gx;
    c.resize(h, vector<char>(w));
    dist.resize(h, vector<int>(w, -1));

    rep(i,h) {
        rep(j, w) {
            cin >> c[i][j];
        }
    }

    bfs(sy-1, sx-1);

    cout << dist[gy-1][gx-1] << endl;

}

int main()
{
    solve1();
}

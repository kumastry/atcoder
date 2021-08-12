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
vector<vector<bool>> seen;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void dfs(int sy, int sx) {
    seen[sy][sx] = true;
    for(int i = 0;i< 4;i++) {
        int x = sx + dx[i], y = sy + dy[i];
        if(x < 0 || x >= w || y < 0 || y >= h || c[y][x] == '#' || seen[y][x]) continue;
        dfs(y, x);
    }
    
}

void solve1() {
    cin >> h >> w;
    c.resize(h, vector<char>(w));
    seen.resize(h, vector<bool>(w, false));

    rep(i,h) {
        rep(j, w) {
            cin >> c[i][j];
            if(c[i][j] == 's') {
                sy = i;
                sx = j;
            }

            if(c[i][j] == 'g') {
                gy = i;
                gx = j;
            }
        }
    }

    dfs(sy, sx);
    string ans = seen[gy][gx]?"Yes":"No";
    cout << ans << endl;

}

int main()
{
    solve1();
}

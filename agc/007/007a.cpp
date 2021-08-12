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

int dx[2] = {0, 1};
int dy[2] = {1, 0};

void bfs(vector<vector<char>> &a, int h, int w, vector<vector<int>> &dist) {
    P s; s.fi = 0; s.se = 0;
    queue<P> que; que.push(s);
    dist[s.fi][s.se] = 0;

    while(que.size()) {
        P f = que.front(); que.pop();

        for(int i = 0; i < 2; i++) {
            int x = f.se + dx[i];
            int y = f.fi + dy[i];

            if(x >= 0 && x < w && y >= 0 && y < h && dist[y][x] == -1) {
                que.push(P(y, x));
                dist[y][x] = dist[f.fi][f.se] + 1;
            }

        }

    }
}

int num(vector<vector<char>>& a, int h, int w) {
    int res = 0;
    rep(i, h) {
        rep(j, w) {
            if(a[i][j] == '#') {
                res ++;
            }
        }
    }

    return res;
}


void solve1() {
    int h, w; cin >> h >> w;
    vector<vector<char>> a(h, vector<char>(w));
    vector<vector<int>> dist(h, vector<int>(w, -1));

    rep(i, h) {
        rep(j, w) {
            cin >> a[i][j];
        }
    }

    //cerr << 1 << endl;
    bfs(a, h, w, dist);
    //cerr << 2 << endl;

    if(dist[h-1][w-1] == -1 || dist[h-1][w-1] + 1 != num(a, h, w)) {
        cout << "Impossible" << endl;
    } else {
        cout << "Possible" << endl;
    }
}

int main()
{
    solve1();
}

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

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(vector<vector<int>>& dist, P s, int h, int w, vector<vector<char>> st) {
    dist[s.fi][s.se] = 0;
    queue<P> que; que.push(s);

    while(que.size()) {
        P f = que.front(); que.pop();

        for(int i = 0; i < 4; i++) {
            int x = dx[i] + f.se;
            int y = dy[i] + f.fi;

            if(x >= 0 && x < w && y >= 0 && y < h && st[y][x] != '#' && dist[y][x] == INF) {
                dist[y][x] = dist[f.fi][f.se] + 1;
                que.push(P(y, x));
            }

        }
    }


}

void solve1() {
    int h, w; cin >> h >> w;
    vector<vector<char>> s(h, vector<char>(w));
    rep(i, h) {
        rep(j, w) {
            cin >> s[i][j];
        }
    }

    vector<vector<int>> dist(h, vector<int>(w));
    int maxV = -1;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            
            rep(i, h) {
                rep(j, w) {
                    dist[i][j] = INF;
                }
            }

            if(s[i][j] == '.') {
                bfs(dist, P(i, j), h, w, s);
            }

            rep(i, h) {
                rep(j, w) {
                    if(dist[i][j] != INF) {
                      maxV = max(maxV, dist[i][j]);
                    }
                }
            }

        }
    }

    cout << maxV << endl;
}

int main()
{
    solve1();
    //solve2();
}

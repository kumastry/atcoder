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
#include <deque>

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

int dx[4] = {0, -1, 1, 0};
int dy[4] = {1, 0, 0, -1};
int r, c, d;

void bfs(vector<vector<int>>& dist, int sx, int sy) {
    dist[sy][sx] = 0;
    queue<P> que; que.push(P(sy, sx));

    while(que.size()) {
        P p = que.front(); que.pop();

        for(int i = 0; i < 4; i++) {
            int x = p.se + dx[i];
            int y = p.fi + dy[i];

            if(x >= 0 && x < c && y >= 0 && y < r && dist[y][x] == -1) {
                dist[y][x] = dist[p.fi][p.se] + 1;
                que.push(P(y, x));
            }
        }
    }

}

void solve1() {
    string s; cin >> s;
    int y = 1000*(s[0]-'0') + 100*(s[1]-'0') + 10*(s[2]-'0') + s[3]-'0';
    int m = 10*(s[5]-'0') + s[6]-'0';
    int d = 10*s[8]-'0' + s[9]-'0';

    for(int i = y; i <= 3000; i++) {
        for(int j = m; j <= 12; j++) {
            if(j)
        }
    } 
}

int main()
{
    solve1();
}

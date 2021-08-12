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

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void solve1() {
    vector<vector<int>> a(4);

    rep(i, 4) {
        rep(j, 4) {
            int x = j, y = i;
            for(int k = 0; k < 4; k++) {
                x += dx[k]; y += dy[k];
                if(x >= 0 && x < 4 && y > 0 && y < 4) {
                    if(a[i][j] == a[y][x]) {
                        cout << "CONTINUE" << endl;
                        return;
                    }
                }
            }
        }
    }

    cout << "GAMEOVER" << endl;
}

int main()
{
    solve1();
}

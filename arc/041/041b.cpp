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
    int h, w; cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w)), ans(h, vector<int>(w));

    rep(i, h) {
        string s; cin >> s;
        rep(j, w) {
            a[i][j] = s[j]-'0';
        }
    }


    rep(i, h) {
        rep(j, w) {
            int minv = 10;
            for(int s = 0; s < 4; s++) {
                int x = j + dx[s];
                int y = i + dy[s];

                
                if(x >= 0 && x < w && y >= 0 && y < h) {
                    minv = min(minv, a[y][x]);
                }
            }

            if(i == 0 || i == h-1 || j == 0 || j == w-1) {
                ans[i][j] = 0;
            } else {
                ans[i][j] = minv;
            }

           
        }
    }

    rep(i, h) {
        rep(j, w) {
            cout << ans[i][j];
        }
        cout << endl;
    }
}

int main()
{
    solve1();
}

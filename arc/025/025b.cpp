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

void solve1() {
    int h, w; cin >> h >> w;
    vector<vector<int>> c(h, vector<int>(w));

    rep(i, h) {
        rep(j, w) {
            cin >> c[i][j];
            if((i+j)%2) {
                c[i][j] *= -1;
            }
        }
      
    }


    vector<vector<int> > s(h+1, vector<int>(w+1, 0));
    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j)
            s[i+1][j+1] = s[i][j+1] + s[i+1][j] - s[i][j] + c[i][j];


    int ans = 0;
 
    for(int x1 = 0; x1 < w; x1++) {
        for(int y1 = 0; y1 < h; y1++) {
            for(int x2 = x1+1; x2 <= w; x2++) {
                for(int y2 = y1+1; y2 <= h; y2++) {
                    int val = s[y2][x2] - s[y1][x2] - s[y2][x1] + s[y1][x1];
                    //cout << val << endl;
                    if(val == 0) {
                        ans = max(ans, abs(x2-x1)*abs(y2-y1));
                    }
                }
            }
        }
    }

    cout << ans << endl;
}

int main()
{
    solve1();
}

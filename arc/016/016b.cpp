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


void solve1() {
    int n; cin >> n;
    vector<vector<char> > x(n, vector<char>(9));

    rep(i, n) {
        rep(j, 9) {
            cin >> x[i][j];
        }
    }

    int ans = 0;
    rep(i, n) {
        rep(j, 9) {
            if(x[i][j] == 'x') {
                ans ++;
                x[i][j] == '.';
            } else if(x[i][j] == 'o') {
                int h = i;
                while(h < n && x[h][j] == 'o') {
                    x[h][j] = '.';
                    h++;
                }
                ans ++;
            }
        }
    }

    cout << ans << endl;
}

int main()
{
    solve1();
}

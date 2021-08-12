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
#include <unordered_map>

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
    vector<vector<int>> d(n, vector<int>(n));

    rep(i, n) {
        rep(j, n) {
            cin >> d[i][j];
        }
    }

    int q; cin >> q;
    vector<int> p(q);
    unordered_map<int,int> m;
    rep(i, q) {
        cin >> p[i];
        m[p[i]] = 0;
    }
    vector<vector<int> > s(n+1, vector<int>(n+1, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            s[i+1][j+1] = s[i][j+1] + s[i+1][j] - s[i][j] + d[i][j];


    int ans = 0;
 
    for(int x1 = 0; x1 < n; x1++) {
        for(int y1 = 0; y1 < n; y1++) {
            for(int x2 = x1+1; x2 <= n; x2++) {
                for(int y2 = y1+1; y2 <= n; y2++) {
                    int val = s[y2][x2] - s[y1][x2] - s[y2][x1] + s[y1][x1];
                    int area = abs(y2-y1)*abs(x2-x1);
                    if(m[area] < val) {
                        m[area] = val;
                    }
                }
            }
        }
    }

    rep(i, q) {
        int ans = 1;
        for(int j = 1; j <= p[i]; j++) {
            ans = max(ans, m[j]);
        }
        cout << ans << endl;
    }
}

int main()
{
    solve1();
}

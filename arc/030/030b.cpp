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

void solve1()  {
    int n, x; cin >> n >> x;
    x --;
    vector<int> h(n); 
    vector<int> jw;
    rep(i, n) {
        cin >> h[i];

        if(h[i] == 1) {
            jw.push_back(i);
        }
    }

    int d[n][n];

    rep(i, n) {
        rep(j, n) {
            if(i != j) {
                d[i][j] = INF;
            } else {
                d[i][j] = 0;
            }
        }
    }

    
    rep(i, n-1) {
        int a, b; cin >> a >> b;
        a--; b--;
        d[a][b] = 1;
        d[b][a] = 1;
    }


    for (int k = 0; k < n; k++){       // 経由する頂点
    for (int i = 0; i < n; i++) {    // 始点
      for (int j = 0; j < n; j++) {  // 終点
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }

    int ans = 0;
    if(jw.size() != 0) {
        ans += d[x][jw[0]];
        for(int i = 0; i < (int)jw.size()-1; i++) {
            ans += d[jw[i]][jw[i+1]];
        }

        ans += d[jw[(int)jw.size()-1]][x];
    }

    cout << ans << endl;


}

int main()
{
    solve1();
}

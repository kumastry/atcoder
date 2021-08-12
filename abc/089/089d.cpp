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

void solve1()
{
    int h, w, d; cin >> h >> w >> d;
    vector<vector<int>> a(h, vector<int>(w));
    rep(i, h) {
        rep(j, w) {
            cin >> a[i][j];
        }
    }

    int q; cin >> q;
    vector<int> l(q), r(q);
    int maxr = -1;
    rep(i, q) {
        cin >> l[i] >> r[i];
        maxr = max(maxr, r[i]);
    }

    map<int, P> m;
     rep(i, h) {
        rep(j, w) {
            m[a[i][j]] = make_pair(i+1, j+1);
        }
     }

     map<P, int> sum;
     for(int i = 1; i <= d; i++) {
         int pl = i;
         int pr = i + d;
         ll res = 0;
         while(pr <= maxr) {
             P tmp1 = m[pl];
             P tmp2 = m[pr];

             res += abs(tmp1.fi - tmp2.fi) +
             abs(tmp1.se - tmp2.se);

             sum[make_pair(i, pr)] = res;
            /* cout << i <<',' <<pr <<':'<< res << endl; */
             pr += d;
             pl += d;
         }

     }
  

     for(int i = 0; i < q; i++) {
         if(l[i] == r[i]) {
             cout << 0 << endl;
         } else {
             int pl = l[i]%d;
             if(pl == 0) {
                 pl += d;
             }

             cout << sum[make_pair(pl, r[i])] -  sum[make_pair(pl, l[i])]  << endl;
             /*cout << sum[make_pair(pl, l[i])] << endl;
             cout << sum[make_pair(pl, r[i])] << endl; */

         }
     }
  

     return;
}

int main()
{
    solve1();
}

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
    int x, y, a, b, c; cin >> x >> y >> a >> b >> c;
    vector<ll> p(a), q(b), r(c);

    
    rep(i, a) {
        cin >> p[i];
    }

    rep(i, b) {
        cin >> q[i];
    }

    rep(i, c) {
        cin >> r[i];
    }

    sort(all(p), greater<ll>());
    sort(all(q), greater<ll>());

    ll ans = 0;
    vector<ll> pp(x), qp(y);
    rep(i, x) {
        ans += p[i];
        pp[i] = p[i];
    }

    rep(i, y) {
        ans += q[i];
        qp[i] = q[i];
    }

    sort(all(pp));
    sort(all(qp));
    sort(all(r), greater<ll>());

    int ip = 0;
    int iq = 0;
    rep(i, c) {

        if(ip < (int)pp.size() && iq < (int)qp.size()) {

            if(r[i] - pp[ip] > r[i] - qp[iq]) {
              ans += max(r[i] - pp[ip++], 0LL);
              //cout << "1 ";
          } else {
              ans += max(r[i] - qp[iq++], 0LL);
              //cout << "2 ";
          }

        } else if(ip < (int)pp.size()) {
            ans += max(r[i] - pp[ip++], 0LL);
            //cout << "3 ";
        } else if(iq < (int)qp.size()) {
            ans += max(r[i] - qp[iq++], 0LL);
           // cout << "4 ";
           // cout << "##### " << r[i] << " " << qp[i] << "###### " << endl;
        }

        //cout << r[i] << " " << ans << endl;
    }

   
   
    cout << ans << endl;


}

int main()
{
    solve1();
}

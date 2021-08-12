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

int prime[10000000];
bool is_prime[100000000 + 1];

int sieve(int n ) {
    int pcnt = 0;
    for(int i = 0; i <= n; i++) {
        is_prime[i] = true;
    }

    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i <= n; i++) {
        if(is_prime[i]) {
            prime[pcnt++] = i;
            for(int j = 2*j; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }

    return pcnt;
}


void solve1()
{
    int n, m, r; cin >> n >> m >> r;
    vector<int> R(r); 
    int miv = 1000000;
    int mav = -1;
    rep(i, r) {
        cin >> R[i];

        miv = min(miv, R[i]);
        mav = max(mav, R[i]);
    }

    sort(all(R));

    ll d[210][210];
    for(int i = 0; i < m; i++) {
        ll a, b, c; cin >> a >> b >> c;
        a--; b --;
        d[a][b] = c;
        d[b][a] = c;
    }

    cout << endl;
    rep(i, n) {
        rep(j, n) {
            cout << d[i][j] << " ";
        }
        cout << endl;
    }

     cout << endl; 
     

    for (int k = 0; k < n; k++){       // 経由する頂点
      for (int i = 0; i < n; i++) {    // 始点
        for (int j = 0; j < n; j++) {  // 終点
          d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        }
      } 
    }

      rep(i, n) {
        rep(j, n) {
            cout << d[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl; 
    


    vector<ll> ans;

    do {

        ll dist = 0;
        for(int i = 0; i < r-1; i++) {
            dist += d[R[i]-1][R[i+1]-1];
        }

        ans.push_back(dist);
       /* cout << dist << endl; */


    } while (next_permutation(all(R)));
  /*  rep(i, (int)ans.size()) {
        cout << ans[i] << " ";
    }
    */

    cout << endl;

    sort(all(ans));
    cout << ans[0] << endl;

}

int main()
{
    solve1();
}

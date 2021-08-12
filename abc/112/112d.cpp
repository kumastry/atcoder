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

vector<ll> divs(ll n) {
    vector<ll> res;
    for(int i = 1; i*i <= n; i++) {
        if(n%i == 0) {
            res.push_back(i);
        

          if(i != n/i) {
              res.push_back(n/i);
          }
        }
    }

    sort(all(res));

    return res;
}

void solve1() {
    ll n, m; cin >> n >> m;

    vector<ll> vec = divs(m);

    ll ans = 1;
    for(int i = 0; i < (int)vec.size(); i++) {
        ll bediv = m;
        bediv /= vec[i];
        if(bediv >= n) {
            ans = max(ans, vec[i]);
        } 
    }

    cout << ans << endl;
}

int main()
{
    solve1();
}

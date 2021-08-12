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
    ll n, k; cin >> n >> k;

    vector<vector<ll>> t(n, vector<ll> (n));
    rep(i, n) {
        rep(j, n) {
            cin >> t[i][j];
        }
    }

    vector<int> p(n-1);
    for(int i = 0; i < n-1; i++) {
        p[i] = i + 2;
    }

    int ans = 0;
    ll dis = 0;
    do {
        dis = 0;

        dis += t[0][p[0]-1];
        for(int i = 0; i < n-2; i++) {
            dis += t[p[i]-1][p[i+1]-1];
        }
        dis += t[p[n-2]-1][0];
      
        if(dis == k) {
            ans ++;
        }

    } while(next_permutation(all(p)));

    cout << ans << endl;
}

int main()
{
    solve1();
}

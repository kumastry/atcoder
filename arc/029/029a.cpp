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

void solve1() {
    int n; cin >> n;
    vector<int> t(n);
    rep(i,n) {
        cin >> t[i];
    }

    sort(all(t));
    int ans;
    if(n == 1) {
        ans = t[0];
    } else if(n == 2) {
        ans = max(t[0], t[1]);
    } else if(n == 3) {
        ans = max(t[0]+t[1], t[2]);
    } else {
        ans = max(t[0]+t[3], t[1]+t[2]);
        ans = min(ans, max(t[3], t[1]+t[2]+t[0]));
    }

    cout << ans << endl;
}

int main()
{
    solve1();
}

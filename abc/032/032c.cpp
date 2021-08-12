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
    vector<ll> s(n);

    bool f = false;
    rep(i, n) {
        cin >> s[i];
        if(s[i] == 0) {
            f = true;
        }
    }

    if(f) {
        cout << n << endl;
        return;
    }

    if(k == 0) {
        cout << 0 << endl;
        return;
    }

    ll num = 1;
    int ans = -1;
    int i = 0, j = 0;
    while(i < n && j < n ) {
        num *= s[i++];

        while(j < n && num > k) {
            num /= s[j++];
        }

        ans = max(ans, abs(i-j));
        //cout << num << endl;
    }

    cout << ans << endl;


}

int main()
{
    solve1();
}

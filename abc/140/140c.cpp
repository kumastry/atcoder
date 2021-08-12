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
    int m; cin >> m;
    int n = m-1;
    vector<int> b(n);

    rep(i, n) {
        cin >> b[i];
    }

    if(m == 2) {
        cout << 2*b[0] << endl;
        return;
    } else if(m == 3) {
        cout << 2*b[0] + b[1] << endl;
        return;
    }

    ll ans = 0;
    for(int i = 0; i < n-1; i++) {
        if(i == 0) {
            if(b[i]<b[i+1]) {
                ans += 2*b[i];
            } else{
                ans += b[i] + b[i+1];
            }
        } else if(i != n-2){
            ans += min(b[i], b[i+1]);
        } else {
            if(b[i+1] > b[i]) {
               ans += b[i]+b[i+1];
            } else {
                ans += 2*min(b[i], b[i+1]);
            }
        }

        // cout << ans << endl;
    }

    cout << ans << endl;


}

int main()
{
    solve1();
}

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
typedef long long ll;
#define MOD 1000000007
#define PI 3.1415926535897932
#define INF 1e9
#define rep(i, n) for (int i = 0; i < n; i++)
#define repe(i, j, n) for (int i = j; i < n; i++)
#define repi(i, n) for (int i = 0; i <= n; i++)
#define repie(i, j, n) for (int i = j; i <= n; i++)
#define all(x) x.begin(), x.end()
#define println() cout << endl
#define P pair<ll, ll>
#define fi first
#define se second



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
    int n, m; cin >> n >> m;
    vector<ll> a(min(n, m)), b(max(n, m));

    for(ll i = 0; i < min(n, m); i++) {
        cin >> a[i];
    }

    for(ll i = 0; i < max(n, m); i++) {
        cin >> b[i];
    }

    vector<P> ans;
    ll j = 0;
    ll pre = 0;
    for(ll i = 0;i<min(n, m); i++) {
        
        bool f = false;
        while(j < max(n, m)) {
        if(a[i] == b[j]) {
            ans.push_back(P(a[i], b[j]));
            f = true;
            pre = j;
            break;
        }
        j++;
        }

        if(!f) {
            j = pre;
        }
    }

    int cnt = 0;
    for(int i = 0; i <= ans.size(); i++) {
        if(ans[i].fi != ans[i].se) {
            cnt ++;
        }
        cout << ans[i].fi << " " << ans[i].se << endl;;
    }


    cout << max(n, m)-ans.size() << endl;
    cout << max(n, m)-ans.size() << endl;
    cout << cnt << endl;
}

int main()
{
    solve1();
}

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
using Graph = vector<vector<int>>;

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


ll f(ll n) {
    string num = to_string(n);
    ll ret = 0;
    ll p = 1;
    for(ll i = (ll)num.size()-1; i >= 0; i--) {
        ret += (num[i]-'0')*p;
        p *= n;
    }

    return ret;
}

bool fnc(ll m, ll a) {
    ll num = f(m);
    if(num <= a) {
        return true;
    } else {
        return false;
    }

}


void solve1() {
    ll a; cin >> a;

    ll l = 9;
    ll r = 1e4 + 1;
    while(r - l > 1) {
       // cout << l << " " << r << endl;
        ll mid = (l+r)/2;
        if(fnc(mid, a)) {
            l = mid;
        } else {
            r = mid;
        }

        //cout << l << " " << r << endl;
    }

    if(f(l) == a) {
       cout << l << endl;
    } else {
        cout << -1 << endl;
    }
}

int main()
{
    solve1();
}

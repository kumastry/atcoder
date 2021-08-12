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

ll modinv(ll a, ll m)
{
    ll b = m, u = 1, v = 0;
    while (b)
    {
        ll t = a / b;
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

ll gcd(ll n, ll m) {
    if(n%m) {
        return gcd(m, n%m);
    } else {
        return m;
    }
}

ll lcm(ll n, ll m) {
    return n / gcd(n, m) * m;
}

void solve1() {
    ll n, m; cin >> n >> m;
    string s, t; cin >> s >> t;

    ll lm = lcm(n, m);
    
    ll sn = lm / n;
    ll tm = lm / m;

    map<ll, char> ms;
    map<ll, char> mt;
    ll i = 0;
    ll j = 0;
    while(i < n) {
        ms[j] = s[i++];
        j += sn;
    }

    i = 0, j = 0;
    while(i < m) {
        mt[j] = t[i++];
        j += tm;
    }

    bool f = true;
    if(n >= m) {
        for(auto itr = mt.begin(); itr != mt.end(); itr++) {
            if(ms[itr->first] != '\0' && itr->second != ms[itr->first]) {
                f = false;
            }

            //cout << itr->second << " " << ms[itr->first] << endl;
        }
    } else {
        for(auto itr = ms.begin(); itr != ms.end(); itr++) {
            if(mt[itr->first] != '\0' && itr->second != mt[itr->first]) {
                f = false;
            }

            //cout << itr->second << " " << ms[itr->first] << endl;
        }   
    }

    if(f) {
        cout << lm << endl;
    } else {
        cout << -1 << endl;
    }
}

int main()
{
    solve1();
}

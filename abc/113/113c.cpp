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
#define P pair<ll, ll>
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
int sieve(int n) {
    int pcnt = 0;
    for(int i = 0; i <= n; i++) {
        is_prime[i] = true;
    }

    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i <= n; i++) {
        if(is_prime[i]) {
            prime[pcnt++] = i;
            for(int j = 2*i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }

    return pcnt;
}

void solve1()
{
    ll n, m; cin >> n >> m;
    vector<P> p(m);
    vector<ll> com(n+1);
    set<ll> s;
    map<P, ll> mp;
    map<ll, ll> t;
    for(ll i = 0; i < m; i++) {
        cin >> p[i].fi >> p[i].se;
        s.insert(p[i].se);
        t[p[i].se] = i;
    }

    com[0] = 0;
    for(int i = 1; i <= n; i++) {
        com[i] = 1;
    }

    ll cnt = 1;
    for(auto itr = s.begin(); itr != s.end(); itr++) {
        ll idx = t[*itr];
        mp[P(p[idx].fi, *itr)] = com[p[idx].fi]++;
    }

    rep(i, m) {
        int l = (int)to_string(p[i].fi).size();
        int r = (int)to_string(mp[P(p[i].fi, p[i].se)]).size();
        for(int i = 0; i < 6-l; i++) {
            cout << '0';
        }
        cout << p[i].fi;
        for(int i = 0; i < 6-r; i++) {
            cout << '0';
        }
        cout << mp[P(p[i].fi, p[i].se)] << endl;
    }




}

int main()
{
    solve1();
}

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

bool f(set<char> s, char c) {
    if(s.find(c) != s.end()) {
        return true;
    } else {
        return false;
    }
}

void solve1() {
    string s; cin >> s;
    set<char> st;
    rep(i, (int)s.size()) {
        st.insert(s[i]);
    }

    if(f(st, 'S') && f(st, 'E') && f(st, 'N') && f(st, 'W')) {
        cout << "Yes" << endl;
    } else if(f(st, 'S') && f(st, 'N') && !f(st, 'W') && !f(st, 'E')) {
        cout << "Yes" << endl;
    } else if(f(st, 'E') && f(st, 'W') && !f(st, 'N') && !f(st, 'S')) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    
}

int main()
{
    solve1();
}

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
    string s, t; cin >> s >> t;

    map<char, char> m, n;
    for(int i = 0; i < (int)s.size(); i++) {
        m[t[i]] = '1';
        n[s[i]] = '1';
    }

    for(int i = 0; i < (int)s.size(); i++) {
        if(m[t[i]] == '1') {
            m[t[i]] = s[i];
            //cerr << 1 << endl;
        } else {
            if(m[t[i]] != s[i]) {
                cout << "No" << endl;
                return;
            }
        }


        if(n[s[i]] == '1') {
            n[s[i]] = t[i];
            //cerr << 1 << endl;
        } else {
            if(n[s[i]] != t[i]) {
                cout << "No" << endl;
                return;
            }
        }
    }

    cout << "Yes" << endl;
}

int main()
{
    solve1();
}

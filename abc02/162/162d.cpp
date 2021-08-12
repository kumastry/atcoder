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
#include <unordered_map>

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
    ll n; cin >> n;
    string s; cin >> s;
    ll num = 1;
    map<ll, ll> m;
    rep(i, s.size()) {
        m[s[i]]++;
    }

    num *= m['R']*m['B']*m['G'];
  //cout << num << endl;
    for(int t = 1; t < n; t++) {
        for(int i = 0; i < n; i++) {
            int j = t + i;
            int k = j + t;

            if(i < n && j < n && k < n) {
                if(s[i]!=s[j] && s[j]!=s[k] && s[k]!=s[i])
                    num--;
                //cout << i << " " << j << " " << k << endl;
            }
        }
    }

    cout << num << endl;



}

int main()
{
    solve1();
}

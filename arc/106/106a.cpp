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

void solve1()
{
    ll n; cin >> n;

    ll ansa = -1, ansb = -1;
    bool f = false;
    for(ll i = 1; i <= 37; i++) {

 

        for(ll j = 1; j <= 25; j++) {
            if(ll(pow(3, i) + pow(5, j)) == n) {
                ansa = i;
                ansb = j;
                f = true;
            }
        }

    }
 

    if(f) {
        cout << ansa << " " << ansb << endl;
    } else {
        cout << -1 << endl;
    }
}

int main()
{
    solve1();
}

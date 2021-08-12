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

ll divs(ll n) {
    ll res = 0;
    for(ll i = 1; i * i <= n; i++) {
        if(n%i == 0) {
            res += i;
            if(i != n/i) {
                res += n/i;
            }
        }
    }

    res -= n;
    return res;
}

void solve1() {
    ll n; cin >> n;

    ll sum = divs(n);
    if(sum > n) {
        cout << "Abundant" << endl;
    } else if(sum < n) {
        cout << "Deficient" << endl;
    } else {
        cout << "Perfect" << endl;
    }
}

int main()
{
    solve1();
}

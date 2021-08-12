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

bool func(int mid, int k, int a) {
    if(k*mid - a > 0) {
        return true;
    } else {
        return false;
    }
}

void solve1() {
    int n, k; cin >> n >> k;
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
     int a = i;
     int r = ceil(2.0*n / k);
     int l = 0;
     while(r - l > 1) {
         int mid = (r+l)/2;
         if(func(mid, k, a)) {
             r = mid;
         } else {
             l = mid;
         }
     } 

     //cout << i << ":" << r  << ":" << k*r - a << endl;
     int b = k*r-a;
     int c = b;
     //cout << "(a, b, c) = " << a << " " << b << " "  << c << endl;
     if( (a + b) % k == 0 && (b + c) % k == 0 && (c + a) % k == 0) { 
        ll j = (n-b)/k + 1;
       //cout << "### " << j << endl;
        ans += j*j;
     }

    }

    cout << ans << endl;
}

int main()
{
    solve1();
}

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
    int n; cin >> n;
    vector<int> x(n), y(n);
    vector<int> p(n);
    
    rep(i, n) {
        cin >> x[i] >> y[i];
        p[i] = i;
    }

    double ans = 0;
    int div = 0;
    do {
        double d = 0;
        for(int i = 0; i < n-1; i++) {
             ans += sqrt( (x[p[i]]-x[p[i+1]])*(x[p[i]]-x[p[i+1]]) + (y[p[i]]-y[p[i+1]])*(y[p[i]]-y[p[i+1]]) );
        }

        

        div ++;
    }while(next_permutation(all(p)));

    cout << fixed << setprecision(15) << ans / div << endl;
}

int main()
{
    solve1();
}

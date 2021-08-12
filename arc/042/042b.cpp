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


void solve1()  {
    int n, m; cin >> n >> m;
    int num; cin >> num;
    vector<int> x(num), y(num);
    rep(i, num) {
        cin >> x[i] >> y[i];
    }

    double ans = 1000000000;

    for(int i = 0; i < num-1; i++) {
        double dist;
        if(y[i] == y[i+1] && x[i] == x[i+1]) {
            continue;
        } else if(y[i] == y[i+1]) {
            dist = abs(y[i]-m);
        } else if(x[i] == x[i+1]) {
            dist = abs(y[i]-n);
        } else {
            double a = (1.0*(y[i+1]-y[i]));
            double b = (1.0*(x[i]-x[i+1]));
            double c = x[i+1]*y[i]-x[i]*y[i+1];
            dist = abs(a*n + b*m + c) / sqrt(a*a + b*b); 
        }

        ans = min(ans, dist);


    }

    double dist;

     if(y[0] != y[num-1] || x[0] != x[num-1]) {

        if(y[0] == y[num-1]) {
            dist = abs(y[0]-m);
        } else if(x[0] == x[num-1]) {
            dist = abs(x[0]-n);
        } else { 
           double a = (1.0*(y[0]-y[num-1]));
           double b = (1.0*(x[num-1]-x[0]));
           double c = x[0]*y[num-1]-x[num-1]*y[0];
           dist = abs(a*n + b*m + c) / sqrt(a*a + b*b);
        }

     }

    ans = min(ans, dist);
    cout << fixed << setprecision(12) <<ans << endl;
}

int main()
{
    solve1();
}

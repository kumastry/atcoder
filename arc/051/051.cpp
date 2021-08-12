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

bool inc(int x1, int y1, int r, int x, int y) {
    int dist =  (x1-x)*(x1-x) + (y1-y)*(y1-y);

    if(dist > r*r) {
        return false;
    } else {
        return true;
    }
}

void solve1() {
    int x1, y1, r; cin >> x1 >> y1 >> r;
    int x2, y2, x3, y3; cin >> x2 >> y2 >> x3 >> y3;
    int h = abs(y2-y3);
    int w = abs(x2-x3);

    if(x2 <= x1 - r && x3 >= x1 + r && y2 <= y1 - r && y3 >= y1 +r) {
        cout << "NO" << endl;
        cout << "YES" << endl;
        
    } else if(inc(x1, y1, r, x2, y2) && inc(x1, y1, r, x3, y3) && inc(x1, y1, r, x2, y3) && inc(x1, y1, r, x3, y2)){
        cout << "YES" << endl;
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        cout << "YES" << endl;
    }

}

int main()
{
    solve1();
}

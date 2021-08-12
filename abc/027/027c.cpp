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
using Graph = vector<vector<int>>;

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
    ll r = n;
    ll l = n / 2 + 1;
    cout << l << " " << r << endl;
    int cnt = 0;
    while(1) {

        if(l <= 1) {
            break;
        }

        r /= 2;
        l /= 2;
        cnt ++;
        cout << l << " " << r << endl;
    }

    cout << cnt << endl;
    if(r == 1) {
        if(cnt % 2) {
            cout << "Takahashi" << endl;
        } else {
            cout << "Aoki" << endl;
        }
        
    } else {
        if(cnt % 2) {
            cout << "Aoki" << endl;
        } else {
            cout << "Takahashi" << endl;
        }
        
    }
}

int main()
{
    solve1();
}

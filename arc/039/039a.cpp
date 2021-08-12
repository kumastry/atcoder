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

void solve1() {
    string a, b; cin >> a >> b;
    string aa, bb;
    cout << a[0] << endl;
    int ans = -1000;
    rep(i, 3) {
        int score;
        aa = a;
        aa[i] = 9;
        rep(j, 3) {
            bb = b;
            if(j == 0) {
                bb[j] = 1;
            } else {
                bb[j] = 0;
            }

            score = 100*(aa[0]-'0') + 10*(aa[1]-'0') + (aa[2]-'0');
            score -= 100*(bb[0]-'0') + 10*(bb[1]-'0') + (bb[2]-'0');

            ans = max(ans, score);
        }
    }

    cout << ans << endl;
}

int main()
{
    solve1();
}

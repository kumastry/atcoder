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
    string s; cin >> s;
    int wc = 0, bc = 0;
    rep(i, n) {
        if(s[i] == '.') {
            wc ++;
        } else {
            bc ++;
        }
    }

    vector<int> sumw(n+1);
    vector<int> sumb(n+1);
    sumw[0] = 0;
    sumb[0] = 0;

    for(int i = 0; i < n; i++) {
        if(s[i] == '.') {
            sumw[i+1] = sumw[i] + 1;
            sumb[i+1] = sumb[i];
        } else {
            sumw[i+1] = sumw[i];
            sumb[i+1] = sumb[i] + 1;
        }
    }


    int ans = 1e7;
    for(int i = 0; i < n+1; i++) {
        int num = sumb[i] + sumw[n] - sumw[i];
        ans = min(num, ans);
    }

    cout << ans << endl;

}

int main()
{
    solve1();
}

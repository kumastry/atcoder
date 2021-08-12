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
    int n, d, k; cin >> n >> d >> k;
    vector<int> l(d), r(d);
    rep(i, d) {
        cin >> l[i] >> r[i];
    }

    vector<int> s(k), t(k);
    rep(i, k) {
        cin >> s[i] >> t[i];
    }

    for(int i = 0; i < k; i++) {
        bool f;
        if(s[i] < t[i]) {
            f = true;
        } else {
            f = false;
        }

        int ans = 0;
        if(f) {

            rep(j, d) {
                if(s[i] >= l[j] && s[i] <= r[j]) {
                    s[i] = r[j];
                }

                if(s[i] >= t[i]) {
                    cout << j + 1 << endl;
                    break;
                }
            }

        } else {

            rep(j, d) {
                if(s[i] >= l[j] && s[i] <= r[j]) {
                    s[i] = l[j];
                }

                if(s[i] <= t[i]) {
                    cout << j + 1 << endl;
                    break;
                }
            }

        }
    }


}

int main()
{
    solve1();
}

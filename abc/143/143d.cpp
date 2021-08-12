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
    vector<int> l(n);
    int maxv = -1;
    int minv = 100000;
    map<int, int> m;
    rep(i, n) {
        cin >> l[i];
        m[l[i]]++;
        maxv = max(maxv, l[i]);
        minv = min(minv, l[i]);
    }

    sort(all(l));
    vector<int> sum(5010);
    sum[0] = m[0];
    for(int i = 1; i <= 5000; i++) {
        sum[i] = m[i] + sum[i-1];
    }

    ll ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int m = abs(l[i]-l[j]);
            int n = l[i]+l[j];
            ans += sum[n-1]-sum[m];

            if(l[i] > m && l[i] < n) {
                ans --;
            }

            if(l[j] > m && l[j] < n) {
                ans --;
            }

           
        }
    }

    cout << ans/3 << endl;
}

bool bi(int n, int fi, int se) {
    if(abs(fi - se) > n && n < fi + se) {
        return true;
    }

    return false;
}

void solve2() {
    int n; cin >> n;
    vector<int> l(n);
    rep(i, n) {
        cin >> l[i];
    }

    sort(all(l));
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int rr = n-1;
            int ll = 0;
            for(int k = 0; k < 100; k++) {
                int mid = (rr+ll) / 2;

                if(bi(l[mid], l[i],  l[j])) {

                } 
            }
        }
    }
}

int main()
{
    //solve1();
    solve2();
}

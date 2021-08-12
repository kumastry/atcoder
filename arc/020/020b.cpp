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
    int n, c; cin >> n >> c;
    vector<int> as(n);

    rep(i, n) {
        cin >> as[i];
    }

    ll ans = 1e18;
    for(int i = 1; i <= 10; i++) {
        for(int j =1 ; j <= 10; j++) {
            if(i != j) {
                ll tmp = 0;
                vector<int> a(as);
                for(int k = 0; k < n-1; k++) {
                    if(k%2 == 0) {
                        if(a[k] != i) {
                            tmp += c;
                            a[k] = i;
                        }

                        if(a[k+1] != j) {
                            tmp += c;
                            a[k+1] = j;
                        }
                    } else {
                        if(a[k] != j) {
                            tmp += c;
                            a[k] = j;
                        }

                        if(a[k+1] != i) {
                            tmp += c;
                            a[k+1] = i;
                        }
                    }
                }

                ans = min(ans, tmp);

            }
        }
    }

    cout << ans << endl;
}

int main()
{
    solve1();
}

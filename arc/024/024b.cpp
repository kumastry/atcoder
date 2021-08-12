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
    vector<int> a(n);

    rep(i, n) {
        cin >> a[i];
    }

    int s = a[0];

    int start = -1;
    for(int i = 0; i < n; i++) {
        if(a[i] != s) {
            start = i;
            s = a[i];
            break;
        }
    }

    if(start == -1) {
        cout << -1 << endl;
    } else {
        int ans = 1;
        int i = start;
        int cnt = 0;
        do {
            //cout << "idx:" << i << endl;
            if(a[i] == s) {
                cnt ++;
            } else {
                //cout << cnt << endl;
                if(cnt%2 == 0) {
                    cnt --;
                } 

                ans = max(ans, cnt/2 + 1);
                cnt = 1;
                if(s == 1) {
                    s = 0;
                } else {
                    s = 1;
                }
            }

            i++;

            if(i > n-1) {
                i = 0;
            }

            if(i == start) {
                //cout << cnt << endl;
                if(cnt%2 == 0) {
                    cnt --;
                } 

                ans = max(ans, cnt/2 + 1);
            }

        } while(i != start);


        cout << ans << endl;
    }
}

int main()
{
    solve1();
}

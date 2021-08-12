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
    int n, k; cin >> n >> k;
    vector<vector<int> > t(5, vector<int>(5));
     rep(i, 5) {
        rep(j, 5) {
            t[i][j] = 0;
        }    
    }

    rep(i, n) {
        rep(j, k) {
            int a;
            cin >> a;
            t[i][j] = a;
          
        }

        
    }

    
    string ans = "Nothing";
    rep(i, k) {
        int val1 = t[0][i];
        rep(j, k) {
            int val2 =  val1 ^ t[1][j];
            rep(l, k) {
               int val3 =  val2 ^ t[2][l];
                rep(m, k) {
                    int val4 =  val3 ^ t[3][m];
                    rep(u, k) {
                        int val5 =  val4 ^ t[4][u];

                        if(val5 == 0) {
                            ans = "Found";
                            goto la;
                        }
                    }
                }
            }
        }
    }

    la:

    cout << ans << endl;
}

int main()
{
    solve1();
}

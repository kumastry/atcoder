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

void solve1()
{
    vector<vector<int>> c(3, vector<int>(3));

    ll sum = 0;
    rep(i, 3) {
        rep(j, 3) {
            cin >> c[i][j];
        }
    }

    vector<vector<int>> b(3, vector<int>(3));
    rep(i, 101) {
        rep(j, 101) {
            rep(k, 101) {
                int idx;
                rep(l, 3) {
                rep(m, 3) {
                    if(l == 0) {
                        idx = i;
                    } else if(l == 1) {
                        idx = j;
                    } else {
                        idx = k;
                    }

                    b[l][m] = c[l][m]-idx;
                }
                }

                bool f1 = b[0][0] == b[1][0] && b[1][0] == b[2][0];
                bool f2 = b[0][1] == b[1][1] && b[1][1] == b[2][1];
                bool f3 = b[0][2] == b[1][2] && b[1][2] == b[2][2];
                /*if(i == 0 && j == 1 && k == 0) {
                    cout << b[0][0] << " " << b[0][1] << " "<<  b[0][2] << endl;
                    cout << b[1][0] << " " << b[1][1] << " "<< b[1][2] << endl;
                    cout << b[2][0] << " " << b[2][1] << " " << b[2][2] << endl;
                }*/
                if(f1 && f2 && f3) {
                    cout << "Yes" << endl;
                    return;
                }
            }
        }
    }

    cout << "No" << endl;
  
}

int main()
{
    solve1();
}

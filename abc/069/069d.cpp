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

int prime[10000000];
bool is_prime[100000000 + 1];

int sieve(int n ) {
    int pcnt = 0;
    for(int i = 0; i <= n; i++) {
        is_prime[i] = true;
    }

    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i <= n; i++) {
        if(is_prime[i]) {
            prime[pcnt++] = i;
            for(int j = 2*j; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }

    return pcnt;
}

void solve1()
{
    int h, w; cin >> h >> w;

    int n; cin >> n;
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
    }

    vector<vector<int>> c(h, vector<int>(w));

    int lim = 0; 
    int cl = 1;
    int index = 0;
    for(int i = 0; i < h; i++) {
    
        if(i%2 == 0) {
            for(int j = 0; j < w; j++) {
                c[i][j] = cl;
                lim ++;
                if(lim == a[index]) {
                    cl ++;
                    index ++;
                    lim = 0;
                }

               /* cout << i << " " << j << endl; */
            }
        } else {
            for(int j = w-1; j >= 0; j--)  {
                c[i][j] = cl;
                lim ++;
                if(lim == a[index]) {
                    cl ++;
                    index ++;
                    lim = 0;
                }

                 /*cout << i << " " << j << endl; */
            }
        }

    }

    rep(i, h) {
        rep(j, w) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    solve1();
}

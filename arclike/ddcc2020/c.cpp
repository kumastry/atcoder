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

#define MOD 998244353
#define PI 3.1415926535897932
#define INF 1e9
#define rep(i, n) for (int i = 0; i < n; i++)
#define repe(i, j, n) for (int i = j; i < n; i++)
#define repi(i, n) for (int i = 0; i <= n; i++)
#define repie(i, j, n) for (int i = j; i <= n; i++)
#define all(x) x.begin(), x.end()
#define println() cout << endl
#define P pair<ll, ll>
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
    int h, w, k; cin >> h >> w >> k;
    vector<vector<char>> s(h, vector<char>(w));

    rep(i, h) {
        rep(j, w) {
            cin >> s[i][j];
        }
    }

    int cnt = 1;
    int hit = 0;
    for(int i = 0; i < h; i++) {
        if(i%2 == 0) {
            for(int j = 0; j < w; j++) {
                if(s[i][j] == '#') {
                    hit ++;
                }

                if(hit == 2) {
                    cnt ++;
                    hit = 0;
                }
                cout << cnt << " ";
            }

            cnt++;
        } else {
            for(int j = w-1; j >= 0; j--) {

            }
        }
    }

}


int main()
{
    solve1();
}

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
    int h, w; cin >> h >> w;

    vector<vector<char>> s(h, vector<char>(w));

    rep(i, h) {
        rep(j, w) {
            cin >> s[i][j];
        }
    }

    int dp[h+1][w+1];
    dp[0][0] = 0;
    for(int i = 0; i <= w; i++) {
        dp[0][i] = 0;
    }

    for(int i = 0; i <= h; i++) {
        dp[i][0] = 0;
    }

    bool f = true;
    int cnt = 0;
    for(int i = 1; i <= w; i++) {
        if(s[0][i-1] == '#') {
            f = false;
        }

        if(f) {
            dp[1][i] = cnt;
            cnt ++; 
        } else {
            dp[1][i] = 0;
        }
    }

    bool f = true;
    cnt = 0;
    for(int i = 1; i <= h; i++) {
        if(s[i-1][0] == '#') {
            f = false;
        }

        if(f) {
            dp[i][1] = cnt;
            cnt ++; 
        } else {
            dp[i][1] = 0;
        }
    }

    dp[1][1] = 1;

    for(int i = 2; i <= h; i++) {
        for(int j = 2; j <= w; j++) {
            
        }
    }
}

int main()
{
    solve1();
}

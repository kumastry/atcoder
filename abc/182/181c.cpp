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
    string s; cin >> s;
    int n = (int)s.size();
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += s[i] - '0';
    }

    int ans = 20;
     for (int bit = 0; bit < (1<<n); ++bit) {
        vector<int> S;
        int val = sum;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (bit & (1<<i)) { // 列挙に i が含まれるか
                val -= s[i] - '0';
                cnt ++;
            }
        }

        if(val%3 == 0) {
          ans = min(ans, cnt);
        }
        
    }

    if(ans == n) {
        ans = -1;
    }

    cout << ans << endl;
}

int main()
{
    solve1();
}

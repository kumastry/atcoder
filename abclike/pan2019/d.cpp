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
    int n;
    cin >> n;
    string s; cin >> s;

    map<char, vector<int> >sum;
    sum['0'][0] = 0;
    sum['1'][0] = 0;
    sum['2'][0] = 0;
    sum['3'][0] = 0;
    sum['4'][0] = 0;
    sum['5'][0] = 0;
    sum['6'][0] = 0;
    sum['7'][0] = 0;
    sum['8'][0] = 0;
    sum['9'][0] = 0;
    for(int i = 0; i < n; i++) {
        for(int j = '1'; j <= '9'; j++) {
            if(char(j) == s[i]) {
                sum[s[i]][i+1] = sum[s[i]][i] + 1;
            } else {
                sum[s[i]][i+1] = sum[s[i]][i];
            }
        }
    }

    ll ans = 0;
}

int main()
{
    solve1();
}

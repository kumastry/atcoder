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
using Graph = vector<vector<int>>;

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
    string s; cin >> s;

    bool f = true;
    for(int i = 0; i < n; i++) {
        if(i != 0) {
            if(s[i] == 'R' && s[i-1] == 'W') {
                f = false;
                break;
            }
        }
    }

    if(f) {
        cout << 0 << endl;
    } else {
        int ans1 = 0;
        int ans2 = 0;
        int ans3 = 0;
        rep(i, n) {
            if(s[i] =='W') {
                ans1 ++;
            } else {
                ans3++;
            }
        }



        int r = n-1;
        int l = 0;
        while(l < r) {
            while(s[l] == 'R') {
                l ++;
            }

            while(s[r] == 'W') {
                r--;
            }

            if(l < r) {
               swap(s[r], s[l]);
               r--;
               l++;
               ans2 ++;
            }
        }

        cout << min({ans1, ans2, ans3}) << endl;
        //cout << s << endl;
    }
}

int main()
{
    solve1();
}

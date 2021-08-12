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

ll modinv(ll a, ll m)
{
    ll b = m, u = 1, v = 0;
    while (b)
    {
        ll t = a / b;
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
    ll num; cin >> num;
    string s = to_string(num);
    int n = (int)s.size();

    int ans1 = 0;
    int ans2 = 0;
    for(int i = 0; i < n; i++) {
        ans2 += s[i]-'0';
    }


    ans1 = 9*(n-1) + s[0]-'0' - 1;

    ll tmp = num;
    int ans3 = -1;
    for(int i = 0; i < 10; i++) {
        string t = to_string(tmp);
        int cnt = 0;
        for(int j = 0; j < (int)t.size(); j++) {
             cnt += t[j]-'0';
        }

        ans3 = max(ans3, cnt);
        tmp--;

        if(tmp <= 0) {
            break;
        }
    }

    cout << max({ans1, ans2, ans3}) << endl;
    //cerr << ans1 << " " << ans2 << " " << ans3 << endl;

}

int main()
{
    solve1();
}

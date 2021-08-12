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
    int n; cin >> n;
    string s, t; cin >> s >> t;

    string ans;
    bool f = false;
    for(int i = 0 ; i < n; i++) {
        string str1 = s.substr(i);
        string str2 = t.substr(0, n-i);

        //cout << "### " << str1 << " " << str2 << endl;
        if(str1 == str2) {
            f = true;
            ans = s.substr(0, i) + str1 + t.substr((int)str1.size());
           // cout << str1 << endl;
            //cout << "&&& " << s.substr(0, i) << str1;
           // cout << t.substr((int)str1.size()) << endl;
            break;
        }
    }

    if(f) {
        cout << ans.size() << endl;
    } else {
        cout << (s+t).size() << endl;
    }
}

int main()
{
    solve1();
}

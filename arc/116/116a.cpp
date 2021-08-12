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
#include <unordered_map>
#include <unordered_set>
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
using Graph = vector<vector<ll>>;


void solve1() {
    ll n; cin >> n;
    vector<ll> c(n);
    rep(i, n) {
        cin >> c[i];
    }

    rep(i, n) {
        ll ev = 0, od = 0;
        ll num = c[i];
        ll cnt = 0;
        while(num%2==0) {e12    わ
            cnt ++;
            num /= 2;
        }

        if(cnt > 1) {
            cout << "Even" << endl;
        } else if(cnt == 1) {
            cout << "Same" << endl;
        } else {
            cout << "Odd" << endl;
        }
    }
}

int main()
{
    solve1();
}

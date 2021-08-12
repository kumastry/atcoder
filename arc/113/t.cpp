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
    string s, t; cin >> s >> t;
    int n = (int)s.size();
    if(s == t) {
        cout << 0 << endl;
        return;
    }

    if((int)s.size() != (int)t.size()) {
        cout << -1 << endl;
        return;
    }

    ll ans = 0;
    rep(i, n) {
        string p = s.substr(n-1);
        s.erase(n-1);
        s.insert(0, p);

        if(s == t) {
            cout << i + 1 << endl;
            return;
        }
    }

    cout << -1 << endl;
}

int main()
{
    solve1();
}

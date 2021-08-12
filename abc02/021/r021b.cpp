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
#define INF 1e18
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

void solve1() {
    int n, a, b, k; cin >> n >> a >> b >> k;
    set<int> p;
    rep(i, k) {
        int d; cin >> d;
        p.insert(d);
    }

    if(p.size() != k || p.find(a) != p.end() || p.find(b) != p.end()) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }


}

int main()
{
    solve1();
}

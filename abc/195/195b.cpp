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


void solve1() {
    ll a, b, w; cin >> a >> b >> w;
    w *= 1000;
    ll diff = abs(a-b);

    if(w%b == 0 && w%a == 0) {
        cout << w/b << " " << w/a << endl;
    } else {
        ll wa = w%a, wb = w%b;
        ll sm = ceil(1.0*w/b);
        ll big = w/a;
        if(sm > big) {
            cout << "UNSATISFIABLE" << endl;
            return;
        }
        cout << sm << " " << big << endl;
    }
    
}

int main()
{
    solve1();
}

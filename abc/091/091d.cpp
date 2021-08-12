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


bool f2(P a, P b) {
    if(a.se == b.se) {
        return a.fi < b.fi;
    } else {
        return a.se > b.se; 
    }
}


void solve1() {
    int n; cin >> n;
    vector<P> ab(n);
    vector<pair<P, bool>>cd(n);
    rep(i, n) {
        cin >> ab[i].fi >> ab[i].se;
    }

    rep(i, n) {
        cin >> cd[i].fi.fi >> cd[i].fi.se;
        cd[i].se = true;
    }

    sort(all(ab), f2); sort(all(cd));

    ll ans1 = 0;

  
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(cd[j].se && ab[i].fi < cd[j].fi.fi && ab[i].se < cd[j].fi.se) {
                ans1 ++;
                cd[j].se = false;
                break;
            }
        }
    }

    cout << ans1 << endl;
}

int main()
{
    solve1();
}

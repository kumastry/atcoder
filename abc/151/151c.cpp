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



void solve1() {
    int n, m; cin >> n >> m;
    vector<pair<ll, string>> ps(m);
    vector<pair<bool, ll>> fs(n, pair<bool, ll>(false, 0));
    rep(i, m) {
        cin >> ps[i].fi >> ps[i].se;
    }

    ll ac = 0, wa = 0;
    rep(i, m) {
        if(ps[i].se == "AC") {
            fs[ps[i].fi-1].fi = true;
        } 

        if(!fs[ps[i].fi-1].fi && ps[i].se == "WA") {
            fs[ps[i].fi-1].se++;
        }
    }

    
    rep(i, n) {
        if(fs[i].fi) {
            ac ++;
            wa += fs[i].se;
        }
    }

    cout << ac << " " << wa << endl;

}

int main()
{
    solve1();
}

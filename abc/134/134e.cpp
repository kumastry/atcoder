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
#include <tuple>

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
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i, n) {
        cin >> a[i];
    }

    int ans = 0;
    vector<ll> p(a);
    while(1) {
        ll num = p[0];
        vector<ll> tmp;
        if(p.size() <= 1) {
            ans += p.size();
            cout << ans << endl;
            return;
        }
        for(int j = 1; j < (int)p.size(); j++) {
            if(num >= p[j]) {
                tmp.push_back(p[j]);
            }
        }

        ans ++;
        p = tmp;

        //cout <<  ans << " " << p.size() << endl;
    }
}

int main()
{
    solve1();
}

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

#define fi first
#define se second
typedef long long ll;
using Graph = vector<vector<ll>>;
#define P pair<ll, ll>


void solve1() {
    ll k; cin >> k;
    ll ans = 0;

    set<tuple<int , int , int>> s;
    for(int i = 1; i * i * i <= k; i++) {
        ll ki = k/i;
        for(int j = 1; j * j <= ki; j++) {
            ll kij = k/i/j;
                for(int m = 1; m <= kij; m++) {
                    if(i <= j && j <= m) {

                    } else {
                        continue;
                    }

                    if(i == j && j == m) {
                        ans ++;
                    } else if(!(i == j || j == m || m == i)) {
                        ans += 6;
                    } else {
                        ans += 3;
                    }

                }
            }
    }

  


    cout << ans << endl;
   
}

int main()
{
    solve1();
}

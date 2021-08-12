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
using Graph = vector<vector<int>>;

typedef long long ll;


ll n,k;
vector<vector<ll>> t;

bool dfs(ll q, ll v) {
    if(q == n) return (v == 0);
    for(int i = 0; i < k; i++) {
        if(dfs(q+1, v^t[q][i])) return true;
    }

    return false;
}

void solve1() {
    cin >> n >> k;
    t.resize(n, vector<ll>(k));
    rep(i,n) {
        rep(j,k) { 
            cin >> t[i][j];
        }
    }

    if(dfs(0, 0)) {
        cout << "Found" << endl;
    } else {
        cout << "Nothing" << endl;
    }
}

int main()
{
    solve1();
}

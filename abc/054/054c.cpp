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

using G = vector<vector<int>>;

bool pass(G g, vector<int> perm) {
    for(int i = 0; i < (int)perm.size()-1; i++) {
        int cur = perm[i];

        bool f = false;
        for(int j = 0; j < (int)g[cur].size(); j++) {
            if(perm[i+1] == g[cur][j]) {
                f = true;
            }
        }

        if(!f) {
            return false;
        } 
    }

    return true;
}

void solve1() {
    int n, m; cin >> n >> m;

    G g(n);
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> perm(n);
    for(int i = 0; i < n;i ++) {
        perm[i] = i;
    }

    ll ans = 0;

    do{

        if(pass(g, perm)) {
            ans ++;
            /*rep(i, n) {
                cout << perm[i] + 1 << " ";
            }
            cout << endl; */
        }
       
    } while (next_permutation(perm.begin() + 1, perm.end()));

    cout << ans << endl;
    
}

int main()
{
    solve1();
}

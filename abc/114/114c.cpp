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

vector<ll> t;
set<ll> al;
void dfs(string s, char c, int c3, int c5, int c7) {
    if(c3 > 7 || c5 > 7 || c7 > 7) {
        return;
    }

    if(c != 's') 
       s += c;

    sort(all(s));

    do {
        ll num = stoll(s);
        if(al.find(num) == al.end()) {
            al.insert(num);
            t.push_back(num);
        }
    } while(next_permutation(all(s)));

    dfs(s, '3', ++c3, c5, c7);
    dfs(s, '5', c3, ++c5, c7);
    dfs(s, '7', c3, c5, ++c7);
}

void solve1() {
    ll n; cin >> n;

    string s = "375";
    int c3 = 1;
    int c5 = 1;
    int c7 = 1;
    dfs(s, 's', c3, c5, c7);

    sort(all(t));
    ll ans = 0;
    for(int i = 0; i < (int)t.size(); i++) {
        if(t[i] <= n) {
            ans ++;
            //cout << t[i] << " ";
        } else {
            break;
        }
    }

    //cout << endl;

    cout << ans << endl;
}

int main()
{
    solve1();
}

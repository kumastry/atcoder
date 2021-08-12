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


void solve1() {
    ll n; cin >> n;
    vector<ll> a(n);
    set<ll> st;
    rep(i, n) {
        cin >> a[i];
        st.insert(a[i]);
    }

    for(int i = 0; i < n; i++) {
        ll num = 2*a[i];
        while(num <= 1000000005) {
            if(st.find(num) != st.end()) {
                st.erase(num);
            }

            num *= 2; 
        }
    }

    cout << st.size() << endl;

}

int main()
{
    solve1();
}

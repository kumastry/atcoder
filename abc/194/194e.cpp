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
using Graph = vector<vector<ll>>;



void solve1() {
    ll n, m; cin >> n >> m;
    vector<ll> a(n);
    rep(i, n) {
        cin >> a[i];
    }

    multiset<ll> s;
    rep(i, m) {
        s.insert(a[i]);
    }

    ll ans = 0;
    for(int i = 0; i <= 2000000; i++) {
        if(s.find(i)==s.end()) {
            ans = i;
            break;
        }
    }


    for(int i = 0; i < n-m+1; i++) {
        if(i != 0) {
            s.insert(a[i+m-1]);
            s.erase(s.find(a[i-1]));

           

            if(s.find(a[i-1]) == s.end()) {
                ans = min(ans, a[i-1]);
                //cout << "####"<<i <<" " << a[i] << endl;
            } 

      
        }

         //cout << a[i] << " " << a[i+m-1] << endl;

       // cout << ans << endl;

    }

    cout << ans << endl;
    

}

int main()
{
    solve1();
}

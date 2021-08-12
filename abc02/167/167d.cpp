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
#include <unordered_map>

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
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    vector<ll> t(n+1);
    rep(i, n) {
        cin >> a[i];
    } 

    /*テーブルの構築*/
    t[1] = a[0];
    ll s = t[1];
    for(ll i = 0; i < n; i++) {
        t[s] = a[s-1];
        s = a[s-1];
    }

    set<ll> ex;
    s = 1;
    ll loop = 0;
    ll one = 0;
    ll onenum;
    while(1) {
        ll num = s;
        //cout << s << ":" << num << endl;
        if(ex.find(num) == ex.end()) {
            ex.insert(num);
        } else {
            onenum = num;
            break;
        }
        s = t[s];
        loop++;
    }

    //cout << "loop " << loop << endl;
    

    s = 1;
    while(s != onenum) {
        s = t[s];
        one++;
    }

    //cout << "pre " << loop -one << endl;

    //cout << k << endl;

    //cout << k << endl;
    loop -= one;
    k %= loop;
    s = onenum; 
    for(ll i = 0; i < k; i++) {
        //cout << i+1 << ":" << s << endl;
       s = t[s];
    }

    cout << one << endl;
    cout << onenum << endl;
    cout << loop << endl;
    cout << k << endl;
    cout << s << endl;
}


int main()
{
    solve1();
}

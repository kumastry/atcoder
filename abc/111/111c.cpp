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
    int n; cin >> n;
    vector<int> a(n);
    map<int, int> d, u;
    rep(i, n) {
        cin >> a[i];
        if(i%2 == 0) {
            d[a[i]] ++;
        } else {
            u[a[i]]++;
        }
    }

    int maxu = -1, maxd = -1;
    int numd = -1, numu = -1;
    vector<int> dd, uu;
    dd.push_back(0);
    uu.push_back(0);
    for(auto itr = d.begin(); itr != d.end(); itr++) {
        if(numd < itr->se) {
            numd = itr->se;
            maxd = itr->fi;
        }

        dd.push_back(itr->se);

    }

    for(auto itr = u.begin(); itr != u.end(); itr++) {
        if(numu < itr->se) {
            numu = itr->se;
            maxu = itr->fi;
        }

        uu.push_back(itr->se);
    }

    
    sort(all(uu), greater<int>());
    sort(all(dd), greater<int>());
    int sd = dd[1];
    int su = uu[1];
    //cout << "&&&&& " << dd.size() << " " << uu.size() << endl;

    if(maxu != maxd) {
        cout << n - numu - numd << endl; 
    } else {
        ll f;
        if(n/2 - numu > n/2 - numd) {
            f = n / 2 - numd;
            f += n/2 - su;
        } else {
            f = n/2 - numu;
            f += n/2 - sd;
        }

        cout << min(n - numu-sd, n-numd-su) << endl;
    }


}

int main()
{
    solve1();
}

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


typedef long long ll;



bool func(ll x, ll n) {
    if(x%2) {
      if(1.0*x <= 2.0 * (n +1 ) / (x+1)) {
          return true;
      } else {
          return false;
      }
    } else {
      if(1.0*(x+1) <= 2.0 * (n +1 ) / x) {
          return true;
      } else {
          return false;
      }
    }
    
}

void solve1() {
    ll n; cin >> n;

    ll r = n+1, l = 1;

    while(r - l > 1) {
        ll mid = (r+l)/2;
        if(func(mid, n)) {
            l = mid;
            //cout << 1 << endl;
        } else {
            r = mid;
           // cout << 2 << endl;
        }
        
        //cout << r << " " << l << endl;
        //cout << mid << endl;
    }

   // cout << l << endl;

   cout << n-l+1 << endl;
}

int main()
{
    solve1();
}

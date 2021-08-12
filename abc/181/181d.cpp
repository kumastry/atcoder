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

long long modinv(long long a, long long m)
{
    long long b = m, u = 1, v = 0;
    while (b)
    {
        long long t = a / b;
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

void solve1() {
    string s; cin >> s;
    vector<int> sd; 
    map<int, int>m;
    rep(i, (int)s.size()) {
        if(m[s[i]-'0'] < 3) {
          m[s[i]-'0']++;
        }
    }

    for(int i = 1; i <= 9; i++) {
        rep(j, m[i]) {
            sd.push_back(i);
        }
    }

    sort(all(sd));
    bool f = false;


     
    if(s.size() == 1) {
        if((s[0]-'0')%8 == 0) {
            f = true;
        }
    } else if(s.size() == 2) {
          if((10*(s[0]-'0')+s[1]-'0')%8 == 0) {
            f = true;
        }

        if((10*(s[1]-'0')+s[0]-'0')%8 == 0) {
            f = true;
        }



    } else {
      do {
          for(int i = 0; i < (int)sd.size()-2; i++) {
              int num = 100*sd[i] + 10*sd[i+1]+sd[i+2];
             
           if(num%8 == 0) {
              f = true;
              goto la;
           }
          }

      } while(next_permutation(all(sd)));
    }

    la:
    if(f) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

}

int main()
{
    solve1();
}

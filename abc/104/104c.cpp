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

ll d, g; 
vector<ll> p, c;

bool f(ll mid) {
    ll tg = g;
    vector<bool> f(d, true);
    while(1) {
        double ave = -1.0;
     
        rep(i, d) {
            if(f[i]) {
            if(mid >= p[i]) {
                ave = max(ave, ((i+1)*100*p[i] + c[i]) / (1.0*p[i]) );
              
            } else {
                ave = max(ave, ((i+1)*100.0*mid) / mid);
            }
            }
        }

        //cout << mid << " " << ave << endl;
    

        rep(i, d) {
            double ma;
            if(f[i]) {
            if(mid >= p[i]) {
                ma = ((i+1)*100*p[i] + c[i]) / (1.0*p[i]) ;
            } else {
                ma = ((i+1)*100.0*mid) / mid;
            }
            
           
            if(ave == ma) {
                f[i] = false;

                //cout << i+1 << " " << idx++ << " : " << ma << endl;
                
                if(mid >= p[i]) {
                    tg -= (i+1)*100*p[i] + c[i];
                    mid -= p[i];
                } else {
                    tg -= (i+1)*100.0*mid;
                    mid = 0;
                }

                if(tg <= 0) {
                    return true;
                }

                if(mid <= 0 && tg > 0) {
                    return false;
                }
            }

            }
        }

        //cout << mid  << " " <<tg << " " << ave << endl;
    }

    
}

void solve1() {
    cin >> d >> g;
    p.assign(d, 1); c.assign(d, 1);   
    rep(i, d) {
        cin >> p[i] >> c[i];
    }

    ll r = 1e18, l = 1;
    while(r - l > 1) {
        ll mid = (r+l)/2;

        if(f(mid)) {
            r = mid;
        } else {
            l = mid;
        }

        //cout << endl;
    }

    cout << r << endl;
}

int main()
{
    solve1();
}

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

#define MOD 998244353
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
    ll a, b; cin >> a >> b;
    ll sum = 0;
    if(a == b) {
        rep(i, a) {
            cout << i + 1 << " ";
        } 

        rep(i, b) {
            if(i == b-1) {
                cout << -b << endl;
                break;
            }
            cout << -(i+1) << " ";
        }


    } else if(a > b) {
        for(ll i = 1; i <= a; i++) {
            sum += i;
            cout << i << " ";
        }

        sum *= -1;
        ll sumb = 0;
        for(ll i = 1; i <= b; i++) {
            if(i == b) {
                cout << sum - sumb << endl;
                break;
            }
          
            sumb -= i;

            cout << -i << " ";
        }
    } else if(b > a) {
        for(ll i = 1; i <= b; i++) {
            sum += i;
            cout << -i << " ";
        }

        ll sumb = 0;
        for(ll i = 1; i <= a; i++) {
            
            if(i == a) {
                cout << sum - sumb << endl;
                break;
            }

           sumb += i;

            cout << i << " ";
        }      
    }
}

int main()
{
    solve1();
}

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
    ll n; cin >> n;
    map<ll, ll> mt;
   
    for(int i = 2; i <= n; i++) {
        ll num = i;
        for(int j = 2; j*j <= num; j++) {
            int cnt = 0;
            while(num%j==0) {
                num /= j;
                cnt ++;
            }

            mt[j] += cnt;
        }

        if(num != 1) mt[num] += 1;
    }

    int t3 = 0, t5 = 0, t15 = 0, t25 = 0, t75=0;
    for(auto itr = mt.begin(); itr != mt.end(); itr++) {
        //cout << itr->first << " " << itr->second << endl;
        
        if(itr->second + 1 >= 75) {
            t75++;
        } 
        if(itr->second + 1 >= 25) {
            t25++;
        }  
         if(itr->second + 1 >= 15) {
            t15++;
        }  
         if(itr->second + 1 >= 5) {
            t5++;
        }  
        
        if(itr->second + 1 >= 3) {
            t3++;
        } 
    }

    ll ans  = 0;
    //cout << t3 << " " << t5 << " " << t15  << " " << t25  << " " << t75 <<  endl;
    ans += t5*(t5-1)/2*(t3-2);
    ans += t25*(t3-1);
    ans += t15*(t5-1);
    ans += t75;
    cout << ans << endl;

}

int main()
{
    solve1();
}

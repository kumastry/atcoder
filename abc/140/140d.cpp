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
    int n, k; cin >> n >> k;
    string s; cin >> s;

    int cnt = 1;
    vector<int>lc, rc;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'L' && s[i] == s[i+1]) {
            cnt ++;
        } else if(s[i] == 'L' && s[i+1] == 'R') {
            lc.push_back(cnt);
            cnt = 1;
        } else if(i == n-1) {
            if(s[i] == 'L') {
            if(s[i-1] != s[i]) {
                cnt=1;
            } 
            lc.push_back(cnt);
            }

            
        }
    }



    cnt = 1;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'R' && s[i] == s[i+1]) {
            cnt ++;
        } else if(s[i] == 'R' && s[i+1] == 'L') {
            rc.push_back(cnt);
            cnt = 1;
        } else if(i == n-1) {
            if(s[i] == 'R') {
                if(s[i-1] != s[i]) {
                    cnt=1;
                }
                rc.push_back(cnt);
            }
        }
    }

    rep(i, (int)lc.size()) {
        cout << lc[i] << " ";
    }

    cout << endl;

    rep(i, (int)rc.size()) {
        cout << rc[i] << " ";
    }

    cout << endl;

    sort(all(lc), greater<int>());
    sort(all(rc), greater<int>());    

    
}

int main()
{
    solve1();
}

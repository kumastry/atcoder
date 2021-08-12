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
#include <tuple>

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
    int h, w; cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    int oddcnt = 0;
    rep(i, h) {
        rep(j, w) {
            cin >> a[i][j];
            oddcnt ++;
        }
    }

    oddcnt /= 2;
    int cnt = 0;
    vector< tuple<int, int, int, int> > t;
    bool f = false;
    rep(i, h) {
        for(int j = 0; j < w; j++) {
            int jj;
            if(i%2 == 0) {
                jj = j;
                
            } else {
                jj = w-1-j;
            }


            if(a[i][jj]%2) {
                
                int idx=-1, jdx=-1;
                if(i%2==0) {
                    if(jj != w-1) {
                        a[i][jj]--;
                        a[i][jj+1]++;
                        idx = i;
                        jdx = jj+1;
                        //cout << "DDDD" << endl;
                    } else if(i != h-1){
                        a[i][jj]--;
                        a[i+1][jj]++;
                        idx = i+1;
                        jdx = jj;   
                        //cout << "BBBB" << endl;                     
                    }
                } else {
                    if(jj != 0) {
                        a[i][jj]--;
                        a[i][jj-1]++;
                        idx = i;
                        jdx = jj-1;
                        //cout << "cccc" << endl; 
                    } else if(i != h-1){
                        a[i][jj]--;
                        a[i+1][jj]++;
                        idx = i+1;
                        jdx = jj;
                        //cout << "aaaa" << endl; 
                    }                    
                }

                if(idx != -1 || jdx != -1) {
                    t.push_back(make_tuple(i+1, jj+1, idx+1, jdx+1));
                    cnt++;
                }
            }
        }
    }

    cout << cnt << endl;
    rep(i, cnt) {
        cout << get<0>(t[i]) << " " << get<1>(t[i]) << " " << get<2>(t[i]) << " " << get<3>(t[i]) << endl;
    }
}

int main()
{
    solve1();
}

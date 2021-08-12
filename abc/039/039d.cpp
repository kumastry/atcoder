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
using Graph = vector<vector<int>>;

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
    vector<vector<char>> s(h, vector<char>(w));
    vector<vector<char>> ans(h, vector<char>(w, '.'));
    vector<vector<int>> counter(h, vector<int>(w, 0));

    rep(i, h) {
        rep(j, w) {
            cin >> s[i][j];
        }
    }


    rep(i, h) {
        rep(j, w) {
            if(s[i][j] == '#') {
                bool f = true;
                for(int k = -1; k <= 1; k++) {
                    for(int l = -1; l <= 1; l++) {
                        int x = j + k;
                        int y = i + l;

                        if(x >= 0 && x < w && y >= 0 && y < h) {
                            if(s[y][x] != '#') {
                                f = false;
                            }

                            //cout << "(" << i+1 << "," << j+1 << ") = " << s[y][x] << endl;
                        }



                    }
                }


                if(f) {
                    ans[i][j] = '#';
                    for(int k = -1; k <= 1; k++) {
                        for(int l = -1; l <= 1; l++) {
                           int x = j + k;
                           int y = i + l;

                           if(x >= 0 && x < w && y >= 0 && y < h && s[y][x] == '#') {
                               counter[y][x] ++;
                           }
                        }
                    }
                }
                
            }
        }
    }


    bool f2 = true;
    rep(i, h) {
        rep(j, w) {
            if(s[i][j] == '#' && counter[i][j] == 0) {
                f2 = false;
            } 
        }
    }

    if(!f2) {
        cout << "impossible" << endl;
    } else {
        cout << "possible" << endl;
        rep(i, h) {
            rep(j, w) {
                cout << ans[i][j];
            }

            cout << endl;
        }
    }

}

int main()
{
    solve1();
}

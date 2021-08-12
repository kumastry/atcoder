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
    int n, a, b, c, d; cin >> n >> a >> b >> c >> d;
    string s; cin >> s;

    bool f = true;
    rep(i, (int)s.size()-1) {
        if(s[i] == '#' && s[i] == s[i+1]) {
            f = false;
        }
    }

    if(f) {
        string tmp(s);

        tmp[d-1] = '#';
        rep(i, (int)s.size()-1) {
           if(tmp[i] == '#' && tmp[i] == tmp[i+1]) {
               f = false;
           }
        }

        tmp[d-1] = '.';

        tmp[c-1] = '#';
        rep(i, (int)s.size()-1) {
           if(tmp[i] == '#' && tmp[i] == tmp[i+1]) {
               f = false;
           }
        }


        if(!f) {
            int cnt = 0;
            int i = b-1;
            while(i < d-2 && i < n) {
                if(s[i] == '.') {
                    if(s[i] == s[i+1]) {
                        cnt += 2;
                        i += 2;
                    } else {
                        cnt ++;
                        i++;
                    }
                } else {
                    if(cnt > 2) {
                        f = true;
                    }
                    cnt = 0;
                    i++;
                }
            }

            if(f) {
                cout << "Yes" << endl;
                //cout << 1 << endl;
            } else {
                cout << "No" << endl;
                //cout << 2 << endl;
            }
            
        } else {
            cout << "Yes" << endl;
        }


    } else {
        cout << "No" << endl;
    }
}

int main()
{
    solve1();
}

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

vector<int> prime(1000000);
vector<bool> is_prime(1000000);

int sieve(int n) {
    int p = 0;
    for(int i = 0; i < n+1; i++) {
        is_prime[i] = true;;
    }

    is_prime[0] = false;;
    is_prime[1] = false;
    

    int idx = 0;
    for(int i = 2; i <= n+1; i++) {
        if(is_prime[i]) {
            prime[idx++] = i;
            for(int j = i*2; j <= n + 1; j += i) {
                is_prime[j] = false;
                p ++;
            }

        }
    }

    return p;
}

void solve1() {
    int a, b; cin >> a >> b;

    if(a<= b) {
        cout << a << endl; 
    } else {
        cout << a-1 << endl;
    }
}

int main()
{
    solve1();
}

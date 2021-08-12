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
    string str;
    string target = "keyence";
	cin>>str;
	if(str == target){
		puts("YES");
		return;
	}
	int n = str.size();
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			//delete [i,j]
			string S = "";
			for(int k=0;k<n;k++){
				if(i<=k && k<=j){
					continue;
				}
				else S.push_back(str[k]);
			}
			if(S == target){
				puts("YES");
				return;
			}
		}
	}
	puts("NO");

}

int main()
{
    solve1();
}

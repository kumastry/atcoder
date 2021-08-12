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
#include <math.h>    // for fabs()
#include <stdio.h>   // for printf()

using namespace std;

#define MOD 1000000007
#define PI 3.1415926535897932
#define INF 1e9
#define max 1e3                //最大繰り返し回数
#define eps 1.0e-6              //収束条件
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


long double a, b, c; 

long double f(long double x) {
    return a*x + b*sin(c*x*PI);
}

void solve1() {
  cin >> a >> b >> c;
  a *= 1.0;
  b *= 1.0;
  c *= 1.0;

  long double low = 0, high = 200;
  for(int i = 0; i < 1000; i++) {
      long double mid = (low + high) / 2;
      if(f(mid) < 100) low = mid;
      else high = mid;

      //cout << low << endl;
  }

  cout << fixed << setprecision(20) << low << endl;
}

int main()
{
    solve1();
}

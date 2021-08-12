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
#define INF 1e18
#define rep(i, n) for (int i = 0; i < n; i++)
#define repe(i, j, n) for (int i = j; i < n; i++)
#define repi(i, n) for (int i = 0; i <= n; i++)
#define repie(i, j, n) for (int i = j; i <= n; i++)
#define all(x) x.begin(), x.end()
#define println() cout << endl
#define P pair<ll, ll>
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

int prime[10000000];
bool is_prime[100000000 + 1];

int sieve(int n) {
    int pcnt = 0;
    for(int i = 0; i <= n; i++) {
        is_prime[i] = true;
    }

    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i <= n; i++) {
        if(is_prime[i]) {
            prime[pcnt++] = i;
            for(int j = 2*i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }

    return pcnt;
}

ll dp[1000][1000];

ll combi(ll n, ll r)
{
       if(n==r) return dp[n][r] = 1;
       if(r==0) return dp[n][r] = 1;
       if(r==1) return dp[n][r] = n;
       if(dp[n][r]) return dp[n][r];
       return dp[n][r] = combi(n-1,r) + combi(n-1,r-1);
}

struct edge {
    ll to;
    ll cost;

    edge(ll to, ll cost) {
        this->to = to;
        this->cost = cost;
    }
};

using Graph = vector<vector<edge>>;
ll V = 500, d[500];
void dijkstra(ll s, ll ne, Graph G) {
    fill(d, d + V, INF);
    d[s] = 0;  // 始点sへの最短距離は0

    priority_queue<P, vector<P>, greater<P>> que;  // 距離が小さい順に取り出せるようgreater<P>を指定
    que.push(P(0, s));
    int cnt = 0;
    while (!que.empty()) {
        P p = que.top();
        que.pop();
        ll v = p.second;  // 更新した頂点の中で距離が最小の頂点v

        if(cnt = 0 && v == ne) {
            cnt ++;
            cout << "###" << endl;
            continue;
        }


        if (d[v] < p.first) {
            continue;
        }

        for (auto e : G[v]) {  // 頂点vから出る辺eを走査
        //cout << cnt << "*" << v+1 << ":" << e.to+1 << endl;
        if(v == s && e.to == ne) continue;
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }

        cnt ++;
        
    }
}

void solve1() {
    ll n;
    cin >> n;

    
}

int main()
{
    solve1();
}

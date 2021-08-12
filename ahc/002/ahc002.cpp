#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve1() {
    
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    ll si,sj; cin >> si >> sj;
    vector<vector<ll>> t(50, vector<ll>(50));
    vector<vector<ll>> p(50, vector<ll>(50));
    vector<vector<bool>> seen(50, vector<bool>(50, false));
    bool fj = false, fi = false;
    set<int> st;
    if(sj >= 25) {
        dx[0] = -1;
        dx[2] = 1;
        fj = true;
    }

    if(si >= 25) {
        dx[1] = -1;
        dx[3] = 1;
        fi = true;
    }

    

    for(int i = 0; i < 50; i++) {
        for(int j = 0; j < 50; j++) {
            cin >> t[i][j];
            st.insert(t[i][j]);
        }
    }

    vector<bool> ts(st.size(), false);
    seen[si][sj] = true;
    for(int i = 0; i < 50; i++) {
        for(int j = 0; j < 50; j++) {
            cin >> p[i][j];
        }
    }

    ts[t[si][sj]] = true;
    ll x = sj, y = si;
    string ans = "";
    int cnt = 0;
    while(1) {

        ll num = -1;
        ll move = -1;
        //cout << x << " " << y << endl;
        for(int i = 0; i < 4; i++) {
            ll nx = x + dx[i], ny = y + dy[i];
            if(nx >= 50 || nx < 0 || ny >= 50 || ny < 0) {
                continue;
            }

            if(seen[ny][nx]) continue;
            if(ts[t[ny][nx]]) continue;
            //cout << i << ": " << nx << " " << ny << endl;

            
            //cout << "## " << p[ny][nx] << endl; 
            if(cnt%15 == 0) {
                if(num < p[ny][nx]) {
                    move = i;
                    num = p[ny][nx];
                }
            } else if(cnt%3 == 0) {
                continue;
            } else {
                move = i;
                break;
            }
            

            //cout << move << " " << num << endl;
        }

        //cout << "###" << endl;
        //cout << "###" << move << endl;
        if(move == 0) {
            if(fj) {
                ans += 'L';
            } else {
                ans += 'R';
            }
        } else if(move == 1) {
            if(fi) {
                ans += 'U';
            } else {
                ans += 'D';
            }
            
        } else if(move == 2) {
            if(fj) {
                ans += 'R';
            } else {
                ans += 'L';
            }
        } else if(move == 3){
            if(fi) {
                ans += 'D';
            } else {
                ans += 'U';
            }
            
        } else {
            break;
        }

       
        x += dx[move];
        y += dy[move];
        seen[y][x] = true;
        ts[t[y][x]] = true;
        cnt ++;

        if(cnt >= 50000000) {
            break;
        }
    }

    cout << ans << endl;
    
}

int main() {
    solve1();
}
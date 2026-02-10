#include<iostream>
#include<vector>
using namespace std;
void dfs(int now_y, int now_x, int h, int w, int k, vector<string>& s, vector<vector<bool>>& is_visited, int& dist, int& ans){
    vector<pair<int, int>> delta = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int next_y, next_x, dy, dx;

    is_visited[now_y][now_x] = true;
    dist++;

    if(dist == k){
        ans++;
        dist--;
        is_visited[now_y][now_x] = false;
        return;
    }

    for(int i=0; i<4; i++){
        dy = delta[i].first;
        dx = delta[i].second;
        next_y = now_y + dy;
        next_x = now_x + dx;
        if(next_y < 0 || h <= next_y || next_x < 0 || w <= next_x) continue;
        if((!is_visited[next_y][next_x]) && (s[next_y][next_x]!='#')) dfs(next_y, next_x, h, w, k, s, is_visited, dist, ans);
    }

    dist--;
    is_visited[now_y][now_x] = false;
    return;

}


int main(){
    int h, w, k;
    cin >> h >> w >> k;
    vector<string> s(h);
    for(int i=0; i<h; i++) cin >> s[i];
    int dist;
    int ans;

    ans = 0;

    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            vector<vector<bool>> is_visited(h, vector<bool>(w, false));
            dist = -1;
            if(s[i][j] == '#') continue;
            dfs(i, j, h, w, k, s, is_visited, dist, ans);
        }
    }

    cout << ans << endl;

    return 0;

}
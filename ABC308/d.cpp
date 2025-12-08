#include<iostream>
#include<vector>
#include<map>
using namespace std;
void dfs_grid(pair<int, int> now_p, int h, int w, vector<string>& grid, vector<vector<bool>>& is_visited){
    int now_y, now_x, next_y, next_x;
    vector<int> dy, dx;
    pair<int, int> next_p;
    map<char, char> word_table{
        {'s', 'n'},
        {'n', 'u'},
        {'u', 'k'},
        {'k', 'e'},
        {'e', 's'}
    };
    dy = {1, 0, -1, 0};
    dx = {0, 1, 0, -1};
    
    now_y = now_p.first;
    now_x = now_p.second;
    is_visited[now_y][now_x] = true;

    for(int i=0; i<dy.size(); i++){
        next_y = now_y + dy[i];
        next_x = now_x + dx[i];
        next_p = {next_y, next_x};
        if(next_y < 0 || h <= next_y || next_x < 0 || w <= next_x) continue;
        if(is_visited[next_y][next_x]) continue;
        if(word_table[grid[now_y][now_x]] != grid[next_y][next_x]) continue;
        dfs_grid(next_p, h, w, grid, is_visited);
    }
}

int main(){
    int h, w;
    string s;
    cin >> h >> w;
    vector<string> grid;
    vector<vector<bool>> is_visited(h, vector<bool>(w, false));
    pair<int, int> now_p;

    for(int i=0; i<h; i++){
        cin >> s;
        grid.push_back(s);
    }

    now_p = {0, 0};
    is_visited[0][0] = true;

    dfs_grid(now_p, h, w, grid, is_visited);

    if(is_visited[h-1][w-1]){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;

}
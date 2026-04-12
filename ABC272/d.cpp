#include<iostream>
#include<vector>
#include<cmath>
#include<set>
#include<deque>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    
    set<int> sqrt_num;
    vector<pair<int, int>> delta;

    for(int i=0; i<sqrt(m)+1; i++) sqrt_num.insert(i*i);

    for(int i=0; i<sqrt(m)+1; i++){
        auto iter = sqrt_num.find(m-i*i);
        if(iter != sqrt_num.end()){
            delta.push_back({i, sqrt(m-i*i)});
            delta.push_back({-i, sqrt(m-i*i)});
            delta.push_back({i, -sqrt(m-i*i)});
            delta.push_back({-i, -sqrt(m-i*i)});
        }
    }

    deque<pair<int, int>> next_grids;
    vector<vector<bool>> is_visited(n, vector<bool>(n, false));
    vector<vector<int>> step(n, vector<int>(n, -1));

    pair<int, int> now_grid, next_grid;
    next_grid = {0, 0};
    is_visited[next_grid.first][next_grid.second] = true;
    step[next_grid.first][next_grid.second] = 0;
    next_grids.push_back(next_grid);

    while(!next_grids.empty()){
        now_grid = next_grids.front();
        next_grids.pop_front();

        for(auto d:delta){
            int dy = d.first;
            int dx = d.second;
            next_grid.first = now_grid.first + dy;
            next_grid.second = now_grid.second + dx;
            if(0 <= next_grid.first && next_grid.first < n && 0 <= next_grid.second && next_grid.second < n){
                if(!is_visited[next_grid.first][next_grid.second]){
                    is_visited[next_grid.first][next_grid.second] = true;
                    step[next_grid.first][next_grid.second] = step[now_grid.first][now_grid.second] + 1;
                    next_grids.push_back(next_grid);
                }
            }
        }
    }

    for(auto si:step){
        for(auto sij:si) cout << sij << " ";
        cout << endl;
    }

    return 0;
}
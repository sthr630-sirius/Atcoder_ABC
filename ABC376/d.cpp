#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<int> cycle_end_node;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        if(b == 0) cycle_end_node.push_back(a);
    }

    int INF = 2000000;
    vector<bool> is_visited(n, false);
    vector<int> length(n, INF);
    queue<int> next_nodes;
    int now_v, next_v;
    int ans;

    next_v = 0;
    next_nodes.push(next_v);
    is_visited[next_v] = true;
    length[next_v] = 0;

    while(!next_nodes.empty()){
        now_v = next_nodes.front();
        next_nodes.pop();

        for(int next_v:g[now_v]){
            if(is_visited[next_v]) continue;
            next_nodes.push(next_v);
            is_visited[next_v] = true;
            length[next_v] = length[now_v]+1;
        }
    }

    ans = INF;
    for(auto v:cycle_end_node){
        ans = min(ans, length[v]);
    }
    
    if(ans == INF) cout << -1 << endl;
    cout << ans+1 << endl;

    return 0;
}

/*
void dfs(int now_v, vector<vector<int>>& g, vector<bool>& is_visited, vector<bool>& is_cycle_node, vector<int>& cycle_order, int& path_length, int& ans){
    is_visited[now_v] = true;
    path_length++;

    for(auto next_v:g[now_v]){        
        if(next_v == 0){
            ans = min(ans, path_length);
            is_cycle_node[now_v] = true;
            cycle_order[now_v] = 1;
        }

        if(is_visited[next_v]){
            if(is_cycle_node[next_v]){
                is_cycle_node[now_v] = true;
                cycle_order[now_v] = min(cycle_order[now_v], cycle_order[next_v]+1);
                ans = min(ans, path_length+cycle_order[next_v]);
            }
        }else{
            dfs(next_v, g, is_visited, is_cycle_node, cycle_order, path_length, ans);
            if(is_cycle_node[next_v]){
                is_cycle_node[now_v] = true;
                cycle_order[now_v] = min(cycle_order[now_v], cycle_order[next_v]+1);
            }
        }
    }

    path_length--;

    return;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    int a, b;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
    }

    int INF = 2000000;
    vector<bool> is_visited(n, false);
    vector<bool> is_cycle_node(n, false);
    vector<int> cycle_order(n, INF);

    int path_length = 0;    
    int ans = INF;

    dfs(0, g, is_visited, is_cycle_node, cycle_order, path_length, ans);
    
    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}
*/
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
void bfs_grid(int next_node, vector<vector<int>>& g, vector<int>& step, int n){
    int now_node;
    queue<int> next_nodes;
    vector<int> is_visited(n, false);

    step[next_node] = 0;
    next_nodes.push(next_node);
    is_visited[next_node] = true;

    while(!next_nodes.empty()){
        now_node = next_nodes.front();
        next_nodes.pop();
        for(int next_node:g[now_node]){
            if(is_visited[next_node]) continue;
            step[next_node] = step[now_node] + 1;
            next_nodes.push(next_node);
            is_visited[next_node] = true;
        }
    }
}

int main(){
    int n1, n2, m;
    cin >> n1 >> n2 >> m;
    vector<vector<int>> g1(n1+n2), g2(n1+n2);
    vector<int> step_g1(n1+n2, -1), step_g2(n1+n2, -1);
    int u, v;
    int ans;
    for(int i=0; i<m; i++){
        cin >> u >> v;
        if(u <= n1){
            u--;
            v--;
            g1[u].push_back(v);
            g1[v].push_back(u);
        }else{
            u--;
            v--;
            g2[u].push_back(v);
            g2[v].push_back(u);
        }
    }
    
    bfs_grid(0, g1, step_g1, n1+n2);
    bfs_grid(n1+n2-1, g2, step_g2, n1+n2);

    ans = *max_element(begin(step_g1), end(step_g1)) + *max_element(begin(step_g2), end(step_g2)) + 1;
    cout << ans << endl;

    return 0;

}
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
    else cout << ans+1 << endl;

    return 0;
}
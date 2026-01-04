#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> v_weight(n);
    vector<vector<pair<int, int>>> g(n);
    int u, v, b;

    for(int i=0; i<n; i++) cin >> v_weight[i];
    for(int i=0; i<m; i++){
        cin >> u >> v >> b;
        u--;
        v--;
        g[u].push_back({v, b});
        g[v].push_back({u, b});
    }

    long long INF = 9000000000000000000;
    vector<long long> sum_weight(n, INF);
    vector<bool> is_visited(n, false);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> next_v_que;
    
    sum_weight[0] = v_weight[0];
    next_v_que.push({sum_weight[0], 0});

    while(!next_v_que.empty()){
        int now_v = next_v_que.top().second;
        next_v_que.pop();
        
        if(is_visited[now_v]) continue;
        is_visited[now_v] = true;
        
        for(auto [next_v, e_weight]:g[now_v]){
            if(is_visited[next_v]) continue;
            sum_weight[next_v] = min(sum_weight[next_v], sum_weight[now_v] + e_weight + v_weight[next_v]);
            next_v_que.push({sum_weight[next_v], next_v});
        }
    }

    for(int i=1; i<n; i++) cout << sum_weight[i] << " ";
    cout << endl;
}
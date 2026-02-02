#include<iostream>
#include<vector>
using namespace std;
void dfs(int now_v, long long num, vector<vector<pair<int, int>>>& g, vector<bool>& is_visited, vector<long long>& x){
    int next_v, next_w;
    
    is_visited[now_v] = true;
    x[now_v] = num;

    for(auto next:g[now_v]){
        next_v = next.first;
        next_w = next.second;
        if(is_visited[next_v]) continue;
        dfs(next_v, num+next_w, g, is_visited, x);
    }
}


int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    vector<long long> x(n);
    
    int u, v, w;
    for(int i=0; i<m; i++){
        cin >> u >> v >> w;
        u--;
        v--;
        g[u].push_back({v, w});
        g[v].push_back({u, -w});
    }

    int now_v;
    long long first_number;
    vector<bool> is_visited(n, false);

    for(int i=0; i<n; i++){
        now_v = i;
        first_number = 0;
        if(is_visited[now_v]) continue;
        dfs(now_v, first_number, g, is_visited, x);
    }

    for(int i=0; i<n; i++) cout << x[i] << " ";
    cout << endl;

    return 0;

}
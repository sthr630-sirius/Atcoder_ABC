#include<iostream>
#include<vector>
using namespace std;
void dfs(int now_v, vector<vector<pair<int, int>>>& g, int step_max, int step, int s, int t, int total_cost, int cost, vector<bool>& ans){
    int next_v, next_c;
    
    step++;
    total_cost += cost;

    //cout <<  "now_v: " << now_v+1 << " total_cost: " << total_cost << endl;
    //cout << "(now_v, step): (" << now_v+1 << ", " << step << "), ";
    
    if(step < step_max){
        for(auto next_info:g[now_v]){
            next_v = next_info.first;
            next_c = next_info.second;
            dfs(next_v, g, step_max, step, s, t, total_cost, next_c, ans);
        }
    }else if(step == step_max){
        //cout << "now_v: " << now_v+1 << " step :" << step << " total_cost :" << total_cost << endl;
        if(s <= total_cost && total_cost <= t) ans[now_v] = true;
    }

    //step--;
    //total_cost -= cost;

    return;
}


int main(){
    int n, m, l, s, t;
    cin >> n >> m >> l>> s >> t;
    vector<vector<pair<int, int>>> g(n);
    for(int i=0; i<m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        u--;
        v--;
        g[u].push_back({v, c});
    }

    /*
    for(auto gi:g){
        for(auto gij:gi) cout << "(" << gij.first << ", " << gij.second << ") ";
        cout << endl;
    }
    */

    vector<bool> ans(n, false);
    int total_cost;
    total_cost = 0;
    dfs(0, g, l, -1, s, t, total_cost, 0, ans);

    for(int i=0; i<n; i++) if(ans[i]) cout << i+1 << " ";
    cout << endl;

    return 0;

}
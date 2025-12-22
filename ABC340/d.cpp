#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
void bfs(int n, vector<vector<pair<int, int>>>& g){
    //vector<bool> is_visited(n, false);
    long long INF = 1000000000000000;
    vector<long long> time(n, INF);
    int now_v, next_v;
    int child_v, child_t;
    vector<pair<int, int>> child_info_list; 
    long long min_time = INF;

    now_v = 0;
    time[now_v] = 0;

    cout << "now_v: " << now_v << endl;
    while(now_v != n-1){
        min_time = INF;
        for(auto child_info : g[now_v]){
            child_v = child_info.first;
            child_t = child_info.second;
            time[child_v] = min(time[child_v], time[now_v]+child_t);

            if(time[child_v] <= min_time){
                min_time = time[child_v];
                next_v = child_v;
            }
        }
        now_v = next_v;    
    }
        
    cout << "-------debug-----------" << endl;
    for(auto t:time) cout << t << " ";
    cout << endl;
    
    cout << time[n-1] << endl;

}

int main(){
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> g(n);
    vector<int> parent(n);
    vector<int> in_edge(n);
    int a, b, x;

    for(int i=0; i<n-1; i++){
        cin >> a >> b >> x;
        x--;
        g[i].push_back({i+1, a});
        g[i].push_back({x, b});
    }

    bfs(n, g);

    return 0;
}
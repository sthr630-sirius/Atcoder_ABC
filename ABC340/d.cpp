#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
void bfs(int n, vector<vector<pair<int, int>>>& g){
    //vector<bool> is_visited(n, false);
    long long INF = 1000000000000000;
    vector<bool> is_visited(n, false);
    vector<long long> time(n, INF);
    int now_v, next_v;
    int child_v, child_t;
    vector<pair<int, int>> child_info_list; 
    long long min_time = INF;

    now_v = 0;
    time[now_v] = 0;
    is_visited[now_v] = true;

    for(auto t:time) cout << t << " ";
    cout << endl;
    for(auto b:is_visited) cout << b << " ";
    cout << endl;

    //cout << "now_v: " << now_v << endl;
    while(now_v != n-1){
        min_time = INF;
        for(auto child_info : g[now_v]){
            child_v = child_info.first;
            child_t = child_info.second;
            if(is_visited[child_v]) continue;
            //cout << "child_v: " << child_v << endl;
            time[child_v] = min(time[child_v], time[now_v]+child_t);

            //cout << "time: " << time[child_v] << endl;

            if(time[child_v] <= min_time){
                //cout << "if----" << endl;
                //cout << "child_v: " << child_v << "  --> next_v" << endl; 
                
                min_time = time[child_v];
                next_v = child_v;
                //cout << "next_v: " << next_v << endl;
            }
        }
        is_visited[next_v] = true;
        //cout << "loop out for: " << endl;
        cout << endl;
        now_v = next_v;    
        cout << "now_v: " << now_v << endl;
        for(auto t:time) cout << t << " ";
        cout << endl;
        for(auto b:is_visited) cout << b << " ";
        cout << endl;
    }
    
    /*
    cout << "-------debug-----------" << endl;
    for(auto t:time) cout << t << " ";
    cout << endl;
    */
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
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a, b, x;
    long long INF = 1000000000000000;
    vector<vector<pair<int, int>>> g(n);
    vector<long long> time(n, INF);
    vector<bool> is_visited(n, false);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> next_v_que;
    pair<long long, int> now_v_info;
    int now_v;
    long long now_t;

    for(int i=0; i<n-1; i++){
        cin >> a >> b >> x;
        x--;
        g[i].push_back({i+1, a});
        g[i].push_back({x, b});
    }
    
    time[0] = 0;
    next_v_que.push({time[0], 0});

    int child_v, child_w;

    while(!next_v_que.empty()){
        now_v_info = next_v_que.top();
        next_v_que.pop();
        now_t = now_v_info.first;
        now_v = now_v_info.second;
        if(is_visited[now_v]) continue;
        is_visited[now_v] = true;

        //for(auto child_info:g[now_v]){
        for(auto [child_v, child_w]:g[now_v]){
            //child_v = child_info.first;
            //child_w = child_info.second;
            
            if(is_visited[child_v]) continue;
            time[child_v] = min(time[child_v], time[now_v]+child_w);
            next_v_que.push({time[child_v], child_v});
        }
    }

    cout << time[n-1] << endl;

    return 0;
}
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

    for(int i=0; i<n-1; i++){
        cin >> a >> b >> x;
        x--;
        g[i].push_back({i+1, a});
        g[i].push_back({x, b});
    }
    
    time[0] = 0;
    next_v_que.push({time[0], 0});

    while(!next_v_que.empty()){
        auto [now_t, now_v] = next_v_que.top();
        next_v_que.pop();
        if(is_visited[now_v]) continue;
        is_visited[now_v] = true;

        for(auto [child_v, child_w]:g[now_v]){            
            if(is_visited[child_v]) continue;
            time[child_v] = min(time[child_v], time[now_v]+child_w);
            next_v_que.push({time[child_v], child_v});
        }
    }

    cout << time[n-1] << endl;

    return 0;
}
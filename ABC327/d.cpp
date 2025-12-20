#include<iostream>
#include<vector>
#include<set>
using namespace std;

void dfs(int now_v, vector<set<int>>& g, vector<bool>& is_visited, vector<int>& parent, vector<bool>& go_to, vector<int>& path, bool& is_ok){
    int cycle_cnt;

    is_visited[now_v] = true;
    path.push_back(now_v);

    //cout << "now_v:" << now_v+1 << endl;
    //cout << "g[" << now_v+1 << "]: ";
    //for(auto v:g[now_v]) cout << v+1 << " ";
    //cout << endl;

    for(auto next_v:g[now_v]){
        if(next_v == parent[now_v]) continue;
        if(is_visited[next_v] && go_to[next_v]){
            //cout << "cycle!!!!!!!!!!!!!!!!!" << endl;
            cycle_cnt = 0;
            for(int i=path.size()-1; i>=0; i--){
                cycle_cnt++;
                //cout << path[i]+1 << " ";
                if(path[i] == next_v) break;
            }
            //cout << endl;
            if(cycle_cnt%2 != 0) is_ok = false;
        }
        if(not is_visited[next_v]){
            //cout << endl;
            //cout << now_v+1 << " ---> " << next_v+1 << endl;
            go_to[now_v] = true;
            parent[next_v] = now_v;
            dfs(next_v, g, is_visited, parent, go_to, path, is_ok);
            go_to[now_v] = false;
            path.pop_back();
            //cout << now_v+1 << " <--- " << next_v+1 << endl;
        }
    }
}


int main(){
    int n, m;
    int u, v;
    cin >> n >> m;
    vector<set<int>> g(n);
    vector<int> a(m), b(m);
    vector<int> parent(n, -1);
    vector<bool> is_visited(n, false);
    vector<bool> go_to(n, false);
    vector<int> path;
    bool is_ok = true;

    for(int i=0; i<m; i++) cin >> a[i];
    for(int i=0; i<m; i++) cin >> b[i];

    for(int i=0; i<m; i++){
        u = a[i]-1;
        v = b[i]-1;
        if(u == v){
            is_ok = false;
            continue;
        }
        g[u].insert(v);
        g[v].insert(u);
    }

    for(int i=0; i<n; i++){
        if(is_visited[i]) continue;
        dfs(i, g, is_visited, parent, go_to, path, is_ok);
    }

    if(is_ok) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
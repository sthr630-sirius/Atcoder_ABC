/*
入力次数が0のedgeをpop
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<int> deg(n, 0);
    queue<int> deg_zero_v;
   
    vector<int> path;
    vector<int> a(n, 0);


    int x, y;
    for(int i=0; i<m; i++){
        cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
        deg[y]++;
    }

    for(int i=0; i<n; i++) if(deg[i]==0) deg_zero_v.push(i);

    int v;
    while(!deg_zero_v.empty()){
        if(deg_zero_v.size() > 1){
            cout << "No" << endl;
            return 0;
        }

        v = deg_zero_v.front();
        deg_zero_v.pop();
        for(auto u:g[v]){
            deg[u]--;
            if(deg[u] == 0) deg_zero_v.push(u);
        }
        path.push_back(v);
    }

    for(int i=0; i<n; i++) a[path[i]] = i+1;

    cout << "Yes" << endl;
    for(auto u:a) cout << u << " ";
    cout << endl;

    return 0;
}

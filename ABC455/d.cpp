#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n, q;
    cin >> n >> q;
    int c, p;
    vector<int> child(n, -1), parent(n, -1);
    for(int i=0; i<q; i++){
        cin >> c >> p;
        c--;
        p--;
        if(parent[c] != -1) child[parent[c]] = -1;
        parent[c] = p;
        child[p] = c;
    }

    int ans;
    for(int i=0; i<n; i++){
        ans = 0;
        if(parent[i] == -1){
            int now_v = i;
            ans++;
            while(child[now_v] != -1){
                now_v = child[now_v];
                ans++;
            }
        }
        cout << ans << " ";
    }
    cout << endl;
    
    return 0;
}
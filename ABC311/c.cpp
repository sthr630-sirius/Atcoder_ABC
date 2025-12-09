#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<bool> is_visited(n, false);
    vector<int> ans;
    int now_e, start_e;
    for(int i=0; i<n; i++){
        cin >> a[i];
        a[i]--;
    }

    now_e = 0;
    
    while(not is_visited[now_e]){
        is_visited[now_e] = true;
        now_e = a[now_e];
    }

    start_e = now_e;
    ans.push_back(now_e+1);
    now_e = a[now_e];
    while(now_e != start_e){
        ans.push_back(now_e+1);
        now_e = a[now_e];
    }
    
    cout << ans.size() << endl;
    for(auto e:ans){
        cout << e << " ";
    }
    cout << endl;

    return 0;
}
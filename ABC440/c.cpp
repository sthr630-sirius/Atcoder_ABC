#include<iostream>
#include<vector>
using namespace std;
void solve(){
    int n, w; 
    cin >> n >> w;
    vector<int> c(n);
    for(int i=0; i<n; i++) cin >> c[i];
    
    int s, ans;
    vector<int> s_idx;
    s = 0;
    for(int i=0; i<n; i++) if(i%(2*w) < w) s += c[i];
    for(int i=0; i<n; i++) if(i%(2*w) == 0) s_idx.push_back(i);
    ans = s;

    cout << "init ans: " << ans << endl;
    for(auto idx:s_idx) cout << "init idx: " << idx << endl;
    
    for(int i=0; i<n/(2*w); i++){
        for(int j=0; j<s_idx.size(); j++){
            cout << "idx: " << s_idx[j] << endl;
            if(s_idx[j] < n) s -= c[s_idx[j]];
            if(s_idx[j]+w < n) s += c[s_idx[j]+w];
            s_idx[j]++;
        }
        ans = min(ans, s);
    }

    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;
    for(int i=0; i<t; i++) solve();
    
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;
int main(){
    string s;
    cin >> s;
    vector<int> a, b, c;
    for(int i=0; i<s.size(); i++){
        if(s[i] == 'A') a.push_back(i);
        else if (s[i] == 'B') b.push_back(i);
        else c.push_back(i);
    }

    int a_idx = 0,  b_idx = 0, c_idx = 0;
    int ans = 0;

    if(a.size() == 0 || b.size() == 0 || c.size() == 0){
        cout << ans << endl;
        return 0;
    }
    while(a_idx < a.size() && b_idx < b.size() && c_idx < c.size()){
        while(a[a_idx] > b[b_idx]) b_idx++;
        while(b[b_idx] > c[c_idx]) c_idx++;
        
        if(a_idx < a.size() && b_idx < b.size() && c_idx < c.size()) ans++;
        else break;
        
        a_idx++;
        b_idx++;
        c_idx++;
    }
    
    cout << ans << endl;
    return 0;


}
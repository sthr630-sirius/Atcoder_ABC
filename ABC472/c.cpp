#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n, m;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i=0; i<n; i++) cin >> a[i] >> b[i];
    cin >> m;
    vector<string> s(m);
    for(int i=0; i<m; i++) cin >> s[i];

    vector<vector<bool>> table(n, vector<bool>(26, false));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(s[j].size() == a[i]) table[i][int(s[j][b[i]-1]-'a')] = true;
        }
    }

    bool is_ok;
    for(int i=0; i<m; i++){
        string target_str = s[i];
        is_ok = true;
        if(target_str.size() == n){
            for(int j=0; j<n; j++){
                if(table[j][int(s[i][j]-'a')]) continue;
                else is_ok = false;
            }
        }else{
            is_ok = false;
        }
        
        if(is_ok) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;

}
#include<iostream>
#include<vector>
using namespace std;
int main(){
    string s;
    cin >> s;
    int n = s.size();
    vector<int> cnt(26);
    vector<long long> palin(26);
    vector<bool> is_included(26, false);
    long long ans = 0;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<26; j++){
            if(int(s[i])-65 == j){
                is_included[j] = true;
                ans += palin[j];
                palin[j] += cnt[j];
                cnt[j]++;
            }else{
                if(is_included[j]) palin[j] += cnt[j];
            }
        }
    }

    cout << ans << endl;

    return 0;
}
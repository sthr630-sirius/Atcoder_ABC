#include<iostream>
#include<vector>
using namespace std;
int main(){
    string s;
    cin >> s;    
    vector<vector<int>> dp(s.size(), vector<int>(26, 0));
    int CONST = 998244353;
    int ans = 0;
    int idx;

    idx = s[0]-'a';
    dp[0][idx] = 1;

    for(int i=1; i<s.size(); i++){
        for(int j=0; j<26; j++){
            idx = s[i]-'a';
            dp[i][idx] = (dp[i][idx] + dp[i-1][j])%CONST;
            if(j == idx) dp[i][j] = (dp[i][j] + 1)%CONST;
            else dp[i][j] = dp[i-1][j];
        }
    }

    for(int i=0; i<26; i++) ans = (ans + dp[s.size()-1][i])%CONST;
    cout << ans << endl;

    return 0;
}
#include<iostream>
#include<vector>
#include<deque>
using namespace std;
int main(){
    int n, s;
    cin >> n >> s;
    vector<int> h(n+1, 0), t(n+1, 0);
    vector<vector<bool>> dp(n+1, vector<bool>(s+1, false));
    deque<string> path;

    for(int i=1; i<n+1; i++) cin >> h[i] >> t[i];

    dp[0][0] = true;

    for(int i=1; i<n+1; i++){
        for(int j=1; j<s+1; j++){
            if(j-h[i]>=0 && dp[i-1][j-h[i]]) dp[i][j] = true;
            if(j-t[i]>=0 && dp[i-1][j-t[i]]) dp[i][j] = true;
        }
    }

    if(dp[n][s]){
        cout << "Yes" << endl;
        
        int num = s;
        for(int i=n; i>0; i--){
            if(num-h[i]>=0 && dp[i-1][num-h[i]]){
                path.push_front("H");
                num -=h[i];
            }else{
                path.push_front("T");
                num -= t[i];
            }
        }
        
        while(!path.empty()){
            cout << path.front();
            path.pop_front();
        }

    }else{
        cout << "No" << endl;
    }

    return 0;
}
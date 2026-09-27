#include<iostream>
#include<vector>
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<int> r(n);
    for(int i=0; i<n; i++) cin >> r[i];

    int inf, min_r, max_r;
    inf = 90000000;
    min_r = *min_element(r.begin(), r.end());
    max_r = *max_element(r.begin(), r.end());
    for(int i=0; i<n; i++) r[i] -= min_r;
        
    vector<vector<int>> dp(max_r, vector<int>(n, inf));

    /*
    for(auto dpi:dp){
        for(auto dpij:dpi) cout << dpij << ", ";
        cout << endl;
    }
    cout << " --------------- " << endl;
    */

    for(int i=r[0]; i>=0; i--) dp[i][0] = r[0]-i;

    for(int j=1; j<n; j++){
        for(int i=r[j]; i>=0; i--){
            if(i+1 < max_r) dp[i][j] = min(dp[i+1][j-1]+r[j]-i, dp[i][j]);
            dp[i][j] = min(dp[i][j-1]+r[j]-i, dp[i][j]);
            if(i-1 >= 0) dp[i][j] = min(dp[i-1][j-1]+r[j]-i, dp[i][j]);
        }
    }

    /*
    for(auto dpi:dp){
        for(auto dpij:dpi) cout << dpij << ", ";
        cout << endl;
    }
    */

    int ans;
    ans = 9000000;
    for(int i=0; i<max_r; i++) ans = min(ans, dp[i][n-1]);
    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        solve();
    }

    return 0;
}
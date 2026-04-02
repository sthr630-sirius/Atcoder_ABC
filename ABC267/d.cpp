#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n+1, 0);
    for(int i=1; i<n+1; i++) cin >> a[i];

    long long INF = -1e18;
    //long long INF = -100;
    vector<vector<long long>> dp(m+1, vector<long long>(n+1, INF));

    for(int j=0; j<n+1; j++) dp[0][j] = 0;

    for(int j=1; j<n+1; j++){
        for(int i=1; i<min(j+1, m+1); i++){
            dp[i][j] = max(dp[i][j-1], dp[i-1][j-1]+i*a[j]);
        }
    }
   
    cout << dp[m][n] << endl;

    return 0;
}

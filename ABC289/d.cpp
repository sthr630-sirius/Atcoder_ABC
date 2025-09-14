#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n, m, x;
    cin >> n;
    vector<int> a(n+1, 0);
    for(int i=1; i<n+1; i++) cin >> a[i];

    cin >> m;
    vector<int> b(m+1, 0);
    for(int i=1; i<m+1; i++) cin >> b[i];

    cin >> x;
    vector<int> dp(x+1, 0);

    dp[0] = 1;
    for(int i=1; i<m+1; i++) dp[b[i]] = 2;

    for(int i=1; i<x+1; i++){
        if(dp[i]==2) continue;
        for(int j=1; j<n+1; j++){
            if(i-a[j]>=0 && dp[i-a[j]]==1) dp[i] = 1;
        }
    }
    
    if(dp[x] == 1) cout << "Yes" << endl;
    else cout << "No" << endl;

    //for(auto dpi:dp) cout << dpi << ", ";
    //cout << endl;

    return 0;

}
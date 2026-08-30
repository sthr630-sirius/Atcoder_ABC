#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> dp;
    for(int i=0; i<n; i++) cin >> a[i];

    for(int i=0; i<n; i++){
        auto iter = dp.find(a[i]-1);
        if(iter == dp.end()) dp[a[i]] = 1;
        else dp[a[i]] = dp.at(a[i]-1)+1;
    }

    int ans  = 0;
    for(auto [key, value]:dp) ans = max(ans, value);
    cout << ans << endl;

    return 0;

}
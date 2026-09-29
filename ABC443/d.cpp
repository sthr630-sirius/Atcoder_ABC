#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void solve(){
    int n, min_r;
    cin >> n;
    vector<int> r(n), original_r(n);
    for(int i=0; i<n; i++) cin >> r[i];
    min_r = *min_element(r.begin(), r.end());
    for(int i=0; i<n; i++) r[i] -= min_r;
    for(int i=0; i<n; i++) original_r[i] = r[i];

    for(int i=1; i<n; i++) r[i] = min(r[i-1]+1, r[i]);
    for(int i=n-2; i>=0; i--) r[i] = min(r[i+1]+1, r[i]);

    long long ans;
    ans = 0;
    for(int i=0; i<n; i++) ans += original_r[i] - r[i];    
    cout << ans << endl;

}

int main(){
    int t;
    cin >> t;
    for(int i=0; i<t; i++) solve();

    return 0;
}
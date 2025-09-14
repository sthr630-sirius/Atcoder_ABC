#include<iostream>
#include<vector>
using namespace std;
int main(){
    int base;
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    vector<int> dp_t(n, 0), dp_b(n, 0); 
    for(int i=0; i<n; i++) cin >> a[i] >> b[i];
    
    dp_t[0] = 1;
    dp_b[0] = 1;

    base = 998244353;

    for(int i=1; i<n; i++){
        if(a[i-1] != a[i]) dp_t[i] = (dp_t[i] + dp_t[i-1])%base;
        if(b[i-1] != a[i]) dp_t[i] = (dp_t[i] + dp_b[i-1])%base;
        if(a[i-1] != b[i]) dp_b[i] = (dp_b[i] + dp_t[i-1])%base;
        if(b[i-1] != b[i]) dp_b[i] = (dp_b[i] + dp_b[i-1])%base;
    }

    cout << (dp_t[n-1] + dp_b[n-1])%base << endl;

    /*
    for(auto dp_ti:dp_t) cout << dp_ti << ", ";
    cout << endl;
    for(auto dp_bi:dp_b) cout << dp_bi << ", ";
    cout << endl;
    */
    return 0;

}
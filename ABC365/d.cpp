#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    string aoki;
    cin >> n >> aoki;
    aoki = "*" + aoki;

    vector<int> dp_r(n+1, -1), dp_s(n+1, -1), dp_p(n+1, -1);

    dp_r[0] = 0;
    dp_s[0] = 0;
    dp_p[0] = 0;
    
    for(int i=1; i<n+1; i++){
        auto c = aoki[i];
        if(c == 'R'){
            dp_r[i] = max(dp_s[i-1], dp_p[i-1]);
            dp_s[i] = -1;
            dp_p[i] = max(dp_s[i-1], dp_r[i-1])+1;
            //cout << dp_r[i] << ", " << dp_s[i] << ", " << dp_p[i] << endl;
        }else if(c == 'S'){
            dp_r[i] = max(dp_s[i-1], dp_p[i-1])+1;
            dp_s[i] = max(dp_r[i-1], dp_p[i-1]);
            dp_p[i] = -1;
            //cout << dp_r[i] << ", " << dp_s[i] << ", " << dp_p[i] << endl;
        }else if(c == 'P'){
            dp_r[i] = -1;
            dp_s[i] = max(dp_r[i-1], dp_p[i-1])+1;
            dp_p[i] = max(dp_r[i-1], dp_s[i-1]);
            //cout << dp_r[i] << ", " << dp_s[i] << ", " << dp_p[i] << endl;
        }
    }

    auto ans = max(dp_r[n], dp_s[n]);
    ans = max(ans, dp_p[n]);
    cout << ans << endl;
    
    return 0;

}
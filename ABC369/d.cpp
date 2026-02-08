#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> a(n+1, 0);
    // n回目を終え、モンスターを倒したのが偶数回の経験値：dp_e[n]
    // n回目を終え、モンスターを倒したのが奇数回の経験値：dp_o[n]
    vector<long long> dp_e(n+1, 0), dp_o(n+1, 0);

    for(int i=1; i<n+1; i++) cin >> a[i];
    dp_e[0] = 0;
    dp_o[0] = 0;
    dp_e[1] = 0;
    dp_o[1] = a[1];

    for(int i=2; i<n+1; i++){
        dp_e[i] = max(dp_e[i-1], dp_o[i-1]+a[i]*2);
        dp_o[i] = max(dp_o[i-1], dp_e[i-1]+a[i]);
    }

    cout << max(dp_e[n], dp_o[n]) << endl;

    return 0;
}
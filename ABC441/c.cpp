#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n, k;
    long long x;
    cin >> n >> k >> x;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    sort(a.rbegin(), a.rend());

    bool is_ok;
    int cnt;
    long long total_sake;
    is_ok = false;
    cnt = n-k;
    total_sake = 0; 
    for(int i=n-k; i<n; i++){
        total_sake += a[i];
        cnt++;
        if(total_sake >= x){
            is_ok = true;
            break;
        }
    }

    if(is_ok) cout << cnt << endl;
    else cout << -1 << endl;

    return 0;

}
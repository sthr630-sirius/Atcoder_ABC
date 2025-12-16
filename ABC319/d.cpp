#include<iostream>
#include<vector>
using namespace std;

bool check_width(long long h, int m, vector<int>& a){
    long long row_len;
    int cnt;

    cnt = 1;
    row_len = a[0];

    for(int i=1; i<a.size(); i++){
        if(row_len+1+a[i] <= h){
            row_len += 1+a[i];
        }else{
            row_len = a[i];
            cnt++;
        }
    }

    if(cnt <= m) return true;
    else return false;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
 
    long long ng, ok, mid;
    ng = 0;
    ok = 1000000000000000;
    while(ng+1<ok){
        mid = (ng+ok)/2;
        if(check_width(mid, m, a)) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;

    return 0;
}
#include<iostream>
#include<vector>
using namespace std;
int upper_idx(vector<int> &a, int target){
    // target以下を満たす最大のaの要素のindex
    int ok, ng, mid;
    ok = -1;
    ng = a.size();
    while(ok+1<ng){
        mid = (ok + ng) / 2;
        if(a[mid] <= target) ok = mid;
        else ng = mid;
    }

    return ok;
}

int lower_idx(vector<int> &a, int target){
    // target以上を満たす最小のaの要素のindex
    int ng, ok, mid;
    ng = -1;
    ok = a.size();
    while(ng+1<ok){
        mid = (ng + ok) / 2;
        if(target <= a[mid]) ok = mid;
        else ng = mid;
    }

    return ok;
}


int main(){
    int n, q;
    cin >> n;
    vector<int> x(n+1, -1000000001), p(n+1, 0);
    vector<long long> sum_p(n+1, 0);
    for(int i=1; i<n+1; i++) cin >> x[i];
    for(int i=1; i<n+1; i++) cin >> p[i];
    for(int i=1; i<n+1; i++) sum_p[i] = sum_p[i-1] + p[i];
    
    cin >> q;
    int l, r;
    for(int i=0; i<q; i++){
        cin >> l >> r;
        auto u_idx = upper_idx(x, r);
        auto l_idx = lower_idx(x, l);
        cout << sum_p[u_idx] - sum_p[l_idx-1] << endl;
    }

    return 0;
}
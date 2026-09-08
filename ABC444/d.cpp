#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<deque>
using namespace std;
int binary_search_idx(vector<int> &a, int target){
    int is_ng, is_ok, mid;
    is_ng = -1;
    is_ok = a.size();
    
    while(is_ng+1 < is_ok){
        mid = (is_ng + is_ok)/2;
        if(target <= a[mid]) is_ok = mid;
        else is_ng = mid;
    }

    return is_ok;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    set<int> b;
    
    for(int i=0; i<n; i++){
        cin >> a[i];
        b.insert(a[i]);
    }
    sort(a.begin(), a.end());

    int max_a;
    max_a = *max_element(a.begin(), a.end());
    vector<int> digit_sum(max_a, -1);
    for(int i=0; i<max_a; i++){
        if(b.find(i+1) == b.end()) continue;
        int idx = binary_search_idx(a, i+1);
        digit_sum[i] = n-idx;
    }

    for(int i=max_a-2; i>=0; i--){
        if(digit_sum[i] == -1) digit_sum[i] = digit_sum[i+1];
    }

    deque<int> ans;
    int d;
    d = 0;
    for(int i=0; i<max_a; i++){
        ans.push_back((digit_sum[i]+d)%10);
        d = (digit_sum[i]+d)/10;
    }

    while(d>0){
        ans.push_back(d%10);
        d = d/10;
    }

    while(ans.size()){
        cout << ans.back();
        ans.pop_back();
    }
    cout << endl;

    return 0;
    
}
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool is_atcoder_rico(vector<int>&a, int l){
    bool is_ok;
    int length;    
    is_ok = true;
    length = a.size();

    if(length%2 == 0){
        for(int i=0; i<length; i++){
            if(a[i]+a[(length-1)-i] == l){
                continue;
            }else{
                is_ok = false;
                break;
            }
        }
    }else{
        is_ok = false;
    }

    return is_ok;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    int l;
    vector<int> ans;

    l = a[0]+a[n-1];
    if(is_atcoder_rico(a, l)) ans.push_back(l);

    l = a.back();
    while(a.back() == l) a.pop_back();
    if(a.size() == 0){
        ans.push_back(l);
    }else{
        if(is_atcoder_rico(a, l)) ans.push_back(l);
    }

    sort(ans.begin(), ans.end());
    for(auto ansi:ans) cout << ansi << " ";
    cout << endl;

    return 0;

}
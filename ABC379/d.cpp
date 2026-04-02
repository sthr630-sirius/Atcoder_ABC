#include<iostream>
#include<vector>
using namespace std;
int binary_upper(int ok_init, long long target, vector<long long>& plant){
    int ok, ng, mid;
    ok = ok_init;
    ng = plant.size();
    
    while(ok+1<ng){
        mid = (ok + ng) / 2;
        if(target <= plant[mid]) ok = mid;
        else ng = mid;
    }

    return ok;

}


int main(){
    int q;
    cin >> q;
    vector<long long> plants;
    int query_no, t, h;
    
    vector<long long> plant;
    long long hight;
    long long ans;
    int ok_idx, ok_prev;
    
    hight = 0;
    ans = 0;
    ok_prev = -1;

    for(int i=0; i<q; i++){
        cin >> query_no;
        if(query_no == 1){
            plant.push_back(-hight);
        }else if(query_no == 2){
            cin >> t;
            hight += t;
        }else{
            cin >> h;
            ok_idx = binary_upper(ok_prev, -hight+h, plant);
            ans = ok_idx - ok_prev;
            ok_prev = ok_idx;
            cout << ans << endl;

        }
    }

    return 0;

}
#include<iostream>
#include<vector>
using namespace std;
int main(){
    long long L; 
    int n1, n2;
    cin >> L >> n1 >> n2;
    vector<vector<long long>> info_1(n1, vector<long long>(2, 0)), info_2(n2, vector<long long>(2, 0));
    int v;
    long long l;
    for(int i=0; i<n1; i++){
        cin >> v >> l;
        info_1[i][0] = v;
        info_1[i][1] = l;
    }
    for(int i=0; i<n2; i++){
        cin >> v >> l;
        info_2[i][0] = v;
        info_2[i][1] = l;
    }

    int idx_1, idx_2;
    long long pos_1, pos_2;
    long long val_1, val_2;

    idx_1 = 0;
    idx_2 = 0;
    pos_1 = info_1[idx_1][1]-1;
    pos_2 = info_2[idx_2][1]-1;
    val_1 = info_1[idx_1][0];
    val_2 = info_2[idx_2][0];

    long long ans = 0;

    if(val_1 == val_2) ans += min(pos_1, pos_2)+1;

    while(pos_1 < L-1 || pos_2 < L-1){
        if(pos_1 <= pos_2){
            idx_1++;
            long long prev_pos;
            prev_pos = pos_1;
            pos_1 += info_1[idx_1][1];
            val_1 = info_1[idx_1][0];
            if(val_1 == val_2) ans += min(pos_2, pos_1) - prev_pos;
            
        }else{
            idx_2++;
            long long prev_pos;
            prev_pos = pos_2;
            pos_2 += info_2[idx_2][1];
            val_2 = info_2[idx_2][0];
            if(val_1 == val_2) ans += min(pos_1, pos_2) - prev_pos;
            
        }
    }

    cout << ans << endl;

    return 0;
}
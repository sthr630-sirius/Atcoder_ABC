#include<iostream>
#include<vector>
#include<set>
using namespace std;
int main(){
    int q;
    cin >> q;
    long long x;
    int q_num, k;
    multiset<long long> number_box;
    
    for(int i=0; i<q; i++){
        cin >> q_num >> x;
        if(q_num == 1){
            number_box.insert(x);
        }else if(q_num == 2){
            cin >> k;
            bool is_ok = true;
    
            auto iter = number_box.upper_bound(x);        
            for(int i=0; i<k; i++){
                if(iter == number_box.begin()){
                    is_ok = false;
                    break;
                }
                --iter;
            }

            if(is_ok) cout << *iter << endl;
            else cout << -1 << endl;    
        }else if(q_num == 3){
            cin >> k;
            bool is_ok = true;
    
            auto iter = number_box.lower_bound(x);        
            for(int i=0; i<k-1; i++){
                if(iter == number_box.end()){
                    is_ok = false;
                    break;
                }
                ++iter;
            }

            if(is_ok && iter != number_box.end()) cout << *iter << endl;
            else cout << -1 << endl;
        }
    }

    return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n, q;
    string s;
    int t, x;
    char c;
    cin >> n >> s >> q;
    vector<int> query_t(q), query_x(q);
    vector<char> query_c(q);

    int last_exchage_evetnts_idx = -1;

    for(int i=0; i<q; i++){
        cin >> query_t[i] >> query_x[i] >> query_c[i];
    }

    for(int i=q-1; i>=0; i--){
        if(query_t[i] == 2 || query_t[i] == 3){
            last_exchage_evetnts_idx = i;
            break;
        }
    }

    for(int i=0; i<q; i++){
        t = query_t[i];
        x = query_x[i];
        c = query_c[i];
        if(t == 1){
            s[x-1] = c;
        }else{
            if(i == last_exchage_evetnts_idx){
                if(t == 2){
                    transform(s.begin(), s.end(), s.begin(), ::tolower);
                }
                if(t == 3){
                    transform(s.begin(), s.end(), s.begin(), ::toupper);
                } 
            }
        }
    }

    cout << s << endl;
    return 0;
}
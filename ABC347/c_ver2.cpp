#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> d(n);
    for(int i=0; i<n; i++){
        cin >> d[i];
        d[i] = d[i]%(a+b);
    }

    sort(d.begin(), d.end());
    for(int i=0; i<n; i++) d.push_back(d[i]+(a+b));
   
    bool is_ok = false;
    for(int i=0; i<d.size()-1; i++){
        if(d[i+1]-d[i] > b){
            is_ok = true;
            break;
        }
    }

    cout << (is_ok ? "Yes" : "No") << endl;

    return 0;

}
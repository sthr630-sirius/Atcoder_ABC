#include<iostream>
#include<vector>
#include<set>
using namespace std;
int main(){
    int n, Q;
    cin >> n >> Q;

    vector<set<int>> cards(200001);
    vector<multiset<int>> boxes(n+1);
    
    for(int k=0; k<Q; k++){
        int q, i, j;
        cin >> q;
        if(q==1){
            cin >> i >> j;
            cards[i].insert(j);
            boxes[j].insert(i);
        }else if(q==2){
            cin >> i;
            for(auto c:boxes[i]) cout << c << " ";
            cout << endl;
        }else{
            cin >> i;
            for(auto b:cards[i]) cout << b << " ";
            cout << endl;
        }
    }

    return 0;
}
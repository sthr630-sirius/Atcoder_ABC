#include<iostream>
#include<vector>
using namespace std;
int main(){
    int h, w;
    cin >> h >> w;
    vector<vector<string>> field(h, vector<string>(w, "."));
   
    for(int i=0; i<h; i++){
        if(i == 0 || i == h-1){
            for(int j=0; j<w; j++){
                field[i][j] = "#";
            }
        }
        if(i > 0 && i < h-1){
            for(int j=0; j<w; j++){
                if(j == 0 || j == w-1){
                    field[i][j] = "#";
                }
                if(j > 0 && j < w-1){
                    field[i][j] = "."; 
                }
            }
        }
    }

    for(auto fi : field){
        for(auto fii :fi){
            cout << fii;
        }
        cout << endl;
    }

    return 0;

}
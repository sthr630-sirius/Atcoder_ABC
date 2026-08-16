#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    string s;
    cin >> n >> s;

    vector<int> circle(n, 0), cross(n, 0);

    if(s[0] == 'o') circle[0] = 1;
    else cross[0] = 1;

    for(int i=1; i<n; i++){
        if(s[i] == 'o'){
            circle[i] = circle[i-1]+1;
            cross[i] = cross[i-1];
        }else{
            circle[i] = circle[i-1];
            cross[i] = cross[i-1]+1;
        }
    }
    
    for(int i=0; i<n; i++){
        int ok, ng, mid, target;
        ok = i;
        ng = n;
        target = circle[i]+cross[i];
        while(ok+1<ng){
            mid = (ok+ng)/2;
            if(cross[mid]<target) ok = mid;
            else ng = mid;
        }
        cout << min(ng+1, n) << endl;
    }

    return 0;

}
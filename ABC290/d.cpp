#include<iostream>
#include<vector>
using namespace std;
int gcd(int x, int y){
    if(x%y == 0) return y;
    else return gcd(y, x%y);
}


int main(){
    int t;
    cin >> t;
    int n, d, k;
    int g;
    int group, block, ans;
    for(int i=0; i<t; i++){
        cin >> n >> d >> k;

        g = gcd(n, d);

        group = (k-1)/(n/g);
        block = (k-1)%(n/g);
        ans = group + (long long)(block*d)%n; 

        cout << ans << endl;

    }

    return 0;
}
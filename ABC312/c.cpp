#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int binary_search(int target, vector<int>& x){
    int ok, ng, mid;
    ok = -1;
    ng = x.size();

    while(ok+1<ng){
        mid = (ok+ng) / 2;
        if(x[mid] >= target) ok = mid;
        else ng = mid;
    }
    return ok+1;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<m; i++) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());
    
    int buyer, seller;
    int ans;
    vector<int> price(n);

    for(int i=0; i<n; i++){
        buyer = i+1;
        seller = binary_search(a[i], b);
        
        if(seller == 0){
            price[i] = b[0]+1;
        }else if(buyer >= seller){
            price[i] = a[i];
        }else{
            price[i] = b[i+1]+1;
        } 
    }

    ans = *min_element(begin(price), end(price));
    cout << ans << endl;
    return 0;

}
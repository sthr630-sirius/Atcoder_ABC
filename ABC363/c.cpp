#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n, k;
    string s;
    int ans = 0;
    string target, reverse_target;
    
    cin >> n >> k;
    cin >> s;
    sort(s.begin(), s.end());

    do{
        bool is_palindrome = false;

        for(int i=0; i<n-k+1; i++){
            target = s.substr(i, k);
            reverse_target = s.substr(i, k);
            
            reverse(reverse_target.begin(), reverse_target.end());
            
            if(target == reverse_target) is_palindrome = true;
        }
        
        if(! is_palindrome) ans++;

    }while(next_permutation(s.begin(), s.end()));

    cout << ans << endl;
    return 0;
}
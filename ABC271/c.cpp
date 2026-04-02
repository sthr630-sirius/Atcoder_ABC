#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<long long> c;
    deque<long long> b;

    for(int i=0; i<n; i++) cin >> a[i];   
    sort(a.begin(), a.end());
    

    c.push_back(a[0]);
    for(int i=1; i<n; i++){
        if(a[i-1] == a[i]) c.push_back(a[i]+2e9);
        else c.push_back(a[i]);
    }
    sort(c.begin(), c.end());

    for(int i=0; i<n; i++) b.push_back(c[i]);

    int ans = 0;
    int book_number = 0;

    for(int i=0; i<n; i++){
        if(b.empty()){
            cout << ans << endl;
            return 0;
        }

        book_number = b.front();
        
        while(ans < book_number){
            if(ans+1 < book_number){
                if(b.size() < 2){
                    cout << ans << endl;
                    return 0;
                }else{
                    b.pop_back();
                    b.pop_back();
                }
            }
            ans++;
        }

        if(b.empty()){
            cout << ans << endl;
            return 0;
        }
        b.pop_front();
    }

    cout << ans << endl;
    return 0;

}

/*
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<long long> b;

    for(int i=0; i<n; i++) cin >> a[i];   
    sort(a.begin(), a.end());
    

    b.push_back(a[0]);
    for(int i=1; i<n; i++){
        if(a[i-1] == a[i]) b.push_back(a[i]+3e8);
        else b.push_back(a[i]);
    }

    sort(b.begin(), b.end());

    int ans = 0;
    int back_idx = n;

    for(int i=0; i<n; i++){
        if(i == back_idx) break;
        while(ans < b[i]){
            if(ans+1 < b[i]){
                if(i+1 < back_idx){
                    ans++;
                    back_idx -= 2;
                }else{
                    cout << ans << endl;
                    return 0;
                }
            }else{
                ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;

}
*/
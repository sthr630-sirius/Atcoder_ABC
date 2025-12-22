#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<long long> b(n);
    long long all_sum = 0;
    long long ans = 0;
    all_sum = 0;
    for(int i=0; i<n; i++){
        cin >> a[i];
        all_sum += a[i];
    }

    for(int i=0; i<n; i++) b[i] = all_sum / n;
    for(int i=0; i<all_sum%n; i++) b[i]++;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for(int i=0; i<n; i++) ans += abs(a[i]-b[i]);
    ans = ans / 2;

    cout << ans << endl;

    return 0;
}
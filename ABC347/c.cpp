#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> d(n), plan;
    for(int i=0; i<n; i++) cin >> d[i];

    for(int i=0; i<n; i++) plan.push_back(d[i]%(a+b));
    sort(plan.begin(), plan.end());

    int min_d, max_d, delta;
    
    min_d = *min_element(plan.begin(), plan.end());
    max_d = *max_element(plan.begin(), plan.end());

    delta = 1;
    for(int i=0; i<n-1; i++){
        delta = max(delta, plan[i+1] - plan[i]);
    }

    if(max_d - min_d < a || delta > b) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;

}
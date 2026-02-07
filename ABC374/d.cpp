#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<bitset>
using namespace std;
int main(){
    int n, s, t;
    cin >> n >> s >> t;
    vector<vector<pair<int, int>>> point(n);
    int a, b, c, d;
    double ans;
    double time_move, time_mark;
    ans = 100000.0;
    time_mark = 0.0;
    for(int i=0; i<n; i++){
        cin >> a >> b >> c >> d;
        point[i].push_back({a, b});
        point[i].push_back({c, d});
        time_mark += sqrt(pow(c-a,2) + pow(d-b, 2))/t;
    }

    vector<int> order;
    pair<double, double> s_point, e_point;

    for(int i=0; i<n; i++) order.push_back(i);

    do{
        for(int bit=0; bit<1<<n; bit++){
            time_move = 0.0;
            s_point = {0.0, 0.0};
            for(int i=0; i<n; i++){
                if(bit>>i & 1) e_point = point[order[i]][0];
                else e_point = point[order[i]][1];
                time_move += sqrt(pow(e_point.first-s_point.first, 2) + pow(e_point.second-s_point.second, 2))/s;
                if(bit>>i & 1) s_point = point[order[i]][1];
                else s_point = point[order[i]][0];
            }
            ans = min(ans, time_move + time_mark);
        }
    }while(next_permutation(order.begin(), order.end()));

    cout << ans << endl;
    printf("%10.20f", ans);

    return 0;
}

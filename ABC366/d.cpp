#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n, q;
    cin >> n;
    int lx, rx, ly, ry, lz, rz;
    int cube_large, cube_small;
    int ans;

    vector<vector<vector<int>>> a(n+1, vector<vector<int>>(n+1, vector<int>(n+1, 0)));
    vector<vector<vector<int>>> c(n+1, vector<vector<int>>(n+1, vector<int>(n+1, 0)));

    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            for(int k=1; k<n+1; k++){
                cin >> a[i][j][k];
                a[i][j][k]++;
            }
        }
    }

    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            for(int k=1; k<n+1; k++){
                c[i][j][k] = c[i][j][k-1] + a[i][j][k];
            }
        }
    }

    for(int i=1; i<n+1; i++){
        for(int k=1; k<n+1; k++){
            for(int j=1; j<n+1; j++){
                c[i][j][k] += c[i][j-1][k];
            }
        }
    }

    for(int j=1; j<n+1; j++){
        for(int k=1; k<n+1; k++){
            for(int i=1; i<n+1; i++){
                c[i][j][k] += c[i-1][j][k];
            }
        }
    }

    cin >> q;
    for(int i=0; i<q; i++){
        cin >> lx >> rx >> ly >> ry >> lz >> rz;
        cube_large = c[rx][ry][rz] - c[rx][ry][lz-1] - c[rx][ly-1][rx] + c[rx][ly-1][lz-1];
        cube_small = c[lx-1][ry][rz] - c[lx-1][ry][lz-1] - c[lx-1][ly-1][rx] + c[lx-1][ly-1][lz-1];
        ans = cube_large - cube_small;
        cout << ans << endl;
    }

    /*
    cout << endl;
    for(int i=1; i<n+1; i++){
        cout << "------a-------" << endl;
        for(int j=1; j<n+1; j++){
            for(int k=1; k<n+1; k++){
                cout << a[i][j][k] << ", ";
            }
            cout << endl;
        }
        cout << endl << endl;

        cout << "------c-------" << endl;
        for(int j=1; j<n+1; j++){
            for(int k=1; k<n+1; k++){
                cout << c[i][j][k] << ", ";
            }
            cout << endl;
        }
        cout << endl << endl;
    }
    */

    return 0;

}
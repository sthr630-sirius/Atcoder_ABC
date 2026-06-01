#include<iostream>
#include<set>
using namespace std;

int main(){
    set<pair<int, int>> diary;

    diary.insert({1, 7});
    diary.insert({3, 3});
    diary.insert({5, 5});
    diary.insert({7, 7});
    diary.insert({9, 9});

    int m, d;

    cin >> m >> d;
    if(diary.find({m, d}) != diary.end()){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
   
   return 0;
}
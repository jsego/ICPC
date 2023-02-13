
//
// Created by js on 13/02/23.
//

#include<bits/stdc++.h>

using namespace std;

int main(){
    int N; cin >> N;
    while(N--){
        int t; cin >> t;
        vector<int> v(11,-1); v[0] = 0;
        for(int i = 0, b, d; i < t; i++) {
            cin >> b >> d;
            v[d] = max(v[d], b);
        }
        if(any_of(v.begin(),v.end(),[](int a){return a == -1;}))
            cout << "MOREPROBLEMS" << endl;
        else cout << accumulate(v.begin(),v.end(), 0) << endl;
    }
}
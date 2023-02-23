//
// Created by js on 6/02/23.
//
#include<bits/stdc++.h>

using namespace std;

int main(){
    int N;
    while(cin >> N){
        int max_cakes = 1000000; // some infinite value
        int required, available;
        for(int i = 0; i < N; i++){
            cin >> required >> available;
            max_cakes = min(max_cakes, available / required);
        }
        cout << max_cakes << "\n";
    }
}
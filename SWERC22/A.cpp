//
// Created by js on 19/02/23.
//
#include<bits/stdc++.h>

using namespace std;

int main(){
    int T; cin >> T;
    for(int t = 0; t < T; t++){
        int N; cin >> N;
        int last = 0, next, counter = 0;
        for(int i = 0; i < N; i++){
            cin >> next;
            counter += (next-last)/120;
            last = next;
        }
        counter += (1440 - next)/120;
        cout << (counter>1?"YES":"NO") << endl;
    }
}
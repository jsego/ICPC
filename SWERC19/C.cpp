//
// Created by js on 31/01/23.
//
#include<bits/stdc++.h>

using namespace std;

int S[1000001];

int main(){
    int N;
    while(cin >> N){
        string X; int num_counter = 0;
        for(int i = 0; i < N; i++){
            cin >> X;
            if(X[0] == '-') continue;
            if(X.size() > 7 or (X.size() == 7u and X != "1000000") ) continue;
            stringstream ss(X);
            ss >> S[num_counter++];
        }
        if(num_counter == 0 ) cout << 0 << endl;
        else{
            sort(S, S+num_counter);
            bool found = false;
            for(int i = 0; i < num_counter; i++){
                if(i != S[i]){
                    cout << i << endl;
                    found = true;
                    break;
                }
            }
            if(not found) cout << num_counter << endl;
        }
    }
}
//
// Created by js on 31/01/23.
//

#include<bits/stdc++.h>

using namespace std;

string A[200001];

int main(){
    int N;
    while(cin>>N){
        for(int i=0; i < N; i++)
            cin >> A[i];
        sort(A, A+N);
        string sol = A[0];
        int rep = 1, max_rep = 1;
        for(int i = 1; i < N; i++){
            if(A[i] != A[i-1]){
                if(rep > max_rep){
                    sol = A[i-1];
                    max_rep = rep;
                }
                rep = 1;
            }
            else rep++;
        }
        if(rep > max_rep){ // check if last element is the maximum
            sol = A[N-1];
            max_rep = rep;
        }
        if(max_rep*2 > N) cout << sol << endl;
        else cout << "NONE" << endl;
    }
}
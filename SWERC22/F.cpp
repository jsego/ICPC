//
// Created by js on 19/02/23.
//
#include<bits/stdc++.h>

using namespace std;

int main(){
    int T; cin >> T;
    for(int t = 0; t < T; t++){
        int N, M, a, b; cin >> N >> M;
        vector<int> degree(N+1, 0);
        vector<pair<int,int>> edges;
        for(int m = 0; m < M; m++){
            cin >> a >> b;
            edges.emplace_back(make_pair(a,b));
            degree[a]++; degree[b]++;
        }
        if(M*2 == N*(N-1)){ // Complete graph
            cout << 3 << endl;
            int chosen_a = 1, chosen_b = 2;
            for(int m = 0; m < M; m++){
                cout << (m?" ":"");
                auto [a,b] = edges[m];
                if((a == chosen_a and b == chosen_b) or (a == chosen_b and b == chosen_a)) cout << 3;
                else if(a == chosen_a or b == chosen_a) cout << 1;
                else cout << 2;
            }cout << endl;
        }
        else{ // some node with degree < N-1
            cout << 2 << endl; // k = 2
            int chosen = -1;
            for(int m = 0; m < M; m++){
                cout << (m?" ":"");
                auto [a,b] = edges[m];
                if(chosen == -1 and degree[a] < N-1)  chosen = a;
                else if(chosen == -1 and degree[b] < N-1) chosen = b;

                if(chosen == a || chosen == b) cout << 1;
                else cout << 2;
            }
            cout << endl;
        }
    }
}
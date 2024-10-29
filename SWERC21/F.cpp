/*
 * F - Bottle Arrangements
 */
 
#include<bits/stdc++.h>

using namespace std;

int main(){
    int T; cin >> T; // test cases
    for(int t = 0; t  < T; t++){
        int N, M; cin >> N >> M; // bottles and critics
        int max_r = 0, max_w = 0, r, w;
        for(int m = 0; m < M; m++){
            cin >> r >> w;
            max_r = max(max_r, r);
            max_w = max(max_w, w);
        }
        if((max_r + max_w) > N) { cout << "IMPOSSIBLE" << endl; }
        else{
            cout << (max_r>0?string(max_r,'R'):"") << (max_r<N?string(N-max_r,'W'):"") << endl;
        }
    }
}

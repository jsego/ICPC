#include <bits/stdc++.h>

using namespace std;

int T[100001];

int main(){
    int N, P;
    while(cin >> N >> P){
        int a, b;
        for(int n=0; n<N; ++n) T[n] = 0;
        for(int n=0; n+1<N; ++n){
            cin >> a >> b;
            ++T[a]; ++T[b];
        }
        int leaves = 0;
        for(int n=0; n<N; ++n) leaves += (T[n] == 1);
        int res = (P/leaves) * 2;
        if(P%leaves == 1) res++;
        else if(P%leaves >= 2) res += 2;
        cout << res << endl;
    }
}
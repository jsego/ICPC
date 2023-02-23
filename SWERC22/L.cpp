//
// Created by js on 23/02/23.
//
#include<bits/stdc++.h>
#define LL long long

using namespace std;

LL p, m;

bool bin_search(LL a, LL b){
    // X = num of discarded + and - (they cancel each other); X <= min(+,-);
    // a*(p-X) == b*(m-X) // the rest of elements should be equivalent
    // a*p - b*m == a*X - b*X => a*p-b*m == (a-b)*X
    LL min_x = 0, max_x = min(p,m), mid_x;
    LL left = a*p-b*m;
    LL right = a-b;
    while(min_x <= max_x){
        mid_x = (min_x + max_x)/2; //cout << "MID_X: " << mid_x << " L: " << left << " R: " << mid_x*right << endl;
        if(left == mid_x * right) return true;
        if(right >= 0) {
            if (left > mid_x * right) min_x = mid_x + 1;
            else max_x = mid_x - 1;
        }
        else{
            if (left > mid_x * right) max_x = mid_x - 1;
            else min_x = mid_x + 1;
        }
    }
    return false;
}

int main(){
    int N;
    while(cin >> N){
        p = 0; m = 0; // pluses & minuses
        char c;
        for(int i = 0; i < N; ++i){
            cin >> c;
            (c=='+'?++p:++m);
        }
        int Q; cin >> Q;
        LL a, b;
        for(int q=0; q < Q; ++q){
            cin >> a >> b;
            bool solved = bin_search(a, b) or bin_search(b, a);
            cout << (solved?"YES":"NO") << endl;
        }
    }
}
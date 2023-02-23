//
// Created by js on 19/02/23.
//
#include<bits/stdc++.h>

using namespace std;

long long mcd(long long a, long long b){
    if(b == 0 ) return a;
    return mcd(b, a%b);
}

long long mcm(long long a, long long b){
    return a*b / mcd(a,b);
}

bool is_correct(long long p, long long m, long long fl, long long fr){
    auto times_pluses_left = p / fl;
    auto times_minus_right = m / fr;

    // Pluses left - Minus right
    auto min_reps = min(times_pluses_left, times_minus_right);
    auto remaining_p = p - min_reps * fl;
    auto remaining_m = m - min_reps * fr;

    if(remaining_m == remaining_p) return true;
    return false;
}

int main(){
    int N;
    while(cin >> N){
        long long p = 0, m = 0;
        char c;
        for(int i = 0; i < N; i++){
            cin >> c;
            if(c == '+') p++;
            else m++;
        }
        int Q; cin >> Q;
        long long l, r;
        for(int q = 0; q < Q; q++){
            cin >> l >> r;
            auto divi = mcm(l,r);
            auto cl = divi / l; // num of l symb
            auto cr = divi / r; // num of r symb
            // p + m == Q
            // x1 + x2 == p;
            // y1 + y2 == m
            // (x1 - y1) * l + (x2 - y2) * r == 0
            // (x1 - y1) * l = (y2 - x2) * r
            bool correct = false;
            if( p == m ) correct = true;
            else if(is_correct(p, m, cl, cr)) correct = true;
            else if(is_correct(p, m,cr,cl)) correct = true;
            cout<< (correct?"YES":"NO") << endl;
        }
    }
}
//
// Created by js on 14/02/23.
//

#include<bits/stdc++.h>

using namespace std;

#define LIM 100001

bool is_prime[LIM];
long long prime[LIM];
int total_primes = 0;
long long w, l, area;

void compute_primes(){
    for(int i = 0; i < LIM; i++) is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i < LIM; i++){
        if(not is_prime[i]) continue;
        prime[total_primes++] = i;
        for(int j = i+i; j < LIM; j+=i)
            is_prime[j] = false;
    }
}

bool is_valid(long long num){
    for(int i = -2; i < 1; i++){
        for(int j = -2; j < 1; j++){
            for(int m = -2; m < 1; m++){
                for(int n = -2; n < 1; n++){
                    if( ((w+i) + (w+j) + (l+m) + (l+n)) == area){
                        if( (w+i)%num != 0) continue;
                        if((w+j)%num != 0) continue;
                        if((l+m)%num != 0) continue;
                        if((l+n)%num != 0) continue;
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

void recur(long long num, vector<pair<long long, long long>> &factors, int idx, set<long long> &divisors){
    if(num > w or num > l or idx >= factors.size()) return;
    //cout << num << " " << w << " " << l << endl;
    auto d = num*factors[idx].first;
    if(factors[idx].second > 0 and d <= w and d <= l and is_valid(d) ){
        factors[idx].second--;
        divisors.insert(d);
        recur(d, factors, idx, divisors);
        factors[idx].second++;
    }
    recur(num, factors, idx+1, divisors);
}

int main(){
    compute_primes();
    //cout << total_primes << endl;

    int T; cin >> T;
    for(int t = 0; t < T; t++){
        cin >> w >> l;
        long long num = w*2 + l*2 - 4;
        area = num;
        vector<pair<long long,long long>> factors;
        for(int i = 0; i < total_primes; i++){
            long long expo = 0;
            while(num%prime[i] == 0) {
                expo++;
                num /= prime[i];
            }
            if(expo > 0){
                factors.emplace_back(make_pair(prime[i], expo));
            }
        }
        if(num > 1) factors.emplace_back(make_pair(num, 1));
        set<long long> divisors; divisors.insert(1);
        recur(1,factors,0,divisors);
        cout << divisors.size();
        for(const auto& d : divisors) {
            cout << " " << d;
        }
        cout << "\n";
    }
}
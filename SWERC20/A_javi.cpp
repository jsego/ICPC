//
// Created by js on 6/02/23.
//
#include<bits/stdc++.h>

using namespace std;

int main(){
    int N, K;
    while(cin >> N >> K){
        string line; getline(cin, line);
        map<string,pair<int,int>> M; // thing => (ocurrences, last index)
        for(int i = 0; i < N; i++){
            for(int j = 0; j < 3; j++){
                getline(cin, line);
                auto it = M.find(line);
                if(it == M.end()){
                    M[line] = make_pair(1,i*3+j);
                }
                else{
                    (it->second).first += 1;
                    (it->second).second = i*3+j;
                }
            }
        }
        vector<pair<pair<int,int>, string>> v;
        for(const auto& it : M){
            v.emplace_back(make_pair(it.second, it.first));
        }
        sort(v.rbegin(),v.rend());
        for(int k=0; k < min(K,(int)v.size()); k++){
            cout << v[k].second << "\n";
        }
    }
}
//
// Created by js on 23/02/23.
//
#include<bits/stdc++.h>
#define LL long long

using namespace std;

typedef struct _point{
    LL x, y;
    int idx;
    _point(){x=0L; y=0L; idx=-1;}
} Point;

LL double_area(Point &a, Point &b, Point &c){
    return (a.x*b.y + b.x*c.y + c.x*a.y) - (a.y*b.x + b.y*c.x + c.y*a.x);
}

pair<LL,int> best_play(vector<Point> &v){
    LL best_area = double_area(v[(int)v.size() - 1], v[0], v[1]);
    int best_pos = 0;
    LL current_area;
    for(int s = 1; s < (int)v.size(); ++s){
        current_area = double_area(v[s-1],v[s],v[(s+1)%(int)v.size()]);
        if(current_area < best_area){
            best_area = current_area;
            best_pos = s;
        }
    }
    return make_pair(best_area,best_pos);
}

LL optimal_play(vector<Point> v, int player){
    if(v.size() == 3u){ // base case
        return (player?-1:1) * double_area(v[0],v[1],v[2]);
    }
    auto [best_area,best_pos] = best_play(v);
    v.erase(v.begin()+best_pos);
    return ((player?-1:1) * best_area) + optimal_play(v, (player?0:1));
}

int main(){
    int N;
    while(cin >> N){
        vector<bool> selected(N, false);
        vector<Point> v(N);
        for(int i = 0; i < N; i++){
            cin >> v[i].x >> v[i].y; v[i].idx = i+1;
        }

        // Player 0 = Alberto; Player 1 = Beatrice
        bool first = false;
        auto diff_area = optimal_play(v, 0);
        if(diff_area > 0) cout << "Beatrice" << endl; // Alberto eats more than Beatrice
        else {
            cout << "Alberto" << endl; // Any other case play as Alberto
            first = true;
        }

        if(first){
            auto [best_area,best_pos] = best_play(v);
            cout << v[best_pos].idx << endl;
            v.erase(v.begin()+best_pos);
        }

        LL next_idx;
        do{
            cin >> next_idx;
            for(auto it = v.begin(); it != v.end(); it++){
                if(it->idx == next_idx){
                    v.erase(it); break;
                }
            }
            auto [best_area,best_pos] = best_play(v);
            cout << v[best_pos].idx << endl;
            v.erase(v.begin()+best_pos);
        }while(v.size() >= 3);


    }
}
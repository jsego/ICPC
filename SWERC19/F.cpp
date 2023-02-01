//
// Created by js on 31/01/23.
//
#include<bits/stdc++.h>

using namespace std;

struct PT {
    long long x, y;
    PT() {}
    PT(int x, int y) : x(x), y(y) {}
    PT(const PT &p) : x(p.x), y(p.y) {}
    PT operator + (const PT &p) const { return PT(x+p.x, y+p.y); }
    PT operator - (const PT &p) const { return PT(x-p.x, y-p.y); }
    PT operator * (long long c) const { return PT(x*c, y*c ); }
    PT operator / (long long c) const { return PT(x/c, y/c ); }
};

long long ComputeSignedArea(const vector<PT> &p) {
    long long area = 0;
    for(int i = 0; i < p.size(); i++) {
        int j = (i+1) % p.size();
        area += p[i].x*p[j].y - p[j].x*p[i].y;
    }
    //return area / 2;
    return area;
}

long long ComputeArea(const vector<PT> &p) {
    return fabs(ComputeSignedArea(p));
}

int main(){
    int N;
    while(cin >> N){
        long long res = 0;
        for(int n = 0 ; n < N; n++) {
            int P;
            cin >> P;
            vector<PT> vpt(P);
            for (int i = 0; i < P; i++)
                cin >> vpt[i].x >> vpt[i].y;
            res += ComputeArea(vpt);
        }
        cout << res/2 << endl;
    }
}
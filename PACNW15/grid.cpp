#include <bits/stdc++.h>

using namespace std;

bool V[501][501];
int QM[250001];
int QN[250001];
int QS[250001];
int T[501][501];

int M, N;

bool is_goal(int cm, int cn){
	return ((cm+1)==M) and ((cn+1)==N);
}

int main(){
	while(cin >> M >> N){
		string s;
		for(int m=0; m<M; m++){
			cin >> s;
			for(int n=0; n<N; n++){
				T[m][n] = int(s[n]-'0');
				V[m][n] = false;
			}
		}
		
		int pos = 0, total = 0, cm, cn, cs, jump, sol=-1;
		QM[total] = 0; QN[total] = 0; QS[total++] = 0;
		while(pos < total){
			cm = QM[pos]; cn = QN[pos]; cs = QS[pos++];
			jump = T[cm][cn];
			if((cm + jump < M) && (not V[cm+jump][cn])){
				if(is_goal(cm+jump,cn)){sol = cs+1; break;}
				V[cm+jump][cn] = true;
				QM[total] = cm+jump; QN[total] = cn; QS[total++] = cs+1;
			} 
			if((cm >= jump) && (not V[cm-jump][cn])){
				V[cm-jump][cn] = true;
				QM[total] = cm-jump; QN[total] = cn; QS[total++] = cs+1;
			} 
			if((cn+jump<N) && (not V[cm][cn+jump])){
				if(is_goal(cm,cn+jump)){sol = cs+1; break;}
				V[cm][cn+jump] = true;
				QM[total] = cm; QN[total] = cn+jump; QS[total++] = cs+1;
			}
			if((cn>=jump) && (not V[cm][cn-jump])){
				V[cm][cn-jump] = true;
				QM[total] = cm; QN[total] = cn-jump; QS[total++] = cs+1;
			}
		}
		if(sol==-1) cout << "IMPOSSIBLE\n";
		else cout << sol << "\n";
	}
}


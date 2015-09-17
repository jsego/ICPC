#include <stdio.h>
#include<iostream>
using namespace std;
#define TAM 10

bool Q[TAM][TAM],C[TAM][TAM],F[TAM][TAM],seen[TAM][TAM],fin;
int T[TAM][TAM],S[TAM][TAM][TAM];

void printSUDO(){
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			printf("%d",T[i][j]);
		}printf("\n");
	}
}

void recur(int i,int j){
	//cout<<i<<" "<<j<<endl;
	if(fin)return;
	
	if( i == 9 && j==0) { 
		fin=true;
		printSUDO(); 
		return; 
	}
	
	if(!seen[i][j]){
		seen[i][j] = true;
		for (int k=1; k<10 && !fin; k++) {
			if(!C[j][k] && !F[i][k] && !Q[(i/3)*3 + (j/3)][k]){
				
				C[j][k]=F[i][k]=Q[(i/3)*3 + (j/3)][k]=true;
				T[i][j] = k;
				//if(i == 8 && j==8) cout<<i<<" "<<j<<" "<<k<<endl;
				if(j+1 == 9) recur(i+1,0); 
				else recur(i,j+1);
				
				if(!fin){
					C[j][k]=F[i][k]=Q[(i/3)*3 + (j/3)][k]=false;
				}
			}
		}
		seen[i][j] = false;
	}
	else {
		if(j+1 == 9) recur(i+1,0); 
		else recur(i,j+1);
	}
}

bool next_changes(){
	int placed=0;
	
	for (int k=1; k<TAM; k++) { // valor K a colocar
		for (int i=0; i<9; i++) {
			for (int j=0; j<9; j++) {
				if(T[i][j] == 0){
					int col=0,fil=0,cua=0,posx=(i/3)*3,posy=(j/3)*3;
					for (int q=0; q<9;q++) {
						if(S[i][q][k]) col++;
						if(S[q][j][k]) fil++;
					}
					for (int p=posx; p<posx+3; p++) {
						for (int q=posy; q<posy+3; q++) {
							if(S[p][q][k]) cua++;
						}
					}
					if( (col!=0 && fil!=0 && cua!=0) && (col == 1 || fil == 1 || cua == 1) ){
						T[i][j] = k;
						placed++;
						for(int q=1;q<TAM;q++) S[i][j][q] = false;
						for(int q=0;q<9;q++) S[q][j][k] = S[i][q][k] = false;
						for (int p=posx; p<posx+3; p++) {
							for (int q=posy; q<posy+3; q++) {
								S[p][q][k] = false;
							}
						}
					}
				}
			}
		}
	}
	
	return (placed==0);
}

int main(int argc, char** argv)
{
	// Type in your solution below
	//FILE * fp = freopen(argv[1], "r", stdin);
	int kases;
	char c;
	scanf("%d",&kases);		
	scanf("%c",&c);
	while(kases--){
		scanf("%c",&c);
		for(int i=0;i<TAM;i++)for(int j=0;j<TAM;j++){
			F[i][j] = C[i][j] = Q[i][j] = seen[i][j] = false;
			for(int k=0;k<TAM;k++){
				S[i][j][k] = true; // se pueden utilizar todos
			}
		}
		T[0][0] = c-'0';
		fin=false;
		int posx,posy;
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				if(i||j){
					scanf("%c",&c);
					T[i][j]=c-'0';
				}
				
				if(T[i][j]>0){
					posx=(i/3)*3;
					posy=(j/3)*3;
					for(int k=1;k<TAM;k++) S[i][j][k] = false; // no se puede utilizar ningun valor en el punto (i,j)
					for(int k=0;k<9;k++) S[k][j][ T[i][j] ] = S[i][k][ T[i][j] ] = false; // no se puede utilizar el valor T[i][j] para la col de i o la fil de j
					
					for (int p=posx; p<posx+3; p++) {
						for (int q=posy; q<posy+3; q++) {
							S[p][q][T[i][j]] = false;
						}
					}
				}
				
			}
			scanf("%c",&c);
		}
		
		/*for (int i=0; i<9; i++) {
		 for (int j=0; j<9; j++) {
		 cout<<"I: "<<i<<" J: "<<j<<endl;
		 for (int k=1; k<10; k++) {
		 cout<<S[i][j][k]<<" ";
		 }cout<<endl;
		 }
		 }*/
		
		//printSUDO(); cout<<endl;
		//refrescar
		//int counti = 0;
		bool last=false;
		while (!last) {
			last = next_changes();
			//printSUDO(); cout<<endl;
			
		}
		//printSUDO(); cout<<endl;
		for (int i=0; i<9; i++) {
			for (int j=0; j<9; j++) {
				if(T[i][j]>0){
					seen[i][j] = true;
					F[i][T[i][j]] = true;
					C[j][T[i][j]] = true;
					Q[ (i/3)*3 + (j/3) ][ T[i][j] ] = true;
				}
			}
		}
		
		//printSUDO();
		
		recur(0,0);
		
		//printSUDO();
	}
	
	//fclose(fp);
}
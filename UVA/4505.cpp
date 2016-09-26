#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
int main(){
	string S; int N,C; bool first=true;
	while (cin>>N && N ) { if(first)first=false; else cout<<endl;
		int pila[2],drop=1; pila[0] = pila[1] = 0;
		for (int n=0; n<N ; n++) {
			cin>>S>>C;
			if (S=="DROP") {//mover primero antes de dejar
				/*if (pila[!drop]) {
					cout<< "MOVE "<<!drop+1<<"->"<<drop+1<<" "<<pila[!drop]<<endl;
					pila[!drop]=0;
				}*/
				cout << "DROP "<<drop+1<<" "<<C<<endl;
				pila[drop]+=C;
			}
			else {
				//mover primero antes de sacar
				if (pila[!drop] < C){
					if(pila[!drop])cout<<"TAKE "<<!drop+1<<" "<<pila[!drop]<<endl;
					cout<<"MOVE "<<drop+1<<"->"<<!drop + 1<<" "<<pila[drop]<<endl;
					cout<<"TAKE "<<!drop+1<<" "<<C-pila[!drop]<<endl;
					pila[!drop] = pila[drop]+pila[!drop]-C;
					pila[drop] = 0;
				}
				else {
					cout<<"TAKE "<<!drop+1<<" "<<C<<endl;
					pila[!drop]-=C;
				}
			}
		}
	}
}
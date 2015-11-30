#include <stdio.h>
#include <string.h>
#include <bitset>
using namespace std;
long int func[22];
size_t calc(int m, int d){
	long int bound = (1<<m);
	size_t tamanho = 22;
	for (long int i = 0; i < (1<<d); ++i){
		long int contK = 0;
		for (int j = 0; j <d; ++j){
			if(i&(1<<j))
				contK = contK|func[j];
		}
		bitset<48> aux(contK); 
		// cout << aux.count()<<endl;
		if(aux.count()>=m){
			bitset<48> aux2(i);			
			if(tamanho > aux2.count()) {
				tamanho = aux2.count();
			}
		}
	}
	return tamanho;
}
int main(int argc, char const *argv[]){

	int t,m,d,c;
	long int k;
	
	scanf("%d",&t);

	while(t--){
		memset(func,0,sizeof(func));
		scanf("%d %d",&m,&d);
		for (int i = 0; i <d; ++i){
			scanf("%d",&c);
			long int keys = 0;
			for (int j = 0; j < c; ++j){
				scanf("%ld",&k);
				keys = (keys|(1<<k));
			}
			func[i] = keys;
		}
		size_t resp = calc(m,d);
		if(resp == 22)
			printf("%s\n","Desastre!");
		else
			printf("%ld\n",resp);
	}
	return 0;
}
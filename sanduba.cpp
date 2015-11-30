#include <stdio.h>
#include <string.h>
long long int seq[100010];

int main(int argc, char const *argv[]){
	int t,n;
	long long int aux,sol;

	scanf("%d",&t);
	for (int i = 0; i < t; ++i)	{
		sol = 0LL;
		aux = 0LL;
		memset(seq,0,sizeof(seq));
		scanf("%d",&n);
		for (int j = 0; j < n; ++j){
			scanf("%lld",&seq[j]);
			
		}
		for (int k = n-1; k >= 0; k--){
			aux+=seq[k];	
			sol+= ((seq[k]%1300031)*(aux%1300031)) % 1300031;
		}		
		printf("%lld\n",sol%1300031);
	}
	
	return 0;
}
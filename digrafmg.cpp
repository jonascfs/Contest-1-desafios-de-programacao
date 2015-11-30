#include <stdio.h>
#include <string.h>
#include <algorithm>
int din[1001];
int dout[1001];
int dinAux[1001];
using namespace std;
main(){
	int n,si=0,so=0,aux=0;

	while(true){
		memset(din,0,sizeof(din));
		memset(dout,0,sizeof(dout));
		memset(dinAux,0,sizeof(dinAux));
		si = so = 0;
		scanf("%d",&n);
		if(n == 0)
			break;
		for (int i = 0; i < n; ++i){
			scanf("%d",&din[i]);
			si+=din[i];
		}
		for (int i = 0; i < n; ++i){
			scanf("%d",&dout[i]);
			so+=dout[i];	
		}
		int auxSO = 0;
		if(si!=so){
			printf("%s\n","N");
			continue;
		}
		sort(begin(dout),end(dout));

		for (int i = 1000; i >1000-n ; --i){
			for (int j = 0; j < n; ++j){				
				if(dout[i]==0)
					break;
				if(dout[i]>0 && dinAux[j]<din[j]){
					dout[i]--;
					dinAux[j]++;
				}
			}
			auxSO+=dout[i];
		}
		bool flag = false;
		for (int i = 0; i < n; ++i)		{
			if(dinAux[i]!= din[i]){
				flag = true;
				break;
			}
		}
		if(auxSO>0 || flag)
			printf("%s\n","N");
		else
			printf("%s\n","E" );
	}
}
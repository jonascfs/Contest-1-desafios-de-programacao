#include <stdio.h>
#include <string.h>

int seq[10010];
int kadane(int n){
	int maxl = 0,maxg = -1;
	for (int i = 0; i < n; ++i)	{
		maxl+=seq[i];
		if(maxl<0){
			maxl = 0;
		}
		if(maxl > maxg){
			maxg = maxl;
		}
	}
	return maxg;
}

int main(int argc, char const *argv[])
{
	int n;
	while(true){
		scanf("%d",&n);
		if(n==0)
			break;
		memset(seq,0,sizeof(seq));
		for (int i = 0; i < n; ++i)	{
			scanf("%d",&seq[i]);
		}
		int s = kadane(n);
		if(s>0)
			printf("The maximum winning streak is %d.\n",s);
		else
			printf("%s\n","Losing streak." );
	}
	return 0;
}
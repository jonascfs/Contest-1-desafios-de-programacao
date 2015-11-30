#include <stdio.h>
#include <string.h>

void pep(char *pre,char *in, int n){
	if (n <=0)
		return;
	if(n==1){
		printf("%c",pre[0]);
		return;
	}
	char root = pre[0];
	int i;
	for( i =0 ; i< n;i++){
		if(in[i]==root)
			break;
	}
	pep(pre+1,in,i);
	pep(pre+i+1,in+i+1,n-i-1);
	printf("%c", root);
}

int main(int argc, char const *argv[])
{	
	char *p = new char[60];
	char *i = new char[60];
	int c,n;
	scanf("%d",&c);
	for (int k = 0; k < c; ++k)	{
		scanf("%d %s %s",&n,p,i);
		pep(p,i,n);
		printf("\n");
	}
	return 0;
}
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
int vet[32];
int r[40011];

bool solve(int n){
	r[0] = 1;
	for (int i = 0; i < n; ++i)	{
		for (int j = vet[n-1]; j >= 0; j--)	{
			if(r[j]>0)				
				r[j+vet[i]]++;
		}
	}
	for (int i = 0; i < n; ++i)	{
		if(r[vet[i]] > 1)
			return false;
	}
	return true;
}
int main(int argc, char const *argv[])
{
	int n,c=1,ant;
	while(scanf("%d",&n)!=EOF){

		memset(vet,0,sizeof(vet));
		memset(r,0,sizeof(r));
		bool flag = true;
		ant = 0;
		for (int i = 0; i < n; ++i)	{
			scanf("%d",&vet[i]);
			if(ant >= vet[i])
				flag = false;
			ant = vet[i];		
		}
		// printf("Case #%d:",c++);
		cout<<"Case #"<<c++<<":";
		for (int i = 0; i < n; ++i)	{
			// printf(" %d",vet[i]);
			cout<<" "<<vet[i];
		}
		if(solve(n)&&flag){
			// printf("\n%s\n","This is an A-sequence.");
			cout<<endl<<"This is an A-sequence."<<endl;
		}else{ 
			cout<<endl<<"This is not an A-sequence."<<endl;
			// printf("\n%s\n","This is not an A-sequence.");
		}


	}

	return 0;
}
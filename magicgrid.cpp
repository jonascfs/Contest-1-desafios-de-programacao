#include <stdio.h>
#include <string.h>

int magrid[501][501];

int f(int r,int c){
	for (int i = 1; i < c; ++i)	{
		if(magrid[0][i] <=0){
			if(-1*magrid[0][i]>=aux[0][i-1]){
				magrid[0][i] = -1*magrid[0][i] - aux[0][i-1] + 1; 
				aux[0][i] = 1; 
			}else{
				magrid[0][i] = magrid[0][i-1];
				aux[0][i] = aux[0][i-1] + magrid[0][i];
			}

		}else{
			aux[0][i]+=aux[0][i-1];
			magrid[0][i] = 1;
		}
	}
	for (int i = 1; i < r; ++i)	{
		if(magrid[i][0] <=0){
			if(-1*magrid[i][0]>=aux[i-1][0]){
				magrid[i][0] = -1*magrid[i][0] - aux[i-1][0] + 1; 
				aux[i][0] = 1; 
			}else{
				magrid[i][0] = magrid[i-1][0];
				aux[i][0] = aux[i-1][0] + magrid[i][0];
			}

		}else{
			aux[0][i]+=aux[0][i-1];
			magrid[0][i] = 1;
		}
	}

	for (int i = 1; i < r; ++i){
		for (int j = 1; j < c; ++j){		
			int t = magrid[i-1][j];
			int l = magrid[i][j-1];
			if(magrid[i][j] > 0){
				aux[i][j]+=magrid[i][j];
				magrid[i][j] = (t < l) ? t : l;
			}else{
				
			}
			// if(t <=0 && l <=0)
			// 	magrid[i][j]+= (t > l) ? t : l; 
			// else if(t > 0 && l > 0)
			// 	magrid[i][j]+= (t < l) ? t : l; 
			// else
			magrid[i][j]+= (t < l) ? t : l;
			if(magrid[i][j] <=0){
				magrid[i][j]*=-1;
				magrid[i][j]++;
			}
		}
			// if(magrid[i][j] == 0) 
			// 	 magrid[i][j] = 1;
		}
	}
	if(magrid[r-1][c-1] <=0)
		return -1*magrid[r-1][c-1] +1;
	else{
		return magrid[r-1][c-1];

	}
}


int main(int argc, char const *argv[]){
	int t,r,c;
	scanf("%d",&t);
	for (int k = 0; k < t; ++k)	{
		memset(magrid,0,sizeof(magrid));
		scanf("%d %d",&r,&c);

		for (int i = 0; i < r; ++i){
			for (int j = 0; j < c; ++j)			{
				scanf("%d",&magrid[i][j]);
			}
		}
		magrid[0][0] = 0;
		magrid[r-1][c-1] = 0;

		printf("%d\n", f(r,c));

	}
	return 0;
}
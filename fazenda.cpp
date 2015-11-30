#include <stdio.h>
#include <string.h>

int grid[2000][2000];

int main(int argc, char const *argv[])
{
	int n,x,y,l,c,area,per;
	while(true){
		scanf("%d",&n);
		if(n == 0)
			break;
		area =0;
		per = 0;
		memset(grid,0,sizeof(grid));
		while(n--){
			scanf("%d %d %d %d",&y,&x,&c,&l);
			for (int i = x+1; l>0 ; i++,l--){
				int aux = c;
				for (int j = y+1; aux>0; j++,aux--){
					if(!grid[i][j])
						area++;
					grid[i][j] = 1;					
				}
			}
		}
		for (int i = 0; i <=1501; ++i){
			for (int j = 0; j <=1501; ++j)			{
				if(grid[i][j]){
					if(!grid[i+1][j]) per++;
					if(!grid[i][j+1]) per++;
					if(!grid[i-1][j]) per++;
					if(!grid[i][j-1]) per++;
				}
			}
		}
	printf("%d %d\n",area,per);	
	
	}
	return 0;
}
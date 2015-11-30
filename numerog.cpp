#include <stdio.h>
#include <string.h>
char map[256];

void init(){
	memset(map,0,sizeof(map));
	int c = 0;
	for (int i ='0'; i <='9'; ++i)	{
		map[i]=c++;
	}
	for (int i = 'A'; i <='Z'; ++i)	{
		map[i] = c++;
	}
}
int main(int argc, char const *argv[]){ 	
	init();
	char *a = new char[7];
	char *b = new char[7];
	while(true){
		scanf("%s %s",a,b);
		if (strcmp(a,b) == 0 && strcmp(a, "0")==0)
			break;
		int tamA,tamB;
		if(strlen(a)>=strlen(b)){
			tamA = strlen(a);
			tamB = strlen(b);
		}else{
			tamA = strlen(b);
			tamB = strlen(a);
			char *aux = b;
			b = a;
			a = aux;
		}
		int resp[tamA+1];
		int resto = 0;
		int j=tamA-1;
		for (int i=tamB-1; i>=0 ; i--,j--){
				resp[j+1] = (map[a[j]] + map[b[i]] + resto) % 36;
				resto = (map[a[j]] + map[b[i]] + resto)/36;
		}
		while(resto && j>=0){
			resp[j+1] =  (map[a[j]] + resto) % 36;
			resto = (map[a[j]] + resto) / 36;
			j--;
		}
		while(j>=0){
			resp[j+1] = map[a[j]];
			j--;
		}
		if(resto){
			printf("%c",resto<=9? resto + '0':resto + 'A'-10);
		}
		
		for (int i = 1; i < tamA+1; ++i)			{
			printf("%c",resp[i]<=9? resp[i] + '0':resp[i] + 'A'-10);
		}
		printf("\n");
	}

	return 0;
}
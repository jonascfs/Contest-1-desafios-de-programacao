#include <iostream> 
using namespace std;
int m[110][110],n,i,r,j;main(){cin>>n;while(n--){cin>>r;for(i=0;i<r;i++)for(j=0;j<=i;j++)cin>>m[i][j];for(i=r-2;i>=0;i--)for(j=0;j<=i;j++)m[i][j]+=m[i+1][j]>m[i+1][j+1]?m[i+1][j]:m[i+1][j+1];cout<<m[0][0]<<endl;}}
#include<stdio.h>
int n,capacity,w[50],p[50],max_profit,i,j,V[50][50];
void main(){
	printf("\n\t\t0/1 KNAPSACK PROBLEM BY DYNAMIC PROGRAMMING METHOD\n");
	printf("\n Enter the number of objects:");
	scanf("%d",&n);
	printf("\n Enter weight and profit of each object\n");
	for(i=1;i<=n;i++){
		printf("\n\t Object %d",i);
		printf("\n Weight:");
		scanf("%d",&w[i]);
		printf("\n Profit:");
		scanf("%d",&p[i]);
	}
	printf("\n Enter capacity of knapsack:");
	scanf("%d",&capacity);
	knapsack();
}

knapsack(){
	for(i=1;i<=n;i++)
	 for(j=1;j<=capacity;j++){
	 	if(i==0 || j==0)
	    	V[i][j]=0;
	  	else if(w[i]>j)
	       	V[i][j]=V[i-1][j];
	  	else
	      	V[i][j]=max(V[i-1][j],V[i-1][j-w[i]]+p[i]);
	       	max_profit=V[i][j];
	  }
	  printf("\nMax profit=%d\n", max_profit);

}

int max(int a,int b){
 return (a>b)?a:b;
}

#include<stdio.h>
#include<sys/time.h>
#include<time.h>
#include<sys/resource.h>

void selection_sort(int input[100],int n){
	int i,j,min,temp;
	for(i=0;i<=n-2;i++){
  		min=i;
  		for(j=i+1;j<=n-1;j++){
   			if(input[j]<input[min])
         		min=j;
  		}
    temp=input[min];
    input[min]=input[i];
    input[i]=temp;
  	}
}

void main(){
	struct timeval  tv1, tv2;
	int size,input[50],i; 
	struct rusage r_usage;

	printf("Enter the input size \n");
	scanf("%d",&size);
 	printf("Enter the array elements \n");
 	for(i=0;i<size;i++){
    	scanf("%d",&input[i]);
 	}
	
	gettimeofday(&tv1, NULL);
 	selection_sort(input,size);
	gettimeofday(&tv2, NULL);
 	printf("\n Sorted array is \n");
 	for(i=0;i<size;i++){
    	printf("%d\t",input[i]);
 	}
 	printf("\nTime of selection sort = %f microseconds",(double)(tv2.tv_usec-tv1.tv_usec));

//  printf ("Total time = %f seconds\n", (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 +  (double) (tv2.tv_sec - tv1.tv_sec));
 
 	getrusage(RUSAGE_SELF,&r_usage);
 	printf("\nMemory usage: %ld kilobytes\n",r_usage.ru_maxrss);
}



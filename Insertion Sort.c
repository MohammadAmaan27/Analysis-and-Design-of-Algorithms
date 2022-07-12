#include<stdio.h>
#include<conio.h>

void main(){
    int arr[100],i,j,n,key;
    printf("Enter the size of the array:\n");
    scanf("%d",&n);
    printf("Enter the %d elements you want to sort: \n",n);
    for(i=0;i<n;i++){
	    scanf("%d",&arr[i]);
    }
    printf("Before sorting:\n");
    for(i=0;i<n;i++){
        printf("%d \t",arr[i]);
    }
    for(i=1;i<n;i++){
    	key=arr[i];
	    j=i-1;
	    while(j>=0 && arr[j]>key){
		    arr[j+1]=arr[j];
	    	j=j-1;
	    }
	    arr[j+1]=key;
	}
    printf("\n");
    printf("After sorting:\n");
    for(i=0;i<n;i++){
	    printf("%d\t",arr[i]);
	}
    getch();
} 

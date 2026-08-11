#include<stdio.h>
int main(){
	int a,key,i,pos=0;
	printf("Enter the size of array:");
	scanf("%d",&a);
	int arr[a];
	printf("Enter the elements of array");
	for(i=0;i<a;i++){
		scanf("%d",&arr[i]);
	}
	
		printf("Enter the key element you want to check in the array:");
	scanf("%d",&key);
	
		for(i=0;i<a;i++){
		if(arr[i]==key){
			pos=i;
			break;
		}
	}
	printf("the pos of the enterd element is : %d",pos+1);
	  return 0;
}

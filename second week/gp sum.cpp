#include<stdio.h>
#include<math.h>

int main(){
	 int x,n,sum=0;
	 printf("Enter the value of x and n:");
	 scanf("%d %d",&x,&n);
	 sum=( x* (pow(x,n)-1)) / (x-1);
	 sum=sum+1;
	 printf("The sum of the values of gp upto n:%d",sum);
	 return 0;
}

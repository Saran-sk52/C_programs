#include<stdio.h>
int main()
{
	int num =10;
	int *ptr;
	ptr=&num;
	printf("The value of the variable number is: %d \n",num);
	printf("The value of the variable num through the pointer variable is: %d \n",*ptr);
	*ptr=22;
	printf("The value of the variable num through the pointer variable is: %d \n",*ptr);
	return(0);
}

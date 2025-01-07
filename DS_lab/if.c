#include<stdio.h>
int main()
{
	int num1,num2;
	printf("Enter the first number:\n");
	scanf("%d" ,&num1);
	printf("Enter the Second number:\n");
	scanf("%d" ,&num2);
	if(num1+num2 <0)
	{
		printf("The Result is negative\n");
	}
	else
	{
		if(num1+num2 >0)
			printf("The Result is positive\n");
		else
			printf("THe result is zero\n");
	}
	printf("Result of %d + %d = %d",num1,num2,num1+num2);
	return(0);
}

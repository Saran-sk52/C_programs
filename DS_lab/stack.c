#include <stdio.h>
#include <stdlib.h>

int top = -1, size = 5, item, arr_stack[10];

void push()
{
    if(top >= size - 1)
    {
        printf("Overflow\n");
    }
    else
    {
    printf("Enter your Item\t");
    scanf("%d",&item);
    top++;
    arr_stack[top] = item;
    }
}

void pop()
{
    if(top < 0)
    {
        printf("Empty Stack\n");
    }
    else
    {
        item = arr_stack[top];
        printf("popped item is %d\n",item);
        top--;
    }
}

void display()
{
    for(int i = 0; i <= top; i++)
    {
        printf("%d\t",arr_stack[i]);
    }
    printf("\n");
}



int main()
{
    int choice;
    printf("You've got a Stack of Size 5\n");
    while(choice!= 4)
    {
    	printf("1.Push\t 2.Pop\t 3.Display\t 4.Exit\t\n");
    	scanf("%d",&choice);
        switch(choice)
        {
        	case 1:
        	    push();
        	    break;
        	case 2:
            	pop();
            	break;
        	case 3:
            	display();
            	break;
        	case 4:
            return 0;
            
        	default:
            printf("Invalid Choice\n");
            break;
        }
    }
    return 0;
}

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};

struct Node *header = NULL;
struct Node *CreateNode(int data)
{
    struct Node *newnode;
    newnode = malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->link = NULL;
    return (newnode);
}

void traversal()
{
    struct Node *ptr;
    ptr = header;
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->link;
    }
}

void insertAtFront(int data)
{
    struct Node *newnode;
    newnode = CreateNode(data);
    if (header == NULL)
    {
        header = newnode;
    } 
    else 
    {
        newnode->link = header;
        header = newnode;
    }
}

void insertAtEnd(int data)
{
    struct Node *newnode;
    newnode = CreateNode(data);
    if (header == NULL)
    {
        header = newnode;
    } 
    else 
    {
        struct Node *ptr = header;
        while (ptr->link != NULL)
            ptr = ptr->link;
        ptr->link = newnode;
    }
}

void insertAtAny(int data, int position)
{
    struct Node *newnode, *ptr, *prev;
    newnode = CreateNode(data);
    if (position == 0) 
    {
        newnode->link = header;
        header = newnode;
        return;
    }
    ptr = header;
    int currentPos = 0;
    while (ptr != NULL && currentPos < position)
    {
        prev = ptr;
        ptr = ptr->link;
        currentPos++;
    }
    if (ptr == NULL && currentPos != position)
    {
        printf("Position out of range\n");
        free(newnode);
        return;
    }

    newnode->link = ptr;
    prev->link = newnode;
}

void deleteAtFront()
{
	if(header == NULL)
	{
		printf("The list is empty...!!!");
	}
	else
	{
		struct Node *ptr = header;
		header = header -> link;
		free(ptr);
	}
}

void deleteAtEnd()
{
    if (header == NULL)
    {
        printf("List is empty..!!!");
    } 
    else 
    {
        struct Node *ptr = header;
        struct Node *ptr1;
        while (ptr -> link != NULL)
        {
            ptr1 = ptr;
            ptr = ptr -> link;
        }
        ptr1 -> link = NULL;
        free(ptr);
    }
}

void deleteAtAny(int key)
{
    if (header == NULL)
        printf("List is empty");
    struct Node *ptr1 = header, *ptr2 = NULL;
    if (ptr1->data == key)
    {
        header = ptr1->link;
        free(ptr1);
        return;
    }
    while (ptr1 != NULL & ptr1->data != key)
    {
        ptr2 = ptr1;
        ptr1 = ptr1->link;
    }
    if (ptr1 == NULL)
        printf("Key not found");
    ptr2->link = ptr1->link;
    free(ptr1);
}

void search(int key)
{
    struct Node *ptr = header;
    int position = 0;
    if (header == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        while (ptr != NULL)
        {
            if (ptr->data == key)
            {
                printf("\nPosition is %d\n", position + 1);
                return;
            }
            ptr = ptr->link;
            position++;
        }
        printf("Key not found\n");
    }
}

int main()
{
    insertAtFront(10);
    insertAtFront(20);
    insertAtFront(30);
    insertAtEnd(0);
    insertAtAny(15, 2);
    deleteAtFront();
    deleteAtEnd();
    deleteAtAny(20);
    traversal();
    search(15);
    return 0;
}


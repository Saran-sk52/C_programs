#include <stdio.h>
#define SIZE 5

int queue[SIZE], front = -1, rear = -1;

void insert(int element) {
    if (rear == SIZE - 1) {
        printf("Queue Overflow, cant add\n");
    } else {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = element;
    }
}

void delete() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
    } else {
        printf("Deleted element: %d\n", queue[front]);
        front++;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements are: ");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int main() {
    int choice, element;
    while (1) {
        printf("\n1. Enqueue\n2- Dequeue\n3- Traversal\n4- Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                insert(element);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}


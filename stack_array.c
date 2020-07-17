#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>



#define MAX_SIZE 10

int stack[MAX_SIZE];

int top;


void Stack_Init(void);
int isEmpty(void);
int isFull(void);
int size(void);
int peek(void);
void push(int item);
int pop(void);
void display(void);


int main() {	
	
	char choice = 'n';

	int n;
	
	Stack_Init();

	printf("Initial stack size = %d\n", size());

	do {

		printf("Item to push: ");
		scanf("%d", &n);
		push(n);
		printf("Push more? (y/n): ");
		while (getchar() != '\n');
		scanf("%c", &choice);

	} while (toupper(choice) == 'Y');
	
	display();

	do {
		printf("Pop more? (y/n): ");
		while (getchar() != '\n');
		scanf("%c", &choice);
		printf("Item popped: %d\n", pop());
	} while (toupper(choice) == 'Y');

	printf("Peek: %d\n", peek());
	

	display();
	
	printf("\n");
	
	return 0;
}



void Stack_Init(void)
{
	top = -1;
}





int isEmpty(void)
{
	return top == -1;
}




int isFull(void)
{
	return (top == MAX_SIZE - 1);
}




int size(void)
{
	return top + 1;
}




int peek(void)
{
	if (isEmpty()) {
		printf("Empty Stack\n");
		return -1;
	} else{
		return stack[top];
	}

}




void push(int item)
{
	if (isFull()) {
		printf("Stack is Full\n");
		return;
	} 

	stack[++top] = item;

}




int pop(void)
{
	if (isEmpty()) {
		printf("Stack is Empty\n");
		return -1;
	} 
	
	return stack[top--];

}




void display(void)
{
	if (isEmpty()) {
		printf("Stack is Empty\n");
		return;
	} 


	for (int i = 0; i <= top; i++) {
		printf("%d --> ", stack[i]);
	}

	printf("\n");

}







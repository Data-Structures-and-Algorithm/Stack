#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>



typedef struct Node {
	int data;
	struct Node *next;
} Node_t;

Node_t *top;



void Stack_Init(void);
int isEmpty(void);
int size(void);
int peek(void);
void push(int item);
int pop(void);
void display(void);


int main() {	
	
	int n;
	
	Stack_Init();

	while (1) {
		printf("1. Display\n2. Push\n3. Pop\n4. Peek\n"
	           "5. Size\n6. Quit\nEnter your choice: ");
		scanf("%d", &n);
		
		switch (n) {
			case 1: 
				display();
				break;
			case 2: { 
				int data;
				printf("Enter a no: ");
				scanf("%d", &data);
				push(data);
				break;
			}
			case 3: 
				printf("Popped %d\n", pop());
				break;
			case 4: 
				printf("Peek =  %d\n", peek());
				break;
			case 5: 
				printf("Size =  %d\n", size());
				break;
			case 6: 
				exit(0);
			default:
				printf("Invalid choice...\n");
		}

		while (getchar() != '\n');

		printf("\n");

	}

	printf("\n");
	
	return 0;
}



void Stack_Init(void)
{
	top = NULL;
}





int isEmpty(void)
{
	return top == NULL;
}




int size(void)
{
	int count = 0;

	Node_t *p = top;

	while (p) {
		p = p->next;
		count++;
	}

	return count;
}




int peek(void)
{
	if (isEmpty()) {
		printf("Empty Underflow...\n");
		return -1;
	} else{
		return top->data;
	}

}




void push(int item)
{
	Node_t *temp = (Node_t *)malloc(sizeof(Node_t));

	temp->data = item;

	temp->next = top;

	top = temp;
}




int pop(void)
{
	if (isEmpty()) {
		printf("Stack underflow...\n");
		return -1;
	} 
	
	Node_t *temp = top;

	int data = temp->data;

	top = top->next;

	free(temp);

	return data;

}




void display(void)
{
	if (isEmpty()) {
		printf("Stack is Empty...\n");
		return;
	} 


	Node_t *p = top;

	while (p) {
		printf("%d --> ", p->data);
		p = p->next;
	}

	printf("\n");

}







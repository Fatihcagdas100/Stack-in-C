#include <stdio.h>
#include <stdlib.h>

typedef struct Stack stack;
const int STACK_SIZE = 10;

struct Stack{
	int top;
	int size;
	int* elements;
};

int push(stack* stack, int element){
	if(stack -> top > stack -> size){
		printf("Overflow!\n");
		return -1;
	}
	stack -> elements[stack -> top + 1] = element;
	stack -> top++;
	printf("%d Stacked.\n",element);
	return 0;
}
int* pop(stack* stack){//If stack is empty return nothing else pop the element and return to user
	if(stack -> top < 0){
		printf("Stack is already empty!\n");
		return NULL;
	}
	int* element = &stack -> elements[stack -> top]; //Because of the type of int* stack has "&"
	stack -> top--;
	return element;
}

int* get(stack* stack, int index){
	if(stack -> top < 0){
		printf("Stack is empty!\n");
		return NULL;
	}
	else if(index > stack -> top){
		printf("Overflow!\n");
		return NULL;
	}
	else if(index < 0){
		printf("There is not such an index.\n");
		return NULL;
	}
	int* element = &stack -> elements[index];
	return element;
}
int search(stack* stack, int element){
	if(stack -> top < 0){
		printf("Stack is empty!\n");
		return -1;
	}
	int current_index = 0;
	while(current_index <= stack -> top){
		if(stack -> elements[current_index] == element){
			return current_index;
		}
		current_index++;
	}
	return -1;
}


int main(int argc, char *argv[]) {
	printf("Hello World\n\n");
	
	stack stack;
	
	stack.top = -1;
	stack.size = STACK_SIZE;
	int elements[STACK_SIZE];
	stack.elements = elements;
	
	push(&stack,5);
	push(&stack,8);
	push(&stack,10);
	push(&stack,7);
	push(&stack,6);
	
	int* value_ptr = get(&stack,2);
	if(!value_ptr){
		printf("Invalid Index\n");
		return 1;
	}
	printf("%d\n",*value_ptr);
	
	int* popped = pop(&stack);
	if(!popped){
		printf("Couldn't Pop");
		return -1;
	}
	printf("%d is popped.\n",*popped);
	
	
	int searched = search(&stack,10);
	if(searched == -1){
		printf("There is no such an number\n");
		return -1;
	}
	printf("index of searched value : %d\n",searched);
	
	
	int* value_ptr2 = get(&stack,4);
	if(!value_ptr2){
		printf("Invalid Index\n");
		return 1;
	}
	printf("%d\n",*value_ptr2);
	
	return 0;
}

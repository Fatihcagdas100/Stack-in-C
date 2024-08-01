#include <stdio.h>
#include <stdlib.h>

typedef struct Stack Stack;

struct Stack{
	int top;
	int size;
	int* elements;
};

Stack new(){
	Stack stack;
	
	stack.top = -1;
	stack.size = 0;
	stack.elements = (int*)malloc(sizeof(0));
	
	return stack;
}

int push(Stack* stack, int element){
	int* space_control = (int*)realloc(stack -> elements, (stack -> size + 1) * sizeof(int));
	if(!space_control){
		return -1;
	}
	stack -> elements[stack -> top + 1] = element;
	stack -> top++;
	stack -> size++;
	return 0;
}

int* pop(Stack* stack){
	if(stack -> size < 0){
		return NULL;
	}
	int* poppedElement = &stack -> elements[stack -> top];
	stack -> elements = (int*)realloc(stack -> elements, (stack -> size - 1) * sizeof(int));
	stack -> top--;
	stack -> size--;
	return poppedElement;
}

int* get(Stack* stack, int index){
	if(index > stack -> top || stack -> size == 0){
		return NULL;
	}
	int* getElement = &stack -> elements[index];
	return getElement;
}

int search(Stack* stack, int element){
	int current_index = 0;
	while(current_index <= stack -> size){
		if(stack -> elements[current_index] == element){
			return current_index;
		}
		current_index++;
	}
	return -1;
}

int main(int argc, char *argv[]) {
	printf("Hello World!\n");
	
	Stack stack = new();

	push(&stack,5);
	push(&stack,102);
	
	int* getElement = get(&stack,1);
	if(!getElement){
		printf("Couldn't get!\n");
		return 1;
	}
	printf("%d is get\n",*getElement);
	
	int* poppedElement = pop(&stack);
	if(!poppedElement){
		printf("Couldn't pop!\n");
		return 1;
	}
	printf("%d is popped.\n",*poppedElement);
	
	
	int* getElement2 = get(&stack,1);
	if(!getElement2){
		printf("Couldn't get!\n");
		return 1;
	}
	printf("%d is get\n",*getElement2);
	
	//...
	
	
}

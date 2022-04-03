#ifndef STACK_H_
#define STACK_H_

typedef struct Stack
{
	
	Object objects[OBJECT_COUNT];
	
} Stack;

void MoveIndexToTop(Stack* stack, int index)
{
	Object copy = stack->objects[index];
	
	for(int i = index; i > 0; i--)
	{
		stack->objects[i] = stack->objects[i - 1];
	}
	
	stack->objects[0] = copy;
}

#endif
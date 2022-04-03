#include <stdlib.h>
#include <time.h>

#include "raylib.h"
#include "raymath.h"

#define OBJECT_COUNT 8

#include "object.h"
#include "random.h"
#include "stack.h"

int screenWidth = 800;
int screenHeight = 800;

bool isDragging = false;
Vector2 mOffset = {0, 0};

void init(Stack* stack);
void update(Stack* stack);
void draw(Stack stack);

int main()
{
	srand(time(0));
	Stack stack = {0};
	
	init(&stack);
	
	while(!WindowShouldClose())
	{
		update(&stack);
		
		BeginDrawing();
		
			draw(stack);
			
		EndDrawing();
	}
	
	CloseWindow();
	
	return 0;
}

void init(Stack* stack)
{
	for(int i = 0; i < OBJECT_COUNT; i++)
	{
		Vector2 size = RandomVector(150, 300, 150, 300);
		
		stack->objects[i] = CreateObject(
			RandomVector(10, screenWidth - size.x - 10, 10, screenHeight - size.y - 10),
			size,
			NewColor(i)
		);
	}
	
	InitWindow(screenWidth, screenHeight, "Raylib Example");
}

void update(Stack* stack)
{
	Vector2 mPos = GetMousePosition();
	
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		for(int i = 0; i < OBJECT_COUNT; i++)
		{
			Object obj = stack->objects[i];
			
			Rectangle objR = {
				obj.position.x,
				obj.position.y,
				obj.size.x,
				obj.size.y
			};
			
			if (CheckCollisionPointRec(mPos, objR))
			{
				isDragging = true;
				mOffset = Vector2Subtract(obj.position, mPos);
				MoveIndexToTop(stack, i);
				
				break;
			}
		}
	}
	
	if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
	{
		isDragging = false;
	}
	
	if (isDragging)
	{
		stack->objects[0].position = Vector2Add(mPos, mOffset);
	}
}

void draw(Stack stack)
{
	ClearBackground(WHITE);

	for(int i = OBJECT_COUNT - 1; i > -1; i--)
	{
		if (i == 0 && isDragging)
		{
			DrawObjectShadow(stack.objects[i]);
			DrawObjectOffset(stack.objects[i]);
		}
		else
		{
			DrawObject(stack.objects[i]);
		}
	}
}
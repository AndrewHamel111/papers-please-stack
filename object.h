#ifndef OBJECT_H_
#define OBJECT_H_

#include "raylib.h"
#include "raymath.h"

#define SHADOW_POP 16

typedef struct Object
{
	
	Vector2 position;
	Vector2 size;
	
	Color color;
	
} Object;

Object CreateObject(Vector2 position, Vector2 size, Color color)
{
	return (Object) {
		.position = position,
		.size = size,
		.color = color
	};
}

void DrawObject(Object object)
{
	DrawRectangleV(object.position, object.size, object.color);
}

void DrawObjectShadow(Object object)
{
	DrawRectangleV(object.position, object.size, Fade(BLACK, 0.75f));
}

void DrawObjectOffset(Object object)
{
	Vector2 pos = Vector2SubtractValue(object.position, SHADOW_POP);
	
	DrawRectangleV(pos, object.size, object.color);
}

#endif
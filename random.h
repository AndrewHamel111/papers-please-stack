#ifndef RANDOM_H_
#define RANDOM_H_

#include <stdlib.h>

Color colors[] =
{
	(Color){0xe3,0xd1,0x96,0xff},
	(Color){0xbf,0xb4,0x69,0xff},
	(Color){219, 188, 140, 0xff},
	(Color){195, 196, 110,0xff},
	(Color){207, 164, 145,0xff},
	(Color){143, 180, 196,0xff},
	(Color){140, 140, 219,0xff},
	(Color){141, 201, 155,0xff}
};

#define COLOR_COUNT 8

int RandomRange(int min, int max)
{
	return min + (rand() % (max - min));
}

Vector2 RandomVector(int minW, int maxW, int minH, int maxH)
{
	return (Vector2) {
		RandomRange(minW, maxW),
		RandomRange(minH, maxH)
	};
}

Color NewColor(int index)
{
	return colors[index % COLOR_COUNT];
}

#endif
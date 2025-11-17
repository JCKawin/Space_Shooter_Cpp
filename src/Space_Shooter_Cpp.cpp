// Space_Shooter_Cpp.cpp : Defines the entry point for the application.
//

#include "Space_Shooter_Cpp.h"
#include "raylib.h"

int main()
{
	InitWindow(1280, 720, "Space Shooter");

	while (!WindowShouldClose()) {
		BeginDrawing();

		ClearBackground(SKYBLUE);

		EndDrawing();
	}
	
	return 0;
}

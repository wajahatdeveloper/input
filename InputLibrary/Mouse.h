#pragma once

#include "Common.h"

// Public Fields
enum
{
	MouseButton0,
	MouseButton1,
	MouseButton2,
	MouseButton3,
	MouseButton4,
	MouseButtonCount_,
} typedef MouseButton;

// Public Functions
void mouse_state_clear();
void process_mouse_button(MouseButton button, b32 isDown);
void process_mouse_position(int xPosition, int yPosition);
void process_mouse_motion(f32 xDelta, f32 yDelta);
void process_mouse_wheel(f32 offset);
b32 is_button_pressed(MouseButton button);
b32 is_button_released(MouseButton button);
b32 is_button_down(MouseButton button);

// Private Fields
struct
{
	b32 is_down;
	b32 changed;
} typedef MouseButtonState;
struct
{
	int x_position;
	int y_position;
	int x_delta;
	int y_delta;
	int wheel_offset;
	MouseButtonState buttons[MouseButtonCount_];
} typedef MouseInput;
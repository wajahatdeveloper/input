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
void process_mouse_wheel(int offset);
b32 is_button_pressed(MouseButton button);
b32 is_button_released(MouseButton button);
b32 is_button_down(MouseButton button);
int get_mouse_wheel_offset();
int get_mouse_position_x();
int get_mouse_position_y();

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
	int wheel_offset;
	MouseButtonState buttons[MouseButtonCount_];
} typedef MouseInput;
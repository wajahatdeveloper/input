#include "Mouse.h"

MouseInput mouseInput = { 0 };

void mouse_state_clear()
{
	for (int i = 0; i < MouseButtonCount_; i++)
		mouseInput.buttons[i].changed = false;
}

void process_mouse_button(MouseButton button, b32 isDown)
{
	mouseInput.buttons[button].changed = (isDown != mouseInput.buttons[button].is_down);
	mouseInput.buttons[button].is_down = isDown;
}

void process_mouse_position(int xPosition, int yPosition)
{
	mouseInput.x_position = xPosition;
	mouseInput.y_position = yPosition;
}

void process_mouse_motion(int xDelta, int yDelta)
{
	mouseInput.x_delta = xDelta;
	mouseInput.y_delta = yDelta;
}

void process_mouse_wheel(int offset)
{
	mouseInput.wheel_offset = offset;
}

b32 is_button_pressed(MouseButton button)
{
	if (mouseInput.buttons[button].is_down && mouseInput.buttons[button].changed)
		return true;
	else
		return false;
}

b32 is_button_released(MouseButton button)
{
	if (!mouseInput.buttons[button].is_down && mouseInput.buttons[button].changed)
		return true;
	else
		return false;
}

b32 is_button_down(MouseButton button)
{
	if (mouseInput.buttons[button].is_down && !mouseInput.buttons[button].changed)
		return true;
	else
		return false;
}

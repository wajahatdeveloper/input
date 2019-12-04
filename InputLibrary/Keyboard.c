#include "Keyboard.h"

KeyboardInput keyboardInput = { 0 };

void keyboardStateClear()
{
	for (int i = 0; i < KeyCount_; i++)
		keyboardInput.keys[i].changed = false;
}

void process_key(KeyCode key, b32 isDown)
{
	keyboardInput.keys[key].changed = (isDown != keyboardInput.keys[key].is_down);
	keyboardInput.keys[key].is_down = isDown;
}

b32 is_key_pressed(KeyCode key)
{
	if (keyboardInput.keys[key].is_down && keyboardInput.keys[key].changed)
		return true;
	else
		return false;
}

b32 is_key_released(KeyCode key)
{
	if (!keyboardInput.keys[key].is_down && keyboardInput.keys[key].changed)
		return true;
	else
		return false;
}

b32 is_key_down(KeyCode key)
{
	if (keyboardInput.keys[key].is_down && !keyboardInput.keys[key].changed)
		return true;
	else
		return false;
}

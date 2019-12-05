# Input
Input is a simple and useful input library for your game.
It handles all the common input devices (keybord,mouse,joystick,gamepad,touchpad and touchscreen)
It has a unified interface for all the common platforms (Windows, Android)

## keyboard
Keyboard Module has the following functions for handling keyboard input.   

```c
b32 is_key_pressed(KeyCode key);            // checks if key is pressed this frame.   
b32 is_key_released(KeyCode key);           // checks if key is released this frame.   
b32 is_key_down(KeyCode key);               // checks if key is held this frame.   
   
// these functions take a keycode and return 1 for true or 0 for false.   
```


```c
void process_key(KeyCode key, b32 isDown);  // updates the internal keyboard state for the given key.  
    
// this function is used to process input messages from the underlying system.   
```

```c
void keyboardStateClear();                  // clears the internal keyboard state for all keys.   
    
// this function should be called at the begining of every logical frame.   
```

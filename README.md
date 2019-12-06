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
void keyboard_state_clear();                  // clears the internal keyboard state for all keys.   
    
// this function should be called at the begining of every logical frame.   
```


## Mouse
Mouse Module has the following functions for handling mouse input.   

```c
b32 is_button_pressed(MouseButton key);            // checks if button is pressed this frame.   
b32 is_button_released(MouseButton key);           // checks if button is released this frame.   
b32 is_button_down(MouseButton key);               // checks if button is held this frame.   
   
// these functions take a MouseButton and return 1 for true or 0 for false.   

int get_mouse_wheel_offset();                       // gets mouse wheel offset positive for up, negative for down
int get_mouse_position_x();                         // gets mouse x position as returned by the underlying windowing library
int get_mouse_position_y();                         // gets mouse y position as returned by the underlying windowing library

```


```c
void process_mouse_button(MouseButton button, b32 isDown);  // updates the internal mouse state for the button
void process_mouse_position(int xPosition, int yPosition);  // updates the internal mouse position state
void process_mouse_wheel(int offset);   // updates the internal mouse wheel state
// this function is used to process input messages from the underlying system.   
```

```c
void mouse_state_clear();                  // clears the internal mouse state.   
    
// this function should be called at the begining of every logical frame.   
```

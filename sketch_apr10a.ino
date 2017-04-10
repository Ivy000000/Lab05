#include <Key.h>
#include <Keypad.h>

#include <Keypad.h> 

#define KEY_ROWS 4 // 按鍵模組的列數
#define KEY_COLS 4 // 按鍵模組的行數

// 依照行、列排列的按鍵字元（二維陣列）
char keymap[KEY_ROWS][KEY_COLS] = {
  {'F', 'E', 'D', 'C'},
  {'B', '3', '6', '9'},
  {'A', '2', '5', '8'},
  {'0', '1', '4', '7'}};
  
byte colPins[KEY_COLS] = {6,5,4,3};	   // 按鍵模組，行1~4接腳。
byte rowPins[KEY_ROWS] = {10,9,8,7}; // 按鍵模組，列1~4接腳。 
// 初始化Keypad物件
// 語法：Keypad(makeKeymap(按鍵字元的二維陣列), 模組列接腳, 模組行接腳, 模組列數, 模組行數)
Keypad myKeypad = Keypad(makeKeymap(keymap), rowPins, colPins, KEY_ROWS, KEY_COLS);
 
void setup(){
  Serial.begin(9600);
}
  
void loop(){
  // 透過Keypad物件的getKey()方法讀取按鍵的字元
  char key = myKeypad.getKey();
  
  if (key){  // 若有按鍵被按下…
    Serial.println(key);  // 顯示按鍵的字元
  }
}



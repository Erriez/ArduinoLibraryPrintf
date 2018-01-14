# Printf() library for Arduino

This library redirects printf() calls to the first serial port.

## Installation
1. Start the Arduino IDE.
2. Download the latest version from:  
   https://github.com/Erriez/ArduinoLibraryPrintf/archive/master.zip
3. Click Sketch | Include Library | Add .ZIP Library... and select this ZIP.
5. Run the example.

## Example
```c++
#include <Arduino.h>
#include <printf.h>
  
void setup()
{
  // Initialize Serial port
  Serial.begin(115200);
  
  // Initialize printf
  printfBegin();  
  
  // Use printf() with string in RAM
  printf("Hello world with printf() string in RAM\r\n");
  
  // Use printf() with string in flash
  printf_P(PSTR("Hello world with printf() string in flash\r\n"));
  
  // Use printf() to print the variable
  int value1 = 1234;
  printf_P(PSTR("millis(): %d\r\n"), value1);
}
```

**Example output serial port Arduino UNO:**
```c++
Hello world with printf() string in RAM
Hello world with printf() string in flash
millis(): 1234
```

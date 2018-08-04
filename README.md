# Printf() library for Arduino

This library redirects printf() calls to the first serial port.


## Example
```c++
#include <Arduino.h>
#include <ErriezPrintf.h>

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
  printf_P(PSTR("Value: %d\r\n"), value1);
}
```

**Example output serial port Arduino UNO:**
```c++
Hello world with printf() string in RAM
Hello world with printf() string in flash
Value: 1234
```

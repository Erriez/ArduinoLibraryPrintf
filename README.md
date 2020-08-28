# Printf() library for Arduino
[![Build Status](https://travis-ci.org/Erriez/ErriezPrintf.svg?branch=master)](https://travis-ci.org/Erriez/ErriezPrintf)

This library redirects printf() calls to the first serial port.


## Example
```c++
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


## Library documentation

* [Doxygen online HTML](https://erriez.github.io/ErriezPrintf)
* [Doxygen PDF](https://raw.githubusercontent.com/Erriez/ErriezPrintf/gh-pages/ErriezPrintf.pdf)


## Library installation

Please refer to the [Wiki](https://github.com/Erriez/ErriezArduinoLibrariesAndSketches/wiki) page.


## Other Arduino Libraries and Sketches from Erriez

* [Erriez Libraries and Sketches](https://github.com/Erriez/ErriezArduinoLibrariesAndSketches)

/*
 * MIT License
 *
 * Copyright (c) 2018 Erriez
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/*!
 * \brief printf() example
 * \details
 *      Source: https://github.com/Erriez/ErriezPrintf
 */

#include <Arduino.h>
#include <ErriezPrintf.h>

void setup()
{
  // Initialize Serial port
  Serial.begin(115200);

  // Redirect printf() calls to the first serial port
  printfBegin();

  // Use printf() with string in RAM
  printf("Hello world with printf() string in RAM\r\n");

  // Use printf() with string in flash
  printf_P(PSTR("Hello world with printf() string in flash\r\n"));

  // Use printf() to print the variable
  int value1 = 1234;
  printf_P(PSTR("Value: %d\r\n"), value1);

  // Print 8-bit hex value
  printHex8(0xa5);

  // Print 16-bit hex value
  printHex16(0x1234);

  // Print 32-bit hex value
  printHex32(0xdeadbeef);
}

void loop()
{
}

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
 * \file ErriezPrintf.cpp
 * \brief printf() library for Arduino.
 * \details
 *      Source: https://github.com/Erriez/ErriezPrintf
 */

#include "ErriezPrintf.h"

#if defined(__arm__)

void printfBegin()
{
}

#else // __arm__

int serial_putc(char c, FILE *)
{
  Serial.write(c);

  return c;
}

void printfBegin()
{
  fdevopen(&serial_putc, 0);
}

#endif // __arm__

void printHex8(uint8_t val)
{
  Serial.print("0x");
  if (val < 0x10) {
    Serial.print("0");
  }
  Serial.println(val, HEX);
}

void printHex16(uint16_t val)
{
  Serial.print("0x");
  if (val < 0x1000) {
    Serial.print("0");
  }
  if (val < 0x100) {
    Serial.print("0");
  }
  if (val < 0x10) {
    Serial.print("0");
  }
  Serial.println(val, HEX);
}

void printHex32(uint32_t val)
{
  Serial.print("0x");
  for (int8_t i = 3; i >= 0; i--) {
    uint8_t c = val >> (i * 8);
    if (c < 0x10) {
      Serial.print("0");
    }
    Serial.print(c, HEX);
  }
  Serial.println();
}

void printDec32(uint32_t val)
{
  char buf[9];
  
  snprintf_P(buf, sizeof(buf), PSTR("%lu"), val);
  Serial.println(buf);
}

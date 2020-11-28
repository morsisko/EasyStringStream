# EasyStringStream
A library for string creation without std:: overhead. It allows you to create strings using the c++ stream operator (<<).

# Example
```cpp
#include <EasyStringStream.h>

char test[1024];
EasyStringStream ss(test, 1024);

float temperature = 36.6f;
int pressure = 1020;
const char* name = "Thermometer";

void setup() {  
  ss << "temperature=" << temperature << "&pressure=" << pressure << "&name=" << name;

  while (!Serial);
  Serial.begin(9600);
  Serial.println(ss.get()); //prints "temperature=36.60&pressure=1020&name=Thermometer"
  Serial.println(test); //works the same as above statement
}

void loop() {

}
```
# Documentation
## `EasyStringStream(char*, int)`
Constructor. You need to provide pointer to the buffer, and the size of the buffer.

## `bool canWrite()`
Return `true` whenever at least one byte can be written to the buffer, otherwise `false`.

## `void setDefaultBase(uint8_t)`
Sets base for numeric values. The default is 10 (decimal).

## `void setDefaultFloatPrecision(uint8_t)`
Sets amounts of digits after float decimal place. The default value is 2.

## `void reset()`
Fills the buffer with zeros.

## `const char* get()`
Returns pointer to the string.

## `int getCursor()`
Returns current position in the stream.

## `int getLength()`
Return length of the buffer

## `size_t print(...)`
Adds the `...` thing to the stream and returns the amount of bytes the cursor had been moved. You can use this instead of the `<<` operator.

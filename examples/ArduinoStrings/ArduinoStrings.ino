#include <EasyStringStream.h>

char test[1024];
EasyStringStream ss(test, 1024);

void setup() {
  String arduinoString = "and this is Arduino string";
  
  ss << F("This is Arduino flash string,")
  << ' '
  << "this is just const char*"
  << ' '
  << arduinoString;

  while (!Serial);
  Serial.begin(9600);
  Serial.println(ss.get()); //prints "This is Arduino flash string, this is just const char* and this is Arduino string"
  Serial.println(test); //works the same as above statement
}

void loop() {

}
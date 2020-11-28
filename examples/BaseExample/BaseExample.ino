#include <EasyStringStream.h>

char test[1024];
EasyStringStream ss(test, 1024);


float temperature = 36.6f;
int pressure = 1020;
const char* name = "Thermometer";

void setup() {
  ss.setDefaultBase(10); //you can set base for numbers - default is 10
  ss.setDefaultFloatPrecision(2); //you can set places after float decimal point - default is 2
  
  ss << "temperature=" << temperature << "&pressure=" << pressure << "&name=" << name;

  while (!Serial);
  Serial.begin(9600);
  Serial.println(ss.get()); //prints "temperature=36.60&pressure=1020&name=Thermometer"
  Serial.println(test); //works the same as above statement
}

void loop() {

}
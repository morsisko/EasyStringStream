#include <string.h>

class EasyStringStream
{
private:
	char* buffer;
	int cursor;
	int length;

public:
	EasyStringStream(char*, int length);
	bool canWrite();
	size_t print(const char[]);
	size_t print(char);
	size_t print(unsigned char);
	size_t print(int);
	size_t print(unsigned int);
	size_t print(long);
	size_t print(unsigned long);
	size_t print(long long);
	size_t print(unsigned long long);
	size_t print(double, int = 2);
};
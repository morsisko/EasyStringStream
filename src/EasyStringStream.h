#include <cstdint>
#include <cmath>

class EasyStringStream
{
private:
	char* buffer;
	int cursor;
	int length;
	uint8_t defaultFloatPrecision = 2;
	uint8_t defaultBase = 10;

public:
	EasyStringStream(char*, int length);
	bool canWrite();
	void setDefaultBase(uint8_t base);
	void setDefaultFloatPrecision(uint8_t precision);
	void reset();
	size_t print(const char[]);
	size_t print(char);
	size_t print(unsigned char);
	size_t print(int, int = -1);
	size_t print(unsigned int, int = -1);
	size_t print(long, int = -1);
	size_t print(unsigned long, int = -1);
	size_t print(long long, int = -1);
	size_t print(unsigned long long, int = -1);
	size_t print(void*);
	size_t print(double, int = -1);
	size_t print(float, int = -1);

	EasyStringStream& operator<<(const char v[]);
	EasyStringStream& operator<<(char v);
	EasyStringStream& operator<<(unsigned char v);
	EasyStringStream& operator<<(int v);
	EasyStringStream& operator<<(unsigned int v);
	EasyStringStream& operator<<(long v);
	EasyStringStream& operator<<(unsigned long v);
	EasyStringStream& operator<<(long long v);
	EasyStringStream& operator<<(unsigned long long v);
	EasyStringStream& operator<<(void* v);
	EasyStringStream& operator<<(float v);
	EasyStringStream& operator<<(double v);
};


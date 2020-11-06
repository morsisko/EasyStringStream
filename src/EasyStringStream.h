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
	size_t print(int, int = 10);
	size_t print(unsigned int, int = 10);
	size_t print(long, int = 10);
	size_t print(unsigned long, int = 10);
	size_t print(long long, int = 10);
	size_t print(unsigned long long, int = 10);
	size_t print(void*);
	size_t print(double, int = 2);
	size_t print(float, int = 2);

	EasyStringStream& operator<<(const char v[])
	{
		this->print(v);
		return *this;
	}

	EasyStringStream& operator<<(char v)
	{
		this->print(v);
		return *this;
	}

	EasyStringStream& operator<<(unsigned char v)
	{
		this->print(v);
		return *this;
	}

	EasyStringStream& operator<<(int v)
	{
		this->print(v);
		return *this;
	}

	EasyStringStream& operator<<(unsigned int v)
	{
		this->print(v);
		return *this;
	}

	EasyStringStream& operator<<(long v)
	{
		this->print(v);
		return *this;
	}

	EasyStringStream& operator<<(unsigned long v)
	{
		this->print(v);
		return *this;
	}

	EasyStringStream& operator<<(long long v)
	{
		this->print(v);
		return *this;
	}

	EasyStringStream& operator<<(unsigned long long v)
	{
		this->print(v);
		return *this;
	}

	EasyStringStream& operator<<(void* v)
	{
		this->print(v);
		return *this;
	}

	EasyStringStream& operator<<(float v)
	{
		this->print(v);
		return *this;
	}

	EasyStringStream& operator<<(double v)
	{
		this->print(v);
		return *this;
	}
};
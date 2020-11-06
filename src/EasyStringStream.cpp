#include <EasyStringStream.h>

EasyStringStream::EasyStringStream(char* buffer, int length) :
	buffer(buffer),
	length(length),
	cursor(0)
{
	memset(buffer, 0, length);
}

bool EasyStringStream::canWrite()
{
	return length -1 > cursor;
}

size_t EasyStringStream::print(const char v[])
{
	size_t i = 0;
	for (; v[i] != 0 && canWrite(); i++)
		buffer[cursor++] = v[i];

	return i;
}

size_t EasyStringStream::print(char v)
{
	if (!canWrite())
		return 0;

	buffer[cursor++] = v;
	return 1;
}

size_t EasyStringStream::print(unsigned char v)
{
	if (!canWrite())
		return 0;

	buffer[cursor++] = v;
	return 1;
}

size_t EasyStringStream::print(unsigned long long number, int base)
{
	if (!base)
		return 0;

	char buf[64];
	uint8_t i = 0;
	uint8_t innerLoops = 0;

	if (base < 2) base = 10;

	uint16_t top = 0xFFFF / base;
	uint16_t th16 = 1;
	while (th16 < top)
	{
		th16 *= base;
		innerLoops++;
	}

	while (number > th16)
	{
		uint64_t q = number / th16;
		uint16_t r = number - q * th16;
		number = q;

		for (uint8_t j = 0; j < innerLoops; j++)
		{
			uint16_t qq = r / base;
			buf[i++] = r - qq * base;
			r = qq;
		}
	}

	uint16_t n16 = number;
	while (n16 > 0)
	{
		uint16_t qq = n16 / base;
		buf[i++] = n16 - qq * base;
		n16 = qq;
	}

	size_t bytes = 0;
	for (; i > 0; i--)
		bytes += print((char)(buf[i - 1] < 10 ?
			'0' + buf[i - 1] :
			'A' + buf[i - 1] - 10));

	return bytes;
}

size_t EasyStringStream::print(long long n, int base)
{
	if (base == 0)
		return 0;

	if (base == 10)
	{
		if (n < 0) 
		{
			int t = print('-');
			n = -n;
			return print((unsigned long long)(n), 10) + t;
		}
		return print((unsigned long long)(n), 10);
	}
	else 
		return print((unsigned long long)(n), base);
}

size_t EasyStringStream::print(unsigned long n, int base)
{
	char buf[8 * sizeof(long) + 1];
	char* str = &buf[sizeof(buf) - 1];

	*str = '\0';

	if (base < 2) base = 10;

	do {
		char c = n % base;
		n /= base;

		*--str = c < 10 ? c + '0' : c + 'A' - 10;
	} while (n);

	return print(str);
}

size_t EasyStringStream::print(unsigned int n, int base)
{
	return print((unsigned long)n, base);
}

size_t EasyStringStream::print(int n, int base)
{
	return print((long)n, base);
}
size_t EasyStringStream::print(long n, int base)
{
	if (base == 0)
		return 0;

	if (base == 10)
	{
		if (n < 0)
		{
			int t = print('-');
			n = -n;
			return print((unsigned long)(n), 10) + t;
		}
		return print((unsigned long)(n), 10);
	}
	else
		return print((unsigned long)(n), base);

}

size_t EasyStringStream::print(void* n)
{
	if (sizeof(void*) <= sizeof(unsigned long))
		return print((unsigned long)n, 16);

	return print((unsigned long long)n, 16);
}

size_t EasyStringStream::print(double number, int digits)
{
	size_t n = 0;

	if (isnan(number)) return print("nan");
	if (isinf(number)) return print("inf");
	if (number > 4294967040.0) return print("ovf");
	if (number < -4294967040.0) return print("ovf");

	if (number < 0.0)
	{
		n += print('-');
		number = -number;
	}

	double rounding = 0.5;
	for (uint8_t i = 0; i < digits; ++i)
		rounding /= 10.0;

	number += rounding;

	unsigned long int_part = (unsigned long)number;
	double remainder = number - (double)int_part;
	n += print(int_part);

	if (digits > 0) {
		n += print(".");
	}

	while (digits-- > 0)
	{
		remainder *= 10.0;
		unsigned int toPrint = (unsigned int)remainder;
		n += print(toPrint);
		remainder -= toPrint;
	}

	return n;
}

size_t EasyStringStream::print(float number, int digits)
{
	return print((double)number, digits);
}
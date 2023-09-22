#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
/**
  *_printf - Works as the print stdlb
  *@format: constant string
  *Return: count
  */
int _printf(const char *format, ...)
{
	int count = 0;
	const char *string;
	va_list args;

	va_start(args, format);
	for (; *format; ++format)
	{
		if (*format == '%')
		{
			if (*(format + 1) == '%')
			{
				_putchar('%');
				++format;
				++count;
			}
			else if (*(format + 1) == 'c')
			{
				_putchar(va_arg(args, int));
				++format;
				++count;
			}
			else if (*(format + 1) == 's')
			{
				string = va_arg(args, const char *);
				while (*string)
				{
					_putchar(*string++);
					++count;
				}
				++format;
			}
		}
		else
		{
			_putchar(*format);
			++count;
		}
	}
	va_end(args);
	return (count);
}

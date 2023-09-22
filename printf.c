#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
 /**
 *_putint - puts integer value
 *@n:Integer
 *Return:count
 */
int _putint(int n);
int _putstr(char *str);

/**
  *_printf - Works as the print stdlb
  *@format: constant string
  *Return: count
  */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == 'c')
			{
				_putchar(va_arg(args, int));
				count++;
			}
			else if (*format == 's')
			{
				count += _putstr(va_arg(args, char *));
			}
			else if (*format == 'd' || *format == 'i')
			{
				count += _putint(va_arg(args, int));
			}
			else if (*format == '%')
			{
				_putchar('%');
				count++;
			}
		}
		else
		{
			_putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
/**
  *_putstr - put string
  *@str: String
  *Return: Count
  */
int _putstr(char *str)
{
	int count = 0;

	while (*str)
	{
		_putchar(*str);
		str++;
		count++;
	}
	return (count);
}
/**
  *_putint - puts integer
  *@n:Integer
  *return:count
  */

int _putint(int n)
{
	int count = 0, reversed;

	if (n == 0)
	{
		_putchar('0');
		return (1);
	}
	if (n < 0)
	{
		_putchar('-');
		count++;
		n = -n;
	}
	reversed = 0;
	while (n > 0)
	{
		reversed = reversed * 10 + (n % 10);
		n /= 10;
		count++;
	}
	while (reversed > 0)
	{
		_putchar('0' + (reversed % 10));
		reversed /= 10;
	}
	return (count);
}

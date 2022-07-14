#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int write_func(char *str)
{
	int i = 0;
	if (!str)
		str = "(null)";
	while(str[i])
	{
		write(1,&str[i],1);
		i++;
	}
	return (i);
}


int write_int(unsigned int i, int base)
{
	char *arr = "0123456789abcdef";
	int count = 0;
	if (i/base != 0)
		count += write_int(i/base, base);
	int n = i % base;
	write(1,&arr[n],1);
	count++;
	return (count);
}

int int_func(int i)
{
	int count = 0;
	if (i < 0)
	{
		write(1,"-",1);
		i *= -1;
		count++;
	}
	count += write_int(i,10);
	return (count);
}

int ft_printf(const char *str, ... )
{
	va_list data;
	va_start(data,str);
	int count = 0;
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == 's')
			{
				count += write_func(va_arg(data,char *));
			}
			else if (str[i + 1] == 'd')
			{
				count += int_func(va_arg(data, int));
			}
			else if (str[i + 1] == 'x')
			{
				count += write_int(va_arg(data, unsigned int), 16);
			}
			i++;
		}
		else
		{
			count ++;
			write(1, &str[i],1);
		}
	}
	return (count);
}

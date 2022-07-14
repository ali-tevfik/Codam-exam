#include <unistd.h>
#include <stdio.h>
int main(int argc, char **argv)
{
	int result = 0;
	if (argc == 3)
	{
		for (int i = 0; argv[1][i]; i++)
		{
			result = 0;
			for(int a = i - 1; a >= 0; a--)
			{
				if (argv[1][i] == argv[1][a])
					result = 1;
			}
			if (result == 0)
			{
				for(int x = 0; argv[2][x]; x++)
				{
					if (argv[1][i] == argv[2][x])
						result = 1;
				}
				if (result == 1)
					write(1,&argv[1][i], 1);
			}
		}
	}
	write(1,"\n",1);
}

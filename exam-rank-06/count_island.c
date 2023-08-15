#include <unistd.h>
    #include <fcntl.h>
	#include <stdio.h>
   
   void floodFill(char buf[1024*1024], int size, int width, int height, int i, char replacer) {

	buf[i] = replacer;

	if ((i > width) && (buf[i - width] == 'X'))
		floodFill(buf, size, width, height, i - width, replacer);

	if ((i < size - width - 1) && buf[i + width] == 'X')
		floodFill(buf, size, width, height, i + width, replacer);
	if (i && (i % width >= 0) && buf[i - 1] == 'X')
		floodFill(buf, size, width, height, i - 1, replacer);
	if (i && (i % width < size - width - 1) && buf[i + 1] == 'X')
		floodFill(buf, size, width, height, i + 1, replacer);
}

int main(int argc , char *argv[]){

	if(argc!= 2){
		write(1,"\n",1);
		return 0;
	}

	int fd = open(argv[1],O_RDONLY);
	char buff[1024*1024] = {0};
	int size = read(fd,buff,1024*1024);
	if(size <= 0){
		write(1,"\n",1);
		return 0;
	}
	buff[size] = '\0';

	int width = 1;
	for (int  i = 0; buff[i] != '\n'; i++)
	{
		width++;
	}
	int a = 1;
	int height = size / width;

	for (int i = 0;buff[i]; i++)
	{
		if(buff[i] == '\n'){
			if(width != a){
				// printf("a %d w %d\n",a,width);
				write(1,"\n",1);
				return 0;
			}
			a = 0;
		}
		a++;
	}

	for(int i = 0; buff[i] ; i++){
		if(buff[i] != 'X'){
			if(buff[i] != '.'){
				if(buff[i] != '\n'){
					write(1,"\n",1);
					return 0;
				}
			}
		}
	}

	char replacer = '0';
	for(int i = 0; i < size; i++){
		if(buff[i] == 'X'){
			floodFill(buff,size,width,height,i,replacer);
			replacer++;
		}
		
	}
	write(1,buff,size);
}






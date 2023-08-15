#include<stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    if(argc != 2){
        printf("\n");
        return 0;
    }


    int digit = atoi(argv[1]);
    int divider = 2;
    while(digit > 1){
        if(digit % divider == 0){
            digit /= divider;
            printf("%d",divider);
            if(digit > 1)
                printf("*");
        }
        else
            divider++;
    }

}
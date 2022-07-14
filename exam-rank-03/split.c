// #include <stdio.h>
// #include <unistd.h>
// #include <stdlib.h>


// int find_word(char *txt)
// {
//     int i;
//     int size = 0;
//     for(i = 0; txt[i] ; i++)
//     {
//         if (txt[i] == ' '|| txt[i] == '\t'|| txt[i] == '\0')
//              size++;
//     }
//     return (size);
// }

// int one_word_len(char *txt)
// {
//     int i;
//     for(i = 0; txt[i] ;i++)
//     {
//          if (txt[i] == ' '|| txt[i] == '\t'|| txt[i] == '\0')
//             return (i);
//     }
//     return (i);
// }

// char *fill_small_arr(char *txt){
//     int a = one_word_len(txt);
//     char *new = (char *)malloc(sizeof(new) * (a + 1));
//     int i;
//     for(i = 0; i < a; i++)
//     {
//         new[i] = txt[i];
//     }
//     new[i] = '\0';
//     return (new);
// }

// char **ft_split(char *txt)
// {
//     int how_many_word = find_word(txt) + 1;
//     char **new = (char **)malloc(sizeof(txt) * how_many_word);
//     int where = 0;
//     int i ;
//     for(i= 0; how_many_word > i;i++)
//     {
//         new[i] = fill_small_arr(txt + where);

//         where += one_word_len(txt + where) + 1;
//     }
//     new[i] = NULL;
//     return (new);
// }


// int main()
// {
//     int i = 0;
//     char **a = ft_split("ali doner");
//     while(a[i]) 
//     {
//         printf("%s\n", a[i]);
//         i++;
//     }
// }



int skip_space(char c)
{
    if(c == ' ' || c == '\t' || c == '\n')
        return (1)
    return (0);
}

char **split_f(char *str1)
{
    char **a = malloc(1024);
    int i = 0, x = 0, y = 0;
    while(str1[i])
    {
        while(skip_space(str1[i]) && str[i])
            i++;
        if (!str1[i])
            break;
        a[x] = malloc(1024);
        while(!skip_space(str1[i]) && str[i])
            a[x][y++] = str1[i++];
        a[x++][y] = 0;
        y = 0 ;
    }
    a[x][y] = NULL;
}
















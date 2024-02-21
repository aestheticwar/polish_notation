#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "all_func.h"


int main(){
    char arr[1000];
    struct polish_notation * first = NULL;
    struct polish_notation * last = NULL;
    struct symbol * top = NULL;
    int count, len;
    scanf("%s", arr);
    count = strlen(arr);
    len = input(arr, count);
    // for(int i = 0; i < len; i ++){
    //     printf("%c", arr[i]);
    // }
    check(arr, len, first, last, top);
    return 0;
}


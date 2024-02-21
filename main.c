#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "all_func.h"


int main(){
    char arr[1000];
    struct polish_notation * first = NULL;
    struct polish_notation * last = NULL;
    struct symbol * top = NULL;
    int count;
    scanf("%s", arr);
    count = strlen(arr);
    check(arr, count, first, last, top);
    return 0;
}
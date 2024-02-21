#include <stdio.h>
#include <stdlib.h>

#include "all_func.h"


void check(char * a, int count, struct polish_notation* first, struct polish_notation* last, struct symbol * top){
    int priority;
    char data;
    for(int i = 0; i < count; i ++){
        if((a[i] == 'x') || (a[i] >= '0' && a[i] <= '9')){
            if(first == NULL){
                first = init_first(a[i], last);
                last = first;
            }
            else {
                last = push_pol_nat(a[i], last);
            }
        }
        else {
            if(a[i] == '+'){
                data = '+';
                priority = 1;
                if(top == NULL){
                    top = push_symbol(data, priority, top);
                }
                else if (priority <= top -> priority){
                    while((top != NULL) && (priority <= top -> priority)){
                        last = push_pol_nat(top -> data, last);
                        top = pop_symbol(top);
                    }
                    top = push_symbol(data, priority, top);
                }
                else{
                    top = push_symbol(data, priority, top);
                }
            }
            if(a[i] == '-'){
                data = '-';
                priority = 1;
                if(top == NULL){
                    top = push_symbol(data, priority, top);
                }
                else if (priority <= top -> priority){
                    while((top != NULL) && (priority <= top -> priority)){
                        last = push_pol_nat(top -> data, last);
                        top = pop_symbol(top);
                    }
                    top = push_symbol(data, priority, top);
                }
                else{
                    top = push_symbol(data, priority, top);
                }
            }
            if(a[i] == '*'){
                data = '*';
                priority = 2;
                if(top == NULL){
                    top = push_symbol(data, priority, top);
                }
                else if (priority <= top -> priority){
                    while((top != NULL) && (priority <= top -> priority)){
                        last = push_pol_nat(top -> data, last);
                        top = pop_symbol(top);
                    }
                    top = push_symbol(data, priority, top);
                }
                else{
                    top = push_symbol(data, priority, top);
                }
            }
            if(a[i] == '/'){
                data = '/';
                priority = 2;
                if(top == NULL){
                    top = push_symbol(data, priority, top);
                }
                else if (priority <= top -> priority){
                    while((top != NULL) && (priority <= top -> priority)){
                        last = push_pol_nat(top -> data, last);
                        top = pop_symbol(top);
                    }
                    top = push_symbol(data, priority, top);
                }
                else{
                    top = push_symbol(data, priority, top);
                }
            }
        }
    }
    while(top != NULL){
        last = push_pol_nat(top -> data, last);
        top = pop_symbol(top);
    }
    output_pol_nat(first);
}


void output_pol_nat(struct polish_notation * first){
    struct polish_notation * ptr = first;
    while(ptr != NULL){
        ptr = ptr -> next;
        printf("%c", first -> data);
        free(first);
        first = ptr;
    }
}


struct polish_notation * push_pol_nat(char data, struct polish_notation* last){
    struct polish_notation *  ptr = malloc(sizeof(struct polish_notation));
    ptr -> data = data;
    ptr -> next = NULL;
    last -> next = ptr;
    return ptr;
}

struct symbol * push_symbol(char data, int priority, struct symbol * top){
    struct symbol * ptr = malloc(sizeof(struct symbol));
    ptr -> data = data;
    ptr -> priority = priority;
    ptr -> next = top;
    return ptr;
}

struct symbol * pop_symbol(struct symbol * top){
    if(top == NULL){
        return NULL;
    }
    struct symbol * ptr = top -> next;
    free(top);
    return ptr;
}

struct polish_notation * init_first(char data, struct polish_notation * last){
    struct polish_notation * ptr = malloc(sizeof(struct polish_notation));
    ptr -> data = data;
    ptr -> next = last;
    return ptr;
}


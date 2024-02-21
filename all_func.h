#ifndef ALL_FUNC_H
#define ALL_FUNC_H

struct polish_notation{
    
    char data;
    struct polish_notation* next;

};

struct symbol{

    char data;
    int priority;
    struct symbol * next;
    
};

struct polish_notation * init_first(char data, struct polish_notation * last);
struct symbol * pop_symbol(struct symbol * top);
struct symbol * push_symbol(char data, int priority, struct symbol * top);
struct polish_notation * push_pol_nat(char data, struct polish_notation* last);
void output_pol_nat(struct polish_notation * first);
void check(char * a, int count, struct polish_notation* first, struct polish_notation* last, struct symbol * top);
#endif
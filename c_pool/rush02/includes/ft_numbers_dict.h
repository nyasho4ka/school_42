#ifndef __FT_NUMBERS_DICT__
#define __FT_NUMBERS_DICT__

typedef struct dict_elem {
    char* number;
    char* repr;
} t_dict_elem;

typedef struct numbers_dict {
    t_dict_elem** elements;
    int size;
    int curr_elem;
} t_numbers_dict;

t_numbers_dict* create_dict(int size);
int add_elem(t_numbers_dict* dict, char* line);
void print_dict(t_numbers_dict* dict);
void free_dict(t_numbers_dict* dict);

#endif
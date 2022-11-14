#ifndef __FT__
#define __FT__
typedef struct fstream {
    int fd;
    int curr_nl_cursor;
    int new_line_size;
    int curr_char;
    int max_char;
    char* stream;
} t_fstream;

typedef struct dict_elem {
    char* number;
    char* repr;
} t_dict_elem;

typedef struct numbers_dict {
    t_dict_elem** elements;
    int size;
    int curr_elem;
} t_numbers_dict;


t_fstream* create_fstream(int fd);
char* ft_getline(t_fstream* fstream, int* status);
t_numbers_dict* create_dict(int size);
int add_elem(t_numbers_dict* dict, char* line);
void print_dict(t_numbers_dict* dict);

#endif
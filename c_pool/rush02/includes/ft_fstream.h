#ifndef __FT_FSTREAM__
#define __FT_FSTREAM__

typedef struct fstream {
    int fd;
    int curr_nl_cursor;
    int new_line_size;
    int curr_char;
    int max_char;
    char* stream;
} t_fstream;

t_fstream* create_fstream(int fd);
char* ft_getline(t_fstream* fstream, int* status);

#endif
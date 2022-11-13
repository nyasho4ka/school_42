#ifndef __FT_FSTREAM__
#define __FT_FSTREAM__
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

const int MAX_CHAR_COUNT = 128;

typedef struct fstream {
    int fd;
    int fd_status;
    int curr_char;
    int max_char;
    char* stream;
} t_fstream;

void read_next_chunk(t_fstream* fstream)
{
    fstream->curr_char = 0;
    fstream->stream = (char*)malloc(sizeof(char) * MAX_CHAR_COUNT);
    fstream->max_char = read(fstream->fd, fstream->stream, MAX_CHAR_COUNT);
}

t_fstream* create_fstream(int fd)
{
    t_fstream* fstream = (t_fstream*)malloc(sizeof(t_fstream));
    fstream->fd = fd;
    read_next_chunk(fstream);
    return fstream;
}

char ft_getc(t_fstream* fstream)
{
    char c = fstream->stream[fstream->curr_char];
    fstream->curr_char++;
    if (fstream->curr_char == fstream->max_char)
    {
        free(fstream->stream);
        read_next_chunk(fstream);
    }
    return c;
}

char* ft_getline(t_fstream* fstream)
{
    
}

int main(int argc, char **argv)
{
    (void)argc;
    char* file_path = argv[1];
    int fd = open(file_path, O_RDONLY);
    t_fstream* fstream = create_fstream(fd);
    char first_char = ft_getc(fstream);
    printf("%c\n", first_char);

    free(fstream);
}

#endif

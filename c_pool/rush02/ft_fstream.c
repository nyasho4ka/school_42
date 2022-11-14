#ifndef __FT_FSTREAM__
#define __FT_FSTREAM__
#define MEM_ERROR -2
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

const int MAX_CHAR_COUNT = 128;

typedef struct fstream {
    int fd;
    int curr_nl_cursor;
    int new_line_size;
    int curr_char;
    int max_char;
    char* stream;
} t_fstream;

void read_next_chunk(t_fstream* fstream)
{
    fstream->curr_char = 0;
    fstream->curr_nl_cursor = 0;
    fstream->stream = (char*)malloc(sizeof(char) * MAX_CHAR_COUNT);
    fstream->max_char = read(fstream->fd, fstream->stream, MAX_CHAR_COUNT);
    // if end of file
    if (fstream->max_char != MAX_CHAR_COUNT)
    {
        fstream->stream[fstream->max_char] = (char)-1;
    }
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
    if (c == -1)
        return c;

    fstream->curr_char++;
    if (fstream->curr_char == MAX_CHAR_COUNT)
    {
        free(fstream->stream);
        read_next_chunk(fstream);
    }
    return c;
}

int try_find_new_line_pos(t_fstream* fstream)
{
    int nl_cursor = fstream->curr_nl_cursor;
    while (nl_cursor < MAX_CHAR_COUNT && fstream->stream[nl_cursor] != '\n' && fstream->stream[nl_cursor] != -1)
    {
        nl_cursor++;
    }
    fstream->new_line_size += (nl_cursor - fstream->curr_nl_cursor);
    fstream->curr_nl_cursor = nl_cursor < MAX_CHAR_COUNT ? nl_cursor + 1 : 0;
    return nl_cursor;
}

char* ft_getline(t_fstream* fstream, int* status)
{
    char* line;
    int nl_pos = try_find_new_line_pos(fstream);
    // fill the line
    if ((line = malloc(sizeof(char) * fstream->new_line_size)) == (void*)(0))
        return (void*)(0);

    int i = 0;
    while (i < fstream->new_line_size)
    {
        line[i] = ft_getc(fstream);
        i++;
    } 
    // if didn't find new line sign
    while (nl_pos == MAX_CHAR_COUNT)
    {
        int prev_new_line_size = fstream->new_line_size;
        char* new_line;
        nl_pos = try_find_new_line_pos(fstream);
        if ((new_line = malloc(sizeof(char) * fstream->new_line_size)) == (void*)(0))
            return (void*)(0);

        // copy old line and free
        int i = 0;
        while (i < prev_new_line_size)
        {
            new_line[i] = line[i];
            i++;
        }
        free(line);
        // fill with new line
        while (i < fstream->new_line_size)
        {
            new_line[i] = ft_getc(fstream);
            i++;
        }
        line = new_line;
    }
    fstream->new_line_size = 0;
    *status = ft_getc(fstream);
    return line;
}

int main(int argc, char **argv)
{
    (void)argc;
    char* file_path = argv[1];
    int fd = open(file_path, O_RDONLY);
    t_fstream* fstream = create_fstream(fd);
    int status = 0;
    char* line = NULL;

    while (status != -1)
    {
        line = ft_getline(fstream, &status);
        printf("%s\n", line);
        free(line);
    }

    free(fstream);
}

#endif

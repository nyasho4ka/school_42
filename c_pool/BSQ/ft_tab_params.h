#ifndef __FT_TAB_PARAMS__
#define __FT_TAB_PARAMS__

typedef struct s_tab_params {
    int line_count;
    char empty_char;
    char obstacle_char;
    char fill_char;
} t_tab_params;

t_tab_params* ft_parse_params(char* line);

#endif
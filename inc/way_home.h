#ifndef WAY_HOME_H
#define WAY_HOME_H

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include <fcntl.h>
#include <sys/stat.h>

typedef struct s_map {
    int map_width;
    int map_height;
    bool **data;
    bool **visited;
    int dst[2];
}              t_map;

typedef struct s_res {
    int dist;
    int exit;
    bool **path;
    int **m_dist_p;
}              t_res;

char *mx_file_to_str(const char *filename);

t_map *mx_load_map_from_file(const char *filename);

void mx_check_map(t_map *map, int x1, int y1, int x2, int y2);

bool mx_is_valid_cell(int x, int y, t_map *map);

void mx_search_shortest_way(t_map *map, int x, int y, int dist, t_res *res);

t_res *mx_find_path(t_map *map, int x1, int y1, int x2, int y2);

void mx_write_map_to_file(t_map *map, t_res *res, const char* filename);

bool mx_isdigit(int c);

bool mx_isspace(char c);

char *mx_remove_separators(char *s, int file_length);

int mx_atoi(const char *str);

void mx_printint(int n);

void mx_printchar(char c);

void mx_printstr(const char *str);

void mx_printerr(const char *err_msg);

char *mx_strnew(const int size);

void mx_strdel(char **str);

int mx_strlen(const char* s);

void mx_check_input_errors(int argc, char *argv[]);

void mx_map_to_bool(const char *s, int width, int height, bool **map);

int mx_get_width(const char *s);

int mx_get_height(const char *s, int length);

int mx_filelength(int file);

#endif


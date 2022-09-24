#include "../inc/way_home.h"

t_map *mx_load_map_from_file(const char *filename) {
    if (filename == NULL)
        return 0;
    
    t_map *loaded_map = malloc(sizeof(t_map));
    int src_file = open(filename, O_RDONLY);
    
    if (src_file < 0) {
        return NULL;
    }
    
    int file_length = mx_filelength(src_file);
    close(src_file);
    
    char *file_content_str = mx_file_to_str(filename);
    char *cleared_str = mx_remove_separators(file_content_str, file_length);
    
    int width = mx_get_width(cleared_str);
    int height = mx_get_height(cleared_str, file_length);
   
    loaded_map->map_width = width;
    loaded_map->map_height = height;
    
    bool **bool_map = (bool**)malloc(height * sizeof(bool*));
    for (int i = 0; i < height; i++)
        bool_map[i] = (bool*)malloc(width * sizeof(bool));
    
    mx_map_to_bool(cleared_str, width, height, bool_map);
    
    loaded_map->data = bool_map;
    mx_strdel(&cleared_str);
    
    return loaded_map;
}


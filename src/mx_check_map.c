#include "../inc/way_home.h"

void mx_check_map(t_map *map, int x1, int y1, int x2, int y2) {
    
    if(x1 < 0 || x2 < 0 || y1 < 0 || y2 < 0 ||
       x1 >= map->map_width || x2 >= map->map_width||
       y1 >= map->map_height || y2 >= map->map_height) {
        mx_printerr("points are out of map range\n");
        exit(0);
    }
    
    if(map->data[y1][x1] == 1) {
        mx_printerr("entry point cannot be an obstacle\n");
        exit(0);
    }

    if(map->data[y2][x2] == 1) {
        mx_printerr("exit point cannot be an obstacle\n");
        exit(0);
    }
}


#include "../inc/way_home.h"

bool mx_is_valid_cell(int x, int y,t_map *map) {
    if (x >= 0 && x < map->map_width && y >= 0 && y < map->map_height) {
        if (!map->visited[y][x] && map->data[y][x] != 1)
            return true;
    }
    return false;
}


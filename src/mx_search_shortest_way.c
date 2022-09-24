#include "../inc/way_home.h"

static void copy_bool_arr(bool **dst, bool **src, int w, int h) {
    for (int i = 0; i < h; i++) {
        for (int j = 0;  j < w; j++) {
            dst[i][j] = src[i][j];
        }
    }
}


void mx_search_shortest_way(t_map *map,int x, int y,
                                int dist, t_res *res) {
    if (x == map->dst[0] & y == map->dst[1]) {
        if (dist < res->exit) {
            res->exit  = dist;
            copy_bool_arr(res->path, map->visited, map->map_width, map->map_height);
        }
        return;
    }
    map->visited[y][x] = true;
    if (mx_is_valid_cell(x + 1, y, map))
        mx_search_shortest_way(map, x + 1, y, dist + 1, res);
    if (mx_is_valid_cell(x - 1, y, map))
        mx_search_shortest_way(map, x - 1, y, dist + 1, res);
    if (mx_is_valid_cell(x, y + 1, map))
        mx_search_shortest_way(map, x, y + 1, dist + 1, res);
    if (mx_is_valid_cell(x, y - 1, map))
        mx_search_shortest_way(map, x, y - 1, dist + 1, res);

    map->visited[y][x] = false;
}



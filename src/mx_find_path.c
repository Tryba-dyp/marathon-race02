#include "../inc/way_home.h"

static void get_dist(t_map *map, t_res *res) {
    int max = -1;

    for (int i = 0; i < map->map_height; i++) {
        for (int j = 0; j < map->map_width; j++) {
            if (res->m_dist_p[i][j] > max && res->m_dist_p[i][j] != 2147483647) {
                max = res->m_dist_p[i][j];
            }
            else if (max != res->m_dist_p[i][j]) {
                res->m_dist_p[i][j] = 0;
        	}
        }
    }

    res->dist = max;
}

static bool has_n(int x, int y, t_map *map) {
   if (mx_is_valid_cell(x + 1, y, map))
		return true;
   if (mx_is_valid_cell(x - 1, y, map))
		return true;
   if (mx_is_valid_cell(x, y + 1, map)) 
       	return true;
   if (mx_is_valid_cell(x, y - 1, map))
       	return true;
   return false;
}

static void find_dist(t_map *map, int x, int y, t_res *res, int dist) {

    if (!has_n(x, y, map)) {
        if(dist < res->m_dist_p[y][x])
            res->m_dist_p[y][x] = dist;
        return;
    }
    
   if (dist < res->m_dist_p[y][x]) {
        res->m_dist_p[y][x] = dist;
    }

    map->visited[y][x] = true;

    if (mx_is_valid_cell(x + 1, y, map))
        find_dist(map, x + 1, y, res, dist + 1);
    if (mx_is_valid_cell(x - 1, y, map))
        find_dist(map, x -1, y, res, dist + 1);
    if (mx_is_valid_cell(x, y - 1, map))
        find_dist(map, x, y - 1, res, dist + 1);
    if (mx_is_valid_cell(x, y + 1, map))
        find_dist(map, x, y + 1, res, dist + 1);

    map->visited[y][x] = false;;

}

static int find_way(t_map *map, int x, int y, t_res *res) {
    res->exit = 2147483647;
    mx_search_shortest_way(map, x, y , 0, res);
    res->path[map->dst[1]][map->dst[0]] = true;
    
    if (res->exit == 2147483647) {
        return -1;
    }
    return 0;
}

t_res *mx_find_path(t_map *map, int x1, int y1, int x2, int y2) { 
    t_res * res = malloc(sizeof(t_res*));
    map->dst[0] = x2;
    map->dst[1] = y2;
    mx_check_map(map, x1, y1, x2, y2);
    map->visited = (bool**)malloc(sizeof(bool*) * map->map_height);
    res->path = (bool**)malloc(sizeof(bool*) * map->map_height);
    res->m_dist_p = (int**)malloc(sizeof(int*) * map->map_height);

    for (int i = 0; i < map->map_height; i++) {
        res->path[i] = (bool*)malloc(sizeof(bool) * map->map_width);
        map->visited[i] = (bool*)malloc(sizeof(bool) * map->map_width);
        res->m_dist_p[i] = (int*)malloc(sizeof(int) * map->map_width);

        for (int j = 0; j < map->map_width; j++)
			res->m_dist_p[i][j] = 2147483647;
    }

    if (find_way(map, x1, y1, res) < 0) {
        mx_printerr("route not found\n");
        exit(0);
    }
    find_dist(map, x1, y1, res, 0);
    get_dist(map,res);
    
    for (int i = 0; i < map->map_height; i++)
       free(map->visited[i]);
    free(map->visited);

    return res;    
}


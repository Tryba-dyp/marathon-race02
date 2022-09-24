#include "../inc/way_home.h"

int main(int argc, char *argv[]) {

    mx_check_input_errors(argc, argv);
    t_map* map = mx_load_map_from_file(argv[1]);
    t_res* res = mx_find_path(map, mx_atoi(argv[2]), mx_atoi(argv[3]), mx_atoi(argv[4]), mx_atoi(argv[5]));

    mx_printstr("dist=");
    mx_printint(res->dist);
    mx_printstr("\nexit=");
    mx_printint(res->exit);
    mx_printstr("\n");
    
    mx_write_map_to_file(map, res, "path.txt");
    
    for (int i = 0; i < map->map_height; i++) {
        free(res->path[i]);
        free(res->m_dist_p[i]);
    }
    free(res->path);
    free(res->m_dist_p);
    free(res);
    free(map);
    return 0;
}


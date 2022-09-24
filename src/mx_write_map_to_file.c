#include "../inc/way_home.h"

void mx_write_map_to_file(t_map *map, t_res *res, const char* filename) {
    int file = open(filename, O_CREAT| O_TRUNC | O_WRONLY, S_IWUSR | S_IRUSR);
    
    if (file == -1) {
        mx_printerr("error\n");
    }

    for (int i = 0; i < map->map_height; i++) {
        for (int j = 0; j < map->map_width; j++) {
			if (res->m_dist_p[i][j] == res->dist
				&& res->path[i][j] == false) {
				write(file, "D", 1);
            }
			else if (res->m_dist_p[i][j] == res->dist
					&& res->path[i][j] == true) {
					write(file, "X", 1);
            }
            else if (res->path[i][j] == true) {
                write(file, "*", 1);
            }
            else if (map->data[i][j] == false) {
                write(file, ".", 1);
            }
            else {
                write(file, "#", 1);
            }
        }
        write(file, "\n", 1);
	}
    close(file);
}


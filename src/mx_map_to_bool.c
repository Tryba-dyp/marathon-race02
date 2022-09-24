#include "../inc/way_home.h"

void mx_map_to_bool(const char *s, int width, int height, bool **map) {
    int count = 0;
    
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if(s[count] == '#') {
                map[i][j] = true;
            }
            else if (s[count] == '.') {
                map[i][j] = false;
            }
            else { 
                break;
            }
            count++;
        }
        count++;
    }
}


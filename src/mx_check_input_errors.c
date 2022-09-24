#include "../inc/way_home.h"

void mx_check_input_errors(int argc, char *argv[]) {
    if (argc != 6) {
        mx_printerr("usage: ./way_home [file_name] [x1] [y1] [x2] [y2]\n");
        exit(-1);
    }
    
    int file = open(argv[1], O_RDONLY);
    if (file == -1) {
        mx_printerr("map does not exist\n");
        exit(-1);
    }
    
    char buf;
    if (read(file, &buf, 1) == -1) {
        mx_printerr("map does not exist\n");
        exit(-1);
    }
    close(file);
    
    file = open(argv[1], O_RDONLY);
	int size_x = 0;
    int size_y = 0;
    int temp_size = 0;
    int line_end = 0;
    
    while(read(file, &buf, 1)) {
        if (buf == ',') {
            continue;
        }
        
        if (buf != '.' && buf != '#' && buf != ',' && buf != '\n') {
            mx_printerr("map error\n");
            exit(-1);
        }
		
		temp_size++;		
		if (line_end != 1) {
			size_x++;
        }

        if (buf == '\n') {
            size_y++;
            line_end = 1;
            if (temp_size != size_x) {
                mx_printerr("map error\n");
                exit(-1);
            }
            temp_size = 0;
        }
    }
     
    if (mx_atoi(argv[2]) > size_x || mx_atoi(argv[2]) < 0
    	|| mx_atoi(argv[3]) > size_y || mx_atoi(argv[3]) < 0
    	|| mx_atoi(argv[4]) > size_x || mx_atoi(argv[4]) < 0
    	|| mx_atoi(argv[5]) > size_y || mx_atoi(argv[5]) < 0) {
    	
    	mx_printerr("points are out of map range\n");
    	exit(-1);
	}
	
	close(file);
}


#include "../include/cub3d.h"
//
#include <stdio.h>


int main(int ac, char **av)
{
	t_map map;
	setMap(ac, av, &map);
	print_map_information(&map);

	
	//error_massage("Finished!\n", &map);

}
/*
01 10
1   1

1   1
01 10



 1  1
10  01

10  01
 1  1

 */
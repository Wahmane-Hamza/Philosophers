#include "philosophers.h"

int main(int ac, char **av)
{
    t_data data;

    if (ac == 5 || ac == 6)
    {
        if (!get_data(&data, ac, av))
            return (1);
        if (data.nop == 0 || data.nme == 0)
			return (0);
        
    }
    else
    {
        write(2, "Invalid Number of Args!\n", 24);
		return (1);
    }
    return 0;
}
#include "mlx.h"
#include <stdlib.h>

#define	WIDTH 900
#define HEIGHT 500

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "SO_LONG");
	mlx_loop(mlx);
	mlx_destroy_window(mlx, mlx_win);
	return (0);
}

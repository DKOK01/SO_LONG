#include <mlx.h>
#include <stdlib.h>

#define	WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int ft_close(void)
{
	exit(0);
}

int	main(void)
{
	void	*mlx;
	int x, j;
	void	*mlx_win;
	void	*img;
	//t_data	img;

	mlx = mlx_init();
	x = 1029;
	j = 600;
	mlx_win = mlx_new_window(mlx, 1029, 600, "Hello world!");
	//img.img = mlx_new_image(mlx, 1920, 1080);
	//img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	//ft_put_pixel(&img, WINDOW_WIDTH/2, WINDOW_HEIGHT/2, 0xFF0000);
	img = mlx_xpm_file_to_image(mlx, "boat.xpm", &x, &j);
	mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);
	mlx_hook(mlx_win, 17, 0, ft_close, 0);
	mlx_loop(mlx);
}

#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>

int		some_key(int key)
{
  if (key != 53)
    {
      printf("hi\n");
    }
  else
    exit(1);
  printf("key: %d\n", key);
  return (0);
}

int	       main(int ac, char **av)
{
  void *mlx_ptr;
  void *win_ptr;
  void *img_ptr;
  int i = 0;

  mlx_ptr = mlx_init();
  win_ptr =  mlx_new_window(mlx_ptr, 1000, 1000, "42");
  while (i++ < 500)
    mlx_pixel_put(mlx_ptr, win_ptr, i, i, 0xFFF000);
  mlx_key_hook(win_ptr, some_key, (void*)0);
  mlx_loop(mlx_ptr);
  return (0);
}

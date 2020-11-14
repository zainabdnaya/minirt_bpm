/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_configue.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 09:49:59 by zdnaya            #+#    #+#             */
/*   Updated: 2020/11/14 10:20:58 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"



void                 create_window(t_minirt *rt, t_mlx *mlx, int WIDTH, int HEIGHT)
{
      if (!(rt->mlx.win = mlx_new_window(rt->mlx.mlx_ptr, WIDTH, HEIGHT, rt->name)))
        {
            error(0);
            exit(1);
        }

    if (!(rt->mlx.img_ptr = mlx_new_image(rt->mlx.mlx_ptr, WIDTH, HEIGHT)))
       {
           error(0);
           exit(1);
       }
    if (!(rt->mlx.image = (int *)mlx_get_data_addr(rt->mlx.img_ptr, &rt->mlx.bpp, &rt->mlx.size_l, &rt->mlx.endian)))
    {
        error(0);
        exit(1);
    }

}
void init_graphics(t_minirt *rt, t_mlx *mlx, int WIDTH, int HEIGHT)
{
    t_list_camera *tmp;

        tmp = NULL;

    
    if ( rt->save == 1)
    {
        create_window(rt, mlx, rt->resol.WIDTH, rt->resol.HEIGHT);               
        config_window(rt,rt->list_camera->fov);
        build_image(rt, rt->list_camera->look_from, rt->list_camera->look_at);
        create_bmp(rt);
    }
    else
    {
        create_window(rt, mlx, rt->resol.WIDTH, rt->resol.HEIGHT);               
        // tmp = rt->list_camera;
        // while(rt->list_camera != NULL)
        // {
        config_window(rt,rt->list_camera->fov);
        build_image(rt, rt->list_camera->look_from, rt->list_camera->look_at);
         // rt->list_camera= rt->list_camera->next;
         // rt->list_camera = tmp;
         // }
        mlx_put_image_to_window(rt->mlx.mlx_ptr, rt->mlx.win, rt->mlx.img_ptr, 0, 0);
        mlx_key_hook(rt->mlx.win, key_hook, &rt->mlx);
        // mlx_hook(rt->mlx.win,4, 46,mouse_press,rt);

        mlx_loop(rt->mlx.mlx_ptr);
    }
       
}

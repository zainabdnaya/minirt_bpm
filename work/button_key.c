/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 09:46:16 by zdnaya            #+#    #+#             */
/*   Updated: 2020/11/16 14:28:31 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int mlx_close(t_minirt *rt)
{
    (void)rt;
    exit(0);
    return(0);
}

int key_hook(int key, t_minirt *rt)
{
    if (key == 53)
        exit(0);
    return (0);
}

int key_press(int keycode, t_minirt *rt)
{

    if(keycode == 8)
            rt->active_cam = 1;
    if(keycode == 17)
    {
            rt->active_trans = 1;
        }
    if(keycode == 15)
             rt->active_rotation = 1; 
    if(( keycode == 13 || keycode == 1 || keycode == 0 || keycode == 2 || keycode == 69 || keycode == 78) && rt->active_cam == 1 )
        {
            if(rt->active_trans == 1)
                    camera_translation(rt,keycode);
        }
    config_window(rt,rt->list_camera->fov);
    build_image(rt, rt->list_camera->look_from, rt->list_camera->look_at);        
    mlx_put_image_to_window(rt->mlx.mlx_ptr, rt->mlx.win, rt->mlx.img_ptr, 0, 0);

    return(0);
}
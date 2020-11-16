/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 13:17:13 by zdnaya            #+#    #+#             */
/*   Updated: 2020/11/16 14:28:44 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void        camera_translation(t_minirt *rt,int keycode)
{
       if(keycode == 0)
            rt->list_camera->look_from.x = rt->list_camera->look_from.x - 0.2; 
        if(keycode == 2)
            rt->list_camera->look_from.x = rt->list_camera->look_from.x + 0.2; 
        if(keycode == 13)
                rt->list_camera->look_from.y = rt->list_camera->look_from.y + 0.2;
        if(keycode == 1)
            rt->list_camera->look_from.y = rt->list_camera->look_from.y - 0.2;
        if(keycode == 69)
            rt->list_camera->look_from.z = rt->list_camera->look_from.z + 0.2;
        if(keycode == 78)
            rt->list_camera->look_from.z = rt->list_camera->look_from.z - 0.2;
        
}
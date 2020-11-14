/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 09:46:16 by zdnaya            #+#    #+#             */
/*   Updated: 2020/11/14 10:21:37 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int mlx_close(t_minirt *rt)
{
    (void)rt;
    exit(0);
}

int key_hook(int key, t_minirt *rt)
{
    if (key == 53)
        exit(0);
    return (0);
}

// int mouse_press(int button, int x, int y,t_minirt *rt)
// {
    
// }
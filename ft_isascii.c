/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muakbas <muakbas@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 15:27:22 by muakbas           #+#    #+#             */
/*   Updated: 2025/06/10 15:28:45 by muakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_isascii(int c)
{
    return (c >= 0 && c <=127);
}
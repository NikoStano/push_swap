/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 10:54:01 by nistanoj          #+#    #+#             */
/*   Updated: 2025/05/20 17:52:44 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../includes/get_next_line.h"

void    run_fd(const char *file)
{
    char    *line;
    int     fd;
    
    fd = open(file, O_RDONLY);
    if (fd < 0)
    {
        printf("Error open file !\n");
        return ;
    }
    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
}

int main(int argc, char **argv)
{
    int i;

    if (argc != 2)
        return (printf("File Needed !\n"));
    i = 1;
    while (i < argc)
    {
        run_fd(argv[i]);
        i++;
    }
    return (0);
}

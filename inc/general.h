/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Oct  8 16:20:21 2012 hugues morisset
*/

#ifndef GENERAL_H_INCLUDED
# define GENERAL_H_INCLUDED

# include <stdio.h>
# include <stdlib.h>
# include <elf.h>
# include "file.h"

void	*deref(void *addr, t_file *file);
int	check_valid_elf(t_file *file);

Elf64_Shdr	*get_section_table64(Elf64_Ehdr *elf, t_file *file);
void	print_sh_name64(Elf64_Ehdr *elf, t_file *file);

#endif /* !GENERAL_H_INCLUDED */

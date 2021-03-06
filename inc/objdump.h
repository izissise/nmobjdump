/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Oct  8 16:20:21 2012 hugues morisset
*/

#ifndef OBJDUMP_H_INCLUDED
# define OBJDUMP_H_INCLUDED

# include <ctype.h>
# include "general.h"

# define BYTE_LINE 16

void	display_section(t_elf *elf, t_file *file, int i);
void	dump_mem(void *addr, int size, size_t disp_addr);
int	display_file(const char *file);
void	display_file_flags(t_elf *elf, t_file *file);

#endif /* !OBJDUMP_H_INCLUDED */

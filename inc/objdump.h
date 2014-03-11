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
# include <string.h>
# include "general.h"

# define BYTE_LINE 16

void	dump_mem(void *addr, int size, size_t disp_addr);

#endif /* !OBJDUMP_H_INCLUDED */

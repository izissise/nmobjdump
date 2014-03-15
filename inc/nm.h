/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Oct  8 16:20:21 2012 hugues morisset
*/

#ifndef NM_H_INCLUDED
# define NM_H_INCLUDED

# include "general.h"

int	display_file(const char *file);
void	sort_symbol(t_elf *elf, void **syms, char *symstr, t_file *file);

#endif /* !NM_H_INCLUDED */

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

#define IS_32(x, y) ((elf->type == ELFCLASS32) ? (x) : (y))

struct		s_elf;
typedef struct	s_elf t_elf;

struct	s_elf
{
  int	type;
  void	*elf;
  void	*(*get_section_table)();
  size_t	(*section_number)();
  size_t	(*sh_offset)();
  size_t	(*sh_size)();
  size_t	(*sh_addr)();
};

void	*deref(void *addr, t_file *file);
int	check_valid_elf(t_file *file);
int	init_elf(t_elf *elf, t_file *file);

void			*get_section_table64(Elf64_Ehdr *elf, t_file *file);
size_t		section_number64(Elf64_Ehdr *elf);

size_t		sh_offset64(Elf64_Ehdr *elf, int idx, t_file *file);
size_t		sh_size64(Elf64_Ehdr *elf, int idx, t_file *file);
size_t		sh_addr64(Elf64_Ehdr *elf, int idx, t_file *file);

void			print_sh_name64(Elf64_Ehdr *elf, t_file *file);

#endif /* !GENERAL_H_INCLUDED */

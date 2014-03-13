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
# include <string.h>
# include <elf.h>
# include "file.h"

# define IS_32(x, y) ((elf->type == ELFCLASS32) ? (void*)(x) : (void*)(y))

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
  char	*(*sh_section_name)();
  void	(*print_elf_info)();
};

void	*deref(void *addr, t_file *file);
int	check_valid_elf(t_file *file);
int	init_elf(t_elf *elf, t_file *file);
int	find_section(t_elf *elf, const char *section, t_file *file);

void			*get_section_table64(Elf64_Ehdr *elf, t_file *file);
size_t		section_number64(Elf64_Ehdr *elf);
size_t		sh_offset64(Elf64_Ehdr *elf, int idx, t_file *file);
size_t		sh_size64(Elf64_Ehdr *elf, int idx, t_file *file);
size_t		sh_addr64(Elf64_Ehdr *elf, int idx, t_file *file);
char			*sh_section_name64(Elf64_Ehdr *elf, int idx, t_file *file);
void			print_elf_info64(Elf64_Ehdr *elf);

void			*get_section_table32(Elf32_Ehdr *elf, t_file *file);
size_t		section_number32(Elf32_Ehdr *elf);
size_t		sh_offset32(Elf32_Ehdr *elf, int idx, t_file *file);
size_t		sh_size32(Elf32_Ehdr *elf, int idx, t_file *file);
size_t		sh_addr32(Elf32_Ehdr *elf, int idx, t_file *file);
char			*sh_section_name32(Elf32_Ehdr *elf, int idx, t_file *file);
void			print_elf_info32(Elf32_Ehdr *elf);

#endif /* !GENERAL_H_INCLUDED */

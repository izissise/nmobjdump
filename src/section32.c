/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Oct  8 16:20:21 2012 hugues morisset
*/

#include "general.h"

void	*get_section_table32(Elf32_Ehdr *elf, t_file *file)
{
  Elf32_Shdr	*shtable;

  shtable = ((size_t)file->data) + deref(&(elf->e_shoff), file);
  return (shtable);
}

size_t	section_number32(Elf32_Ehdr *elf)
{
  return (elf->e_shnum);
}

char		*symbols_str_32(Elf32_Ehdr *elf, int sym, t_file *file)
{
  Elf32_Shdr	*tab;
  char		*res;

  if ((tab = get_section_table32(elf, file)) == NULL)
    return (NULL);
  res = file->data + (tab[tab[sym].sh_link]).sh_offset;
  return (res);
}

void		dump_symbol32(void *addr, char *symstr, t_file *file)
{
  Elf32_Sym	*sym;

  sym = addr;
  if (((void*)(symstr + sym->st_name) >= file->data + file->size)
      || (symstr[sym->st_name] == '\0'))
    return ;
  printf("%s\n", &symstr[sym->st_name]);
}

void	print_elf_info32(Elf32_Ehdr *elf)
{
  int	ftypes[ET_NUM];
  char	*types[ET_NUM];

  types[ET_NONE] = "";
  ftypes[ET_NONE] = 0x0;
  types[ET_REL] = "HAS_RELOC, HAS_SYMS";
  ftypes[ET_REL] = 0x11;
  types[ET_EXEC] = "EXEC_P, HAS_SYMS, D_PAGED";
  ftypes[ET_EXEC] = 0x112;
  types[ET_DYN] = "HAS_SYMS, DYNAMIC, D_PAGED";
  ftypes[ET_DYN] = 0x150;
  types[ET_CORE] = "";
  ftypes[ET_CORE] = 0x0;
  if (elf->e_type < ET_NUM)
    {
      printf(ARCHI32, ftypes[elf->e_type]);
      printf("%s\n", types[elf->e_type]);
      printf(STARTADDR32, elf->e_entry);
    }
}

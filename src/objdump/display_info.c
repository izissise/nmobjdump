/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Oct  8 16:20:21 2012 hugues morisset
*/

#include "objdump.h"

int	display_file(const char *filename)
{
  t_file		file;
  t_elf		elf;
  size_t		section_number;
  char		*name;
  unsigned int	i;

  i = 1;
  if ((open_file(&file, filename, O_RDONLY, 0) == -1)
      || check_valid_elf(&file) || init_elf(&elf, &file))
    return (1);
  elf.elf = file.data;
  section_number = elf.section_number(elf.elf);
  printf("\n");
  display_file_flags(&elf, &file);
  printf("\n");
  while (i < section_number)
    {
      name = elf.sh_section_name(elf.elf, i, &file);
      if (!(!strcmp(name, ".bss") || !strcmp(name, ".shstrtab")
            || !strcmp(name, ".symtab") || !strcmp(name, ".strtab")))
        display_section(&elf, &file, i);
      i++;
    }
  close_file(&file);
  return (0);
}

void	display_file_flags(t_elf *elf, t_file *file)
{
  printf("%s:     file format %s\n", file->name, "elf64-x86-64");
}

void	display_section(t_elf *elf, t_file *file, int i)
{
  void	*tmp;

  tmp = file->data + elf->sh_offset(elf->elf, i, file);
  printf("Contents of section %s:\n",
         elf->sh_section_name(elf->elf, i, file));
  if (tmp + elf->sh_size(elf->elf, i, file) <= file->data + file->size)
    dump_mem(tmp, elf->sh_size(elf->elf, i, file),
             elf->sh_addr(elf->elf, i, file));
}

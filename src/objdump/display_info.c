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

int	section_worth_display(char *name)
{
  if (!(!strcmp(name, ".bss")
        || !strcmp(name, ".shstrtab")
        || !strcmp(name, ".symtab")
        || !strcmp(name, ".strtab")
        || !strcmp(name, ".rela.text")
        || !strcmp(name, ".rela.debug_info")
        || !strcmp(name, ".rela.debug_aranges")
        || !strcmp(name, ".note.GNU-stack")
        || !strcmp(name, ".rela.eh_frame")
        || !strcmp(name, ".rela.debug_line")))
    return (0);
  return (1);
}

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
      if ((name != NULL) && !section_worth_display(name))
        display_section(&elf, &file, i);
      i++;
    }
  return (close_file(&file));
}

void	display_file_flags(t_elf *elf, t_file *file)
{
  if (elf->type == ELFCLASS32)
    printf("%s:     file format %s\n", file->name, "elf32-i386");
  else
    printf("%s:     file format %s\n", file->name, "elf64-x86-64");
  elf->print_elf_info(elf->elf);
}

void	display_section(t_elf *elf, t_file *file, int i)
{
  void	*tmp;
  char	*name;
  size_t	size;

  size = elf->sh_size(elf->elf, i, file);
  name = elf->sh_section_name(elf->elf, i, file);
  if ((name == NULL) || (size == 0))
    return ;
  tmp = file->data + elf->sh_offset(elf->elf, i, file);
  printf("Contents of section %s:\n", name);
  if (tmp + size <= file->data + file->size)
    dump_mem(tmp, size, elf->sh_addr(elf->elf, i, file));
}


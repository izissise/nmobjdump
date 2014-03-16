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

static char	*g_sectionname64[] = {
  ".bss",
  "code",
  ".data",
  ".debug",
  ".drectve",
  ".edata",
  ".fini",
  ".idata",
  ".init",
  ".pdata",
  ".rdata",
  ".rodata",
  ".sbss",
  ".scommon",
  ".sdata",
  ".text",
  ".vars",
  ".zerovars"
};

char	symtype_sectname64(char *sectname)
{
  int	i;
  char	*types;

  types = "btdNietitprrscgtdb";
  i = 0;
  while (i < (int)(sizeof(g_sectionname64) / sizeof(char*)))
    {
      if (!strcmp(sectname, g_sectionname64[i]))
        return (types[i]);
      i++;
    }
  return ('?');
}

char		symclass_type64(Elf64_Ehdr *elf, Elf64_Sym *sym, t_file *file)
{
  char		*str;
  char		type;
  Elf64_Shdr	*shlinked;

  shlinked = file->data + elf->e_shoff + (elf->e_shentsize * sym->st_shndx);
  if ((void*)shlinked >= file->data + file->size)
    return ('?');
  if (ELF64_ST_BIND(sym->st_info) == STB_GNU_UNIQUE)
    return ('u');
  if (sym->st_shndx)
    {
      if ((str = sh_section_name64(elf, shlinked->sh_name, file)) == NULL)
        return ('?');
      if ((type = symtype_sectname64(str)) == '?')
        return ('?');
    }
  else
    return ('?');
  if (ELF64_ST_BIND(sym->st_info) == STB_GLOBAL)
    type = toupper(type);
  return (type);
}

char		symbol_sect_type64(Elf64_Ehdr *elf, Elf64_Sym *sym, t_file *file)
{
  Elf64_Shdr	*shlinked;

  shlinked = file->data + elf->e_shoff + (elf->e_shentsize * sym->st_shndx);
  if ((void*)shlinked >= file->data + file->size)
    return ('?');
  return (((shlinked->sh_flags & SHF_EXECINSTR) != 0) ? ('T') :
          ((shlinked->sh_flags & SHF_ALLOC) != 0
           && shlinked->sh_type != SHT_NOBITS) ?
          (((shlinked->sh_flags & SHF_WRITE) == 0) ? ('r') : ('D')) :
          (shlinked->sh_type == SHT_NOBITS) ? ('B') :
          ((shlinked->sh_type != SHT_NOBITS)
           && ((shlinked->sh_flags & SHF_WRITE) == 0)) ? ('n') : ('?'));
}

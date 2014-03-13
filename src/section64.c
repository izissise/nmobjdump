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

void	*get_section_table64(Elf64_Ehdr *elf, t_file *file)
{
  Elf64_Shdr	*shtable;

  shtable = ((size_t)file->data) + deref(&(elf->e_shoff), file);
  return (shtable);
}

size_t	section_number64(Elf64_Ehdr *elf)
{
  return (elf->e_shnum);
}

void	print_elf_info64(Elf64_Ehdr *elf)
{
  int	flags;
  char	*stuff;

  flags = 0x112;
  stuff = "EXEC_P, HAS_SYMS, D_PAGED";
  printf("architecture: i386:x86-64, flags 0x%08x:\n", flags);
  printf("%s\n", stuff);
  printf("start address 0x%016lx\n", elf->e_entry);
}


/* e_shstrndx  This member holds the section header table index of the entry associated with the section name string table.  If the file has no section name string table,
                   this member holds the value SHN_UNDEF.

                   If  the  index  of  section name string table section is larger than or equal to SHN_LORESERVE (0xff00), this member holds SHN_XINDEX (0xffff) and the real
                   index of the section name string table section is held in the sh_link member of the initial entry in section header table.  Otherwise, the  sh_link  member
                   of the initial entry in section header table contains the value zero.

                   SHN_UNDEF     This  value marks an undefined, missing, irrelevant, or otherwise meaningless section reference.  For example, a symbol "defined" relative to
                                 section number SHN_UNDEF is an undefined symbol.

                   SHN_LORESERVE This value specifies the lower bound of the range of reserved indices.

                   SHN_LOPROC    Values greater than or equal to SHN_HIPROC are reserved for processor-specific semantics.

                   SHN_HIPROC    Values less than or equal to SHN_LOPROC are reserved for processor-specific semantics.

                   SHN_ABS       This value specifies absolute values for the corresponding reference.  For example, symbols defined relative to section number  SHN_ABS  have
                                 absolute values and are not affected by relocation.

                   SHN_COMMON    Symbols defined relative to this section are common symbols, such as Fortran COMMON or unallocated C external variables.

                   SHN_HIRESERVE This  value  specifies the upper bound of the range of reserved indices between SHN_LORESERVE and SHN_HIRESERVE, inclusive; the values do not
                                 reference the section header table.  That is, the section header table does not contain entries for the reserved indices.
                                 */

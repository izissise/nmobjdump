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

void			dump_line(void *addr, int size)
{
  int			j;
  int			i;
  unsigned char	*tmp;
  char			ascii[BYTE_LINE + 1];

  j = 0;
  tmp = addr;
  memset(ascii, 0, BYTE_LINE + 1);
  while (j < size + ((size % BYTE_LINE) > 0 ? 1 : 0))
    {
      i = 0;
      while (i < ((j >= size) ? (4 - (size % 4)) : 4))
        {
          ascii[j + i] = isprint(tmp[j + i]) ? tmp[j + i] : '.';
          printf("%0x", tmp[i + j]);
          i++;
        }
      printf(" ");
      j += 4;
    }
  printf(" %s", ascii);
}

void	dump_mem(void *addr, int size, size_t disp_addr)
{
  int	i;
  int	lines;
  int	div;

  i = 0;
  div = (size / BYTE_LINE);
  lines = div + (size % BYTE_LINE > 0 ? 1 : 0);
  while (i < lines)
    {
      printf(" %lx ", disp_addr + (i * BYTE_LINE));
      dump_line(addr + (i * BYTE_LINE),
                (i >= div) ? (BYTE_LINE - (size % BYTE_LINE)) : BYTE_LINE);
      printf("\n");
      i++;
    }
}

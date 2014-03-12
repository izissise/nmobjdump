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

void	dump_line(unsigned char *addr, int size)
{
  int	j;
  int	i;
  int	k;
  char	ascii[BYTE_LINE + 1];
  char	res[4 * (BYTE_LINE + 1)];

  j = 0;
  k = 0;
  memset(ascii, 0, BYTE_LINE + 1);
  while (j < (size))
    {
      i = 0;
      while ((i < 4) && (i + j < size))
        {
          ascii[j + i] = isprint(addr[j + i]) ? addr[j + i] : '.';
          sprintf(&(res[k]), "%02x ", addr[i + j]);
          i++;
          k += 2;
        }
      k++;
      j += 4;
    }
  printf("%-36s %s", res, ascii);
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
      printf(" %04lx ", disp_addr + (i * BYTE_LINE));
      dump_line((unsigned char*)(addr + (i * BYTE_LINE)),
                (i >= div) ? (size % BYTE_LINE) : BYTE_LINE);
      printf("\n");
      i++;
    }
}

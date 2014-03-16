/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Oct  8 16:20:21 2012 hugues morisset
*/

#include "nm.h"

void	swap(void **a, void **b)
{
  void	*tmp;

  tmp = *a;
  *a = *b;
  *b = tmp;
}

int	strcasecmp_underscore(char *str1, char *str2)
{
  char	a;
  char	b;

  while (str1[0] && str2[0])
    {
      while (str1[0] == '_')
        str1++;
      while (str2[0] == '_')
        str2++;
      a = str1[0];
      a = (a >= 'A' && a <= 'Z') ? a - 'A' + 'a' : a;
      b = str2[0];
      b = (b >= 'A' && b <= 'Z') ? b - 'A' + 'a' : b;
      if (a != b)
        break;
      str1++;
      str2++;
    }
  return (a - b);
}

void	sort_symbol(t_elf *elf, void **syms, char *symstr, t_file *file)
{
  int	i;
  int	ok;
  char	*n1;
  char	*n2;

  ok = 1;
  while (ok)
    {
      ok = 0;
      i = 1;
      while (syms[i])
        {
          n1 = elf->symbol_name(syms[i - 1], symstr, file);
          n2 = elf->symbol_name(syms[i], symstr, file);
          if ((!n1 && n2) || (n1 && n2 && (strcasecmp_underscore(n1, n2) > 0)))
            {
              swap(&syms[i - 1], &syms[i]);
              ok = 1;
            }
          i++;
        }
    }
}

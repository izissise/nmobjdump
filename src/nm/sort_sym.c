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

char	*skyp_underscore(char *str)
{
  if (str == NULL)
    return (NULL);
  while (str[0] == '_')
    str++;
  return (str);
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
          n1 = skyp_underscore(elf->symbol_name(syms[i - 1], symstr, file));
          n2 = skyp_underscore(elf->symbol_name(syms[i], symstr, file));
          if ((!n1 && n2) || (n1 && n2 && (strcasecmp(n1, n2) > 0)))
            {
              swap(&syms[i - 1], &syms[i]);
              ok = 1;
            }
          i++;
        }
    }
}

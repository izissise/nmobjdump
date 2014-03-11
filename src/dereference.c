/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Oct  8 16:20:21 2012 hugues morisset
*/

#include "file.h"

void	*deref(void *addr, t_file *file)
{
  if ((addr >= file->data) && (addr <= (file->data + file->size)))
    return ((void*)(*((void**)(addr))));
  return (NULL);
}

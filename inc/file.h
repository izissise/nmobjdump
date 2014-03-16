/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Oct  8 16:20:21 2012 hugues morisset
*/

#ifndef FILE_H_INCLUDED
# define FILE_H_INCLUDED

# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/mman.h>

typedef struct	s_file
{
  int		fd;
  int		flags;
  mode_t	mode;
  char const	*name;
  size_t	size;
  void		*data;
}		t_file;

int	open_file(t_file *file, const char *name, int flags, mode_t mode);
int	close_file(t_file *file);

#endif /* !FILE_H_INCLUDED */

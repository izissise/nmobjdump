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

int		filesize(t_file *file)
{
  struct stat	buf;

  if (fstat(file->fd, &buf) == -1)
    {
      file->size = 0;
      perror(file->name);
      return (-1);
    }
  file->size = buf.st_size;
  return (0);
}

int	open_file(t_file *file, const char *name, int flags, mode_t mode)
{
  int	mapright;

  file->data = NULL;
  file->mode = mode;
  file->name = name;
  file->flags = flags;
  mapright = ((flags == O_RDONLY) ? PROT_READ : (flags == O_WRONLY) ?
              PROT_WRITE : (flags == O_RDWR) ? PROT_WRITE | PROT_READ : 0);
  file->fd = ((flags & O_CREAT) == O_CREAT) ? open(name, flags, mode)
             : open(name, flags);
  if (file->fd == -1)
    {
      perror(file->name);
      return (-1);
    }
  if (filesize(file) == -1)
    return (-1);
  if ((file->data = mmap(NULL, file->size, mapright,
                         MAP_SHARED, file->fd, 0)) == MAP_FAILED)
    {
      perror(file->name);
      close(file->fd);
      return (-1);
    }
  return (0);
}

int	close_file(t_file *file)
{
  int	ret;

  ret = 0;
  if (munmap(file->data, file->size) == -1)
    {
      perror(file->name);
      ret = -1;
    }
  if (close(file->fd) == -1)
    {
      perror(file->name);
      ret = -1;
    }
  return (ret);
}

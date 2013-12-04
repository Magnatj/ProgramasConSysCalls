#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/sendfile.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
int main (int argc, char* argv[])
{
int delete_fd;

/* Elimina el archivo de entrada  */
delete_fd = unlink (argv[1]);
/* Cerramos */
close (delete_fd);
return 0;
}

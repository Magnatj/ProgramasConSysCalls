#include <stdio.h>
#include <sys/sendfile.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char* argv[])
{
        int read_fd;
        int write_fd;
	int delete_fd;
        struct stat stat_buf;
        off_t offset = 0;
        /* Abre el archivo de entrada */
        read_fd = open (argv[1], O_RDONLY);
        /* Obtenemos el tamano del archivo de entrada */
        fstat (read_fd, &stat_buf);
        /* Abre el archivo de salida para escritura */
        write_fd = open (argv[2], O_WRONLY | O_CREAT, stat_buf.st_mode);
        /* Manda los bytes de un archivo a otro */
        sendfile (write_fd, read_fd, &offset, stat_buf.st_size);
	/*Borramos el primer archivo */
	delete_fd = unlink(argv[1]);
        /* Cerramos */
        close (read_fd);
        close (write_fd);
	close (delete_fd);
        return 0;
}


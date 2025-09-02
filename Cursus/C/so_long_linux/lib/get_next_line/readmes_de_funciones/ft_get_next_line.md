# get_next_line
`get_next_line` es una función que lee una línea completa desde un archivo descriptor, manejando internamente un buffer estático para conservar datos entre llamadas.

## Prototipo
```c
char *get_next_line(int fd);
```

## Parámetros
- `fd`: El descriptor de archivo desde el cual se leerá la línea.

## Valor de retorno
- Devuelve un puntero a una cadena que contiene la línea leída, incluyendo el carácter de nueva línea (`\n`) si está presente.
- Devuelve `NULL` si se alcanza el final del archivo o si ocurre un error.

## Descripción
La función `get_next_line` realiza las siguientes tareas:
1. Utiliza un buffer estático para almacenar datos no procesados entre llamadas.
2. Lee datos del archivo descriptor en bloques de tamaño `BUFFER_SIZE`.
3. Ensambla y devuelve una línea completa, gestionando adecuadamente el buffer estático.
4. Libera la memoria asignada si se alcanza el final del archivo o si ocurre un error.

## Ejemplo de uso
```c
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("archivo.txt", O_RDONLY);
    char *line;

    if (fd < 0)
        return (1);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```
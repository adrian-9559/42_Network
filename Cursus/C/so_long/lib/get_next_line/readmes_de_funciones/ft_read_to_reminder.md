# ft_read_to_reminder

La función `ft_read_to_reminder` es una función auxiliar utilizada para leer datos desde un descriptor de archivo y almacenarlos en un recordatorio (`reminder`). Su objetivo es manejar la lectura en bloques y ensamblar los datos en una cadena dinámica.

## Prototipo
```c
static int ft_read_to_reminder(int fd, char **reminder);
```

## Parámetros
- `fd`: El descriptor de archivo desde el cual se leerán los datos.
- `reminder`: Un puntero a una cadena que almacena los datos leídos y no procesados.

## Valor de retorno
- Devuelve el número de bytes leídos si la operación es exitosa.
- Devuelve `-1` si ocurre un error durante la lectura o la asignación de memoria.

## Descripción
La función realiza las siguientes tareas:
1. Reserva memoria para un buffer temporal de tamaño `BUFFER_SIZE + 1`.
2. Lee datos del descriptor de archivo en bloques de tamaño `BUFFER_SIZE`.
3. Ensambla los datos leídos en el recordatorio (`reminder`) utilizando `ft_strjoin`.
4. Detiene la lectura si encuentra un carácter de nueva línea (`\n`) o si no hay más datos por leer.
5. Libera la memoria asignada al buffer antes de retornar.

## Notas
- Es importante asegurarse de que `BUFFER_SIZE` esté definido y sea mayor que 0.
- La función `ft_strjoin` debe manejar correctamente la concatenación de cadenas dinámicas.
- La función `ft_strchr` se utiliza para buscar el carácter de nueva línea (`\n`) en la cadena `reminder`.
- La gestión de memoria es crucial para evitar fugas. Asegúrate de liberar cualquier memoria asignada en caso de error.

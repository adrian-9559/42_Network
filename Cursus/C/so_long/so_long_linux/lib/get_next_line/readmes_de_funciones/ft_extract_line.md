# ft_extract_line

La función `ft_extract_line` es una función auxiliar diseñada para extraer una línea completa desde un recordatorio (`reminder`). Su objetivo es separar la línea hasta el carácter de nueva línea (`\n`) y actualizar el recordatorio con los datos restantes.

## Prototipo
```c
static char *ft_extract_line(char **reminder);
```

## Parámetros
- `reminder`: Un puntero a una cadena que contiene los datos leídos y no procesados.

## Valor de retorno
- Devuelve un puntero a la línea extraída si la operación es exitosa.
- Devuelve `NULL` si ocurre un error o si no hay datos en el recordatorio.

## Descripción
La función realiza las siguientes tareas:
1. Verifica si el recordatorio es válido y no está vacío.
2. Busca el índice del carácter de nueva línea (`\n`) en el recordatorio.
3. Extrae la línea desde el inicio del recordatorio hasta el carácter de nueva línea (incluyéndolo, si existe) utilizando `ft_substr`.
4. Crea una copia de los datos restantes después de la línea extraída utilizando `ft_strdup`.
5. Libera la memoria del recordatorio original y actualiza su valor con los datos restantes.
6. Retorna la línea extraída.

## Notas
- La función `ft_substr` debe manejar correctamente la extracción de subcadenas dinámicas.
- La función `ft_strdup` debe crear una copia válida de la cadena restante.
- Es crucial liberar la memoria asignada en caso de error para evitar fugas.
- Si no se encuentra un carácter de nueva línea, se extrae todo el contenido del recordatorio como una única línea.
- La gestión de punteros dobles es importante para actualizar correctamente el recordatorio.

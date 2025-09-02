# 🌟 Introducción

El proyecto `get_next_line` es un ejercicio fundamental en el currículo de 42 que te desafía a implementar una función capaz de leer una línea completa desde un descriptor de archivo, incluso si esta línea está dividida en múltiples lecturas. 📜 Este proyecto te permitirá profundizar en el manejo de archivos, la gestión de memoria dinámica y la manipulación de buffers en C. 🛠️

A través de este ejercicio, aprenderás a trabajar con conceptos clave como el almacenamiento en búfer, la reutilización de datos no procesados y la optimización de recursos. 🚀 Además, `get_next_line` es una excelente oportunidad para mejorar tus habilidades en la gestión de memoria y en la escritura de código modular y eficiente. 🧠

Este proyecto es de dificultad moderada y te preparará para enfrentar desafíos más complejos en el futuro. 🔑 La clave del éxito radica en diseñar un código limpio, extensible y conforme a la Norma de 42. 🧹 ¡Prepárate para explorar el fascinante mundo de la lectura de archivos y llevar tus habilidades de programación al siguiente nivel! 💻✨

## 📋 Instrucciones generales

- 🖋️ Tu proyecto deberá estar escrito en C.
- ✅ Tu proyecto debe estar escrito siguiendo la Norma. Si tienes archivos o funciones adicionales, estas están incluidas en la verificación de la Norma y tendrás un 0 si hay algún error de norma en cualquiera de ellos.
- 🚫 Tus funciones no deben terminar de forma inesperada (segfault, bus error, double free, etc.) excepto en el caso de comportamientos indefinidos. Si esto sucede, tu proyecto será considerado no funcional y recibirá un 0 durante la evaluación.
- 🧹 Toda la memoria asignada en el heap deberá liberarse adecuadamente cuando sea necesario. No se permitirán fugas de memoria.
- 🛠️ Si el enunciado lo requiere, deberás entregar un Makefile que compilará tus archivos fuente al output requerido con las flags `-Wall`, `-Werror` y `-Wextra`, utilizar `cc` y, por supuesto, tu Makefile no debe hacer relink.
- 📜 Si el enunciado requiere de un Makefile, tu Makefile debe contener al menos las normas `$(NAME)`, `all`, `clean`, `fclean` y `re`.
- 🎁 Para entregar los bonus de tu proyecto deberás incluir una regla `bonus` en tu Makefile, en la que añadirás todos los headers, librerías o funciones que estén prohibidas en la parte principal del proyecto. Los bonus deben estar en archivos distintos `_bonus.{c/h}`. La parte obligatoria y los bonus se evalúan por separado.
- 🧪 Te recomendamos crear programas de prueba para tu proyecto, aunque este trabajo no será entregado ni evaluado. Te dará la oportunidad de verificar que tu programa funciona correctamente durante tu evaluación y la de otros compañeros. Y sí, tienes permitido utilizar estas pruebas durante tu evaluación o la de otros compañeros.
- 📂 Entrega tu trabajo en tu repositorio Git asignado. Solo el trabajo de tu repositorio Git será evaluado. Si Deepthought evalúa tu trabajo, lo hará después de tus compañeros. Si se encuentra un error durante la evaluación de Deepthought, esta habrá terminado.

# 📄 Enunciado

El objetivo del proyecto `get_next_line` es implementar una función en C que permita leer una línea completa desde un descriptor de archivo, independientemente de cómo esté segmentada en las lecturas. Esta función debe cumplir con las siguientes especificaciones:

1. **Prototipo de la función**:
    ```c
    char *get_next_line(int fd);
    ```
    - `fd`: Descriptor de archivo desde el cual se leerá la línea.

2. **Comportamiento esperado**:
    - La función debe devolver una línea terminada en un salto de línea (`\n`), excepto si el archivo no termina con un salto de línea.
    - Si no hay más líneas por leer, debe devolver `NULL`.
    - La función debe manejar correctamente errores en el descriptor de archivo o en la lectura.

3. **Restricciones**:
    - No se permite el uso de funciones estándar de la biblioteca como `malloc`, `free`y `read` fuera de las especificaciones del proyecto.
    - La función debe ser capaz de manejar múltiples descriptores de archivo simultáneamente (requisito obligatorio para el bonus).
    - El tamaño del búfer utilizado para la lectura será definido por la macro `BUFFER_SIZE`.

4. **Consideraciones adicionales**:
    - La memoria asignada dinámicamente debe ser liberada adecuadamente para evitar fugas.
    - El código debe cumplir con la Norma de 42.

Este ejercicio te permitirá desarrollar habilidades clave en la gestión de memoria dinámica, el manejo de archivos y la escritura de código modular y eficiente. ¡Buena suerte! 🚀

# 🛠️ Instrucciones de uso

## 🚀 Instrucciones de ejecución

1. Compilar el programa con la librería creada:
    ```bash
    cc main.c get_next_line.a
    ```

2. Ejecutar el programa:
    ```bash
    ./a.out
    ```

# ✅ Funcionalidades implementadas

La función `get_next_line` permite leer una línea completa desde un descriptor de archivo, soportando las siguientes características:

| 🛠️ Característica                    | 📜 Descripción                                                                 |
|-----------------------------------|-----------------------------------------------------------------------------|
| 📦 Lectura por bloques               | Utiliza un búfer para leer datos en bloques definidos por `BUFFER_SIZE`.    |
| 🔄 Manejo de múltiples descriptores  | Soporta la lectura simultánea desde múltiples descriptores de archivo.      |
| 🧹 Gestión de memoria eficiente      | Garantiza que no haya fugas de memoria durante la ejecución.                |

# 🔍 Funciones utilizadas

| 🛠️ Función           | 📜 Descripción                                                                 | 🔗 Enlace al README de la función                     |
|-------------------|-----------------------------------------------------------------------------|---------------------------------------------------|
| `get_next_line`   | Función principal que gestiona la lectura de líneas desde un descriptor.    | [README](./readmes_de_funciones/ft_get_next_line.md) |
| `ft_read_to_reminder`      | Función auxiliar utilizada para leer datos desde un descriptor de archivo y almacenarlos en un recordatorio.                 | [README](./readmes_de_funciones/ft_read_to_reminder.md)    |
| `ft_extract_line`       | Función auxiliar diseñada para extraer una línea completa desde un recordatorio.                       | [README](./readmes_de_funciones/ft_extract_line.md)     |

# 🎁 **BONUS**

El proyecto `get_next_line` incluye una sección de bonus que amplía las funcionalidades de la parte obligatoria. Estas características adicionales no son obligatorias, pero su implementación demuestra un nivel avanzado de comprensión y habilidades en programación. A continuación, se describen los requisitos y funcionalidades del bonus:

## 📜 Requisitos del bonus

- **Soporte para múltiples descriptores de archivo**: La función debe ser capaz de manejar la lectura simultánea desde múltiples descriptores de archivo sin interferencias entre ellos.
- **Normas de implementación**: Los archivos y funciones del bonus deben seguir las mismas reglas de la Norma que la parte obligatoria.
- **Separación de archivos**: Todas las funciones y headers relacionados con el bonus deben estar en archivos separados con el sufijo `_bonus` (por ejemplo, `get_next_line_bonus.c` y `get_next_line_bonus.h`).

## 🚀 Funcionalidades adicionales implementadas

| 🛠️ Característica                    | 📜 Descripción                                                                 |
|-----------------------------------|-----------------------------------------------------------------------------|
| 🔄 Manejo de múltiples descriptores  | Permite la lectura simultánea desde varios descriptores de archivo.         |
| 🗂️ Modularidad                       | Código separado en archivos específicos para facilitar la organización.     |

# 🛠️ Instrucciones de uso de la librería

## 🚀 Instrucciones de ejecución

1. Compilar el programa con la librería creada:
    ```bash
    cc main.c get_next_line_bonus.a
    ```

2. Ejecutar el programa:
    ```bash
    ./a.out
    ```

El bonus es una excelente oportunidad para demostrar tu capacidad de implementar soluciones avanzadas y optimizadas. ¡Buena suerte! 🚀

# 📝 **Nota de la corrección**  
🎯 **Puntuación obtenida:** **125** / 125  

🔍 **Consejo:** Revisa los puntos donde perdiste puntuación para aprender de ellos y evitar errores similares en el futuro. 🚀  

✨ ¡Sigue adelante y no te rindas! 🌈

# 🛠️ Herramientas recomendadas

En esta sección encontrarás una lista de herramientas que te serán útiles durante el desarrollo de este proyecto. Estas herramientas están diseñadas para facilitar la depuración, la escritura de código y la gestión de tu proyecto.

## 🧰 Lista de herramientas recomendadas

- **🛡️ Valgrind**: Para detectar fugas de memoria y errores relacionados con la gestión de memoria.
- **📏 Norminette**: Una herramienta para verificar que tu código cumple con la Norma de 42.
- **🧪 gnlTester**: Es una herramienta que comprueba todas las comprobaciones de [Francinette Image](./../README.md#-francinette) pero solo de **get next line**.

## Instalación y uso de herramientas específicas

### 🧪 gnlTester

`gnlTester` es una herramienta comunitaria diseñada para comparar el comportamiento de tu función `get_next_line` con el comportamiento esperado. Es especialmente útil para validar la precisión, robustez y compatibilidad de tu implementación en diferentes escenarios y con múltiples descriptores de archivo.

#### Instalación

1. **Clona el repositorio:**
    ```bash
    git clone https://github.com/Tripouille/gnlTester.git
    ```

2. **Accede al directorio del tester:**
    ```bash
    cd gnlTester
    ```

#### Ejecución de pruebas

- **Tests obligatorios:**
    ```bash
    make m
    ```
- **Tests de bonus:**
    ```bash
    make b
    ```
- **Todos los tests (obligatorios + bonus):**
    ```bash
    make a
    ```
- **Limpiar archivos generados:**
    ```bash
    make fclean
    ```

#### ⚠️ Importante

Si durante alguna de las pruebas del tester aparece un **TIMEOUT** ⏰, debes añadir la siguiente línea en el **Makefile** del tester para aumentar el tiempo de espera:

```makefile
TIMEOUT_US = 150000
```

Esto ayudará a evitar que las pruebas se detengan prematuramente por exceder el tiempo límite. ¡No olvides guardar los cambios antes de volver a ejecutar los tests! 🛠️🚦

> Consulta la [documentación oficial](https://github.com/Tripouille/gnlTester) para más detalles, opciones avanzadas y resolución de problemas.

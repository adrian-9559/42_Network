# 🌟 Introducción

El proyecto `pipex` es un ejercicio esencial en el currículo de 42 que te reta a recrear parte del comportamiento de la shell al gestionar tuberías entre procesos. 🔗 A través de este proyecto, aprenderás a redirigir la entrada y salida estándar, crear procesos hijos y comunicarte entre ellos usando pipes en C. 🛠️

Durante el desarrollo de `pipex`, profundizarás en conceptos clave como la manipulación de descriptores de archivo, la ejecución de comandos externos y la sincronización de procesos. 🚀 Este ejercicio es una excelente oportunidad para mejorar tus habilidades en la gestión de recursos del sistema y en la escritura de código robusto y modular. 🧠

La dificultad de este proyecto es intermedia y te preparará para abordar retos más avanzados en programación de sistemas. 🔑 El éxito radica en comprender a fondo cómo funciona la comunicación entre procesos y en seguir las normas de codificación de 42. 🧹 ¡Prepárate para sumergirte en el mundo de la programación de sistemas y llevar tus conocimientos al siguiente nivel! 💻✨

## 📋 Instrucciones generales

- Tu proyecto deberá estar escrito en C.
- Tu proyecto debe estar escrito siguiendo la Norma. Si tienes archivos o funciones adicionales, estas están incluidas en la verificación de la Norma y tendrás un 0 si hay algún error de norma en cualquiera de ellos.
- Tus funciones no deben terminar de forma inesperada (segfault, bus error, double free, etc) excepto en el caso de comportamientos indefinidos. Si esto sucede, tu proyecto será considerado no funcional y recibirás un 0 durante la evaluación.
- Toda la memoria asignada en el heap deberá liberarse adecuadamente cuando sea necesario. No se permitirán leaks de memoria.
- Si el enunciado lo requiere, deberás entregar un Makefile que compilará tus archivos fuente al output requerido con las flags -Wall, -Werror y -Wextra, utilizar cc y por supuesto tu Makefile no debe hacer relink.
- Tu Makefile debe contener al menos las normas $(NAME), all, clean, fclean y re.
- Para entregar los bonus de tu proyecto deberás incluir una regla bonus en tu Makefile, en la que añadirás todos los headers, librerías o funciones que estén prohibidas en la parte principal del proyecto. Los bonus deben estar en archivos distintos _bonus.{c/h}. La parte obligatoria y los bonus se evalúan por separado.
- Si tu proyecto permite el uso de la libft, deberás copiar su fuente y sus Makefile asociados en un directorio libft con su correspondiente Makefile. El Makefile de tu proyecto debe compilar primero la librería utilizando su Makefile, y después compilar el proyecto.
- Te recomendamos crear programas de prueba para tu proyecto, aunque este trabajo no será entregado ni evaluado. Te dará la oportunidad de verificar que tu programa funciona correctamente durante tu evaluación y la de otros compañeros.
- Y sí, tienes permitido utilizar estas pruebas durante tu evaluación o la de otros compañeros.
- Entrega tu trabajo en tu repositorio Git asignado. Solo el trabajo de tu repositorio Git será evaluado. Si Deepthought evalúa tu trabajo, lo hará después de tus compañeros. Si se encuentra un error durante la evaluación de Deepthought, esta habrá terminado.

# 📄 Enunciado

El objetivo del proyecto `pipex` es implementar en C un programa que simule el comportamiento de las tuberías de la shell, permitiendo encadenar la salida de un comando como entrada de otro. El programa debe cumplir con las siguientes especificaciones:

1. **Prototipo del programa**:
    ```bash
    ./pipex archivo_entrada comando1 comando2 archivo_salida
    ```
    - `archivo_entrada`: Archivo desde el que se leerá la entrada.
    - `comando1`: Primer comando a ejecutar, que recibirá la entrada del archivo.
    - `comando2`: Segundo comando a ejecutar, que recibirá la salida del primer comando.
    - `archivo_salida`: Archivo donde se escribirá la salida final.

2. **Comportamiento esperado**:
    - El programa debe crear una tubería entre `comando1` y `comando2`, de modo que la salida estándar de `comando1` se convierta en la entrada estándar de `comando2`.
    - La entrada de `comando1` debe provenir de `archivo_entrada` y la salida de `comando2` debe escribirse en `archivo_salida`.
    - Debe gestionar correctamente los errores de apertura de archivos, ejecución de comandos y creación de procesos.

3. **Restricciones**:
    - Solo se permite el uso de funciones estándar especificadas en el enunciado del proyecto.
    - El programa debe manejar correctamente la duplicación y cierre de descriptores de archivo.
    - No se permite el uso de funciones prohibidas por la Norma de 42.

4. **Consideraciones adicionales**:
    - Toda la memoria y recursos asignados deben ser liberados adecuadamente para evitar fugas.
    - El código debe cumplir con la Norma de 42 y ser modular y robusto.
    - Para la parte bonus, se podrá implementar el encadenamiento de múltiples comandos y el soporte para here_doc.

Este ejercicio te permitirá profundizar en la gestión de procesos, la comunicación entre ellos y el manejo avanzado de descriptores de archivo en C. ¡Mucho éxito! 🚀

# 🛠️ Instrucciones de uso

## 🚀 Instrucciones de ejecución

1. Compila el proyecto utilizando el Makefile proporcionado:
    ```bash
    make
    ```

2. Ejecuta el programa con la siguiente sintaxis:
    ```bash
    ./pipex archivo_entrada comando1 comando2 archivo_salida
    ```
    Por ejemplo:
    ```bash
    ./pipex infile "ls -l" "wc -l" outfile
    ```

# ✅ Funcionalidades implementadas

El programa `pipex` implementa las siguientes funcionalidades principales:

| 🛠️ Característica                  | 📜 Descripción                                                                 |
|------------------------------------|-------------------------------------------------------------------------------|
| 🔗 Comunicación entre procesos      | Crea una tubería que conecta la salida de un comando con la entrada de otro.  |
| 📂 Redirección de archivos         | Lee la entrada desde un archivo y escribe la salida en otro archivo.          |
| ⚙️ Ejecución de comandos externos   | Ejecuta comandos utilizando las rutas del sistema y gestiona argumentos.      |
| 🚦 Manejo de errores               | Detecta y reporta errores en apertura de archivos, ejecución y procesos.      |
| 🧹 Liberación de recursos           | Libera toda la memoria y recursos utilizados para evitar fugas.               |

# 📝 **Nota de la corrección**  
🎯 **Puntuación obtenida:** ND / 125  

🔍 **Consejo:** Revisa los puntos donde perdiste puntuación para aprender de ellos y evitar errores similares en el futuro. 🚀  

✨ ¡Sigue adelante y no te rindas! 🌈

# 🛠️ Herramientas recomendadas

En esta sección encontrarás una lista de herramientas que te serán útiles durante el desarrollo de este proyecto. Estas herramientas están diseñadas para facilitar la depuración, la escritura de código y la gestión de tu proyecto.

## 🧰 Lista de herramientas recomendadas

- **🛡️ Valgrind**: Para detectar fugas de memoria y errores relacionados con la gestión de memoria.
- **📏 Norminette**: Una herramienta para verificar que tu código cumple con la Norma de 42.
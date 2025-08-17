# 🌟 Introducción
El proyecto `push_swap` es una parte fundamental del currículo de 42 que te desafía a implementar un algoritmo eficiente para ordenar una pila de números utilizando un conjunto limitado de operaciones. 🔄 A través de este reto, aprenderás a diseñar y optimizar algoritmos, gestionar estructuras de datos como stacks y trabajar con restricciones específicas en C. 🛠️

Durante el desarrollo de `push_swap`, profundizarás en conceptos clave como la manipulación de listas enlazadas, la gestión de memoria dinámica y la minimización de la complejidad algorítmica. 🚀 Este ejercicio es ideal para fortalecer tus habilidades en lógica, análisis de eficiencia y escritura de código limpio y modular. 🧠

La dificultad de este proyecto es intermedia y te prepara para afrontar desafíos más avanzados en programación algorítmica y estructuración de proyectos. 🔑 El éxito depende de entender a fondo las operaciones permitidas y de aplicar estrategias inteligentes para reducir el número de movimientos. 🧹 ¡Prepárate para mejorar tu pensamiento algorítmico y llevar tus habilidades de programación al siguiente nivel! 💻✨

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

## 📄 Enunciado

✍️ Escribir un algoritmo de ordenamiento es un paso crucial en el viaje de un desarrollador. Normalmente es el primer encuentro con el concepto de complejidad.  
🧩 Los algoritmos de ordenamiento y su complejidad suponen una parte importante de las preguntas realizadas durante las entrevistas laborales.  
⏳ Es posiblemente un buen momento para echar un vistazo a estos conceptos ya que tendrás que enfrentarte a ellos en algún momento de tu vida.  
🎯 Los objetivos de aprendizaje de este proyecto son rigor, uso de C, y el uso de algoritmos básicos... haciendo especial hincapié en su complejidad.  
🔢 Ordenar valores es simple.  
⚡ Ordenarlos de forma rápida es menos simple, especialmente porque de una configuración de enteros a otra, la solución más eficiente para ordenar puede diferir.

# 📚 Reglas

Tienes **2 stacks**, llamados `a` y `b`.

- **Para empezar:**
    - El stack `a` contiene una cantidad aleatoria de números positivos y/o negativos.
    - El stack `b` está vacío.

- **Objetivo:**  
    Ordenar los números del stack `a` en orden ascendente utilizando solo las siguientes operaciones:

| Operación | Descripción |
|-----------|-------------|
| `sa`      | Intercambia los dos primeros elementos del stack `a`. No hace nada si hay uno o menos elementos. |
| `sb`      | Intercambia los dos primeros elementos del stack `b`. No hace nada si hay uno o menos elementos. |
| `ss`      | Realiza `sa` y `sb` al mismo tiempo. |
| `pa`      | Toma el primer elemento del stack `b` y lo pone el primero en el stack `a`. No hace nada si `b` está vacío. |
| `pb`      | Toma el primer elemento del stack `a` y lo pone el primero en el stack `b`. No hace nada si `a` está vacío. |
| `ra`      | Desplaza hacia arriba todos los elementos del stack `a` una posición; el primer elemento se convierte en el último. |
| `rb`      | Desplaza hacia arriba todos los elementos del stack `b` una posición; el primer elemento se convierte en el último. |
| `rr`      | Realiza `ra` y `rb` al mismo tiempo. |
| `rra`     | Desplaza hacia abajo todos los elementos del stack `a` una posición; el último elemento se convierte en el primero. |
| `rrb`     | Desplaza hacia abajo todos los elementos del stack `b` una posición; el último elemento se convierte en el primero. |
| `rrr`     | Realiza `rra` y `rrb` al mismo tiempo. |

# 🚀 Uso del programa

Para ejecutar el programa, proporciona una lista de números como argumentos. El programa mostrará la secuencia de operaciones necesarias para ordenar los números.

```bash
ARG="3 2 1"; ./push_swap $ARG
```

Puedes contar el número de movimientos realizados usando:

```bash
ARG="3 2 1"; ./push_swap $ARG | wc -l
```

1. **Prototipo del programa**:
    ```bash
    ARG="(NUMEROS A METER)"; ./push_swap $ARG | wc -l
    ```

# ✅ Validación del proyecto

Para validar este proyecto, deberás realizar ciertas pruebas con un número mínimo de operaciones.

- Para una validación mínima del proyecto (nota mínima de 80), deberás ser capaz de ordenar **100 números aleatorios en menos de 700 operaciones**.
- Para una validación máxima del proyecto y poder obtener los bonus, además del paso anterior, deberás ordenar **500 números aleatorios en menos de 5500 operaciones**.

# 📝 **Nota de la corrección**  
🎯 **Puntuación obtenida:** ND / 125  

🔍 **Consejo:** Revisa los puntos donde perdiste puntuación para aprender de ellos y evitar errores similares en el futuro. 🚀  

✨ ¡Sigue adelante y no te rindas! 🌈

# 🛠️ Herramientas recomendadas

En esta sección encontrarás una lista de herramientas que te serán útiles durante el desarrollo de este proyecto. Estas herramientas están diseñadas para facilitar la depuración, la escritura de código y la gestión de tu proyecto.

## 🧰 Lista de herramientas recomendadas

- **🛡️ Valgrind**: Para detectar fugas de memoria y errores relacionados con la gestión de memoria.
- **📏 Norminette**: Una herramienta para verificar que tu código cumple con la Norma de 42.
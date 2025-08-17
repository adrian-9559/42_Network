# 🌟 Introducción

# 📄 Enunciado

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
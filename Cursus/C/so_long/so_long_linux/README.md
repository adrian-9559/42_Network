# 🌟 Introducción
El proyecto `so_long` es una introducción práctica al desarrollo de videojuegos en C dentro del currículo de 42. 🕹️ Te desafía a crear un juego sencillo donde el jugador navega por un mapa, recoge objetos y alcanza la salida, todo mientras evita obstáculos y gestiona recursos limitados. 🌱

A lo largo de `so_long`, aprenderás a trabajar con matrices para representar mapas, gestionar la entrada del usuario y dibujar gráficos básicos usando la biblioteca MiniLibX. 🎨 Este proyecto te permitirá profundizar en el manejo de archivos, la lógica de juego y la gestión eficiente de memoria, aspectos fundamentales en la programación de sistemas. ⚡

La dificultad es accesible pero exige atención al detalle y rigor en la implementación. 🧩 El éxito depende de tu capacidad para estructurar el código, depurar errores y seguir las normas de codificación de 42. 🧹 Prepárate para explorar el mundo del desarrollo de videojuegos y fortalecer tus habilidades en C mientras te diviertes programando. 🚀✨

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

🕹️ El proyecto **so_long** consiste en crear un pequeño juego en C donde el jugador debe recorrer un mapa, recoger objetos y alcanzar la salida evitando obstáculos.  
🗺️ El mapa se representa como una matriz de caracteres y debe cumplir ciertas reglas de validez.  
🎮 El objetivo principal es aplicar conceptos fundamentales de programación en C, manejo de archivos, lógica de juego y gráficos básicos usando la biblioteca MiniLibX.  
🚀 Este proyecto fomenta el rigor en la implementación, el trabajo con estructuras de datos y el desarrollo de habilidades para depurar y optimizar código.  
🔍 Además, se enfatiza la importancia de la gestión de memoria y la correcta manipulación de recursos gráficos y de entrada/salida.


# 🧠 Introducción

El proyecto `philosophers` es una inmersión profunda en el mundo de la programación concurrente y la sincronización de hilos. 🍽️ Basado en el famoso problema de los "Filósofos Comensales" de Dijkstra, este desafío te llevará a explorar los conceptos fundamentales de la programación multihilo en C, la gestión de recursos compartidos y la prevención de deadlocks. 🔒

A lo largo de `philosophers`, dominarás el uso de pthreads, mutexes y semáforos para crear un sistema donde múltiples filósofos pueden cenar simultáneamente sin conflictos. 🧵 Este proyecto te enseñará a manejar condiciones de carrera (race conditions), sincronización de hilos, y la delicada arte de evitar tanto el hambre (starvation) como los bloqueos mutuos (deadlocks). ⚖️

La complejidad reside en la coordinación precisa: cada filósofo necesita dos tenedores para comer, pero solo hay tantos tenedores como filósofos. 🍴 El éxito depende de tu capacidad para implementar algoritmos de sincronización elegantes y eficientes, mientras mantienes el código limpio y libre de errores de concurrencia. 🚀✨

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

🧠 El proyecto **philosophers** implementa el clásico problema de los filósofos comensales usando programación concurrente en C.
🍽️ Cada filósofo alterna entre pensar, comer y dormir, pero necesita dos tenedores para comer, creando un problema de sincronización.
🧵 El objetivo principal es gestionar hilos (threads) y recursos compartidos usando mutexes para evitar condiciones de carrera y deadlocks.
⚖️ Este proyecto desarrolla habilidades esenciales en programación concurrente, sincronización de hilos y gestión eficiente de recursos compartidos.
🔒 Se enfatiza la importancia de implementar algoritmos robustos que prevengan tanto el hambre (starvation) como los bloqueos mutuos (deadlocks).

## 🎯 Objetivos del proyecto

### 🔧 Técnicos

- **Programación multihilo**: Dominar el uso de pthreads en C
- **Sincronización**: Implementar mutexes para proteger recursos compartidos
- **Gestión de tiempo**: Usar funciones de tiempo precisas para controlar las acciones
- **Prevención de deadlocks**: Implementar estrategias para evitar bloqueos mutuos
- **Optimización**: Crear código eficiente que minimice la latencia y maximice el paralelismo

### 🎓 Educativos

- Comprender los fundamentos de la programación concurrente
- Aprender a identificar y resolver condiciones de carrera
- Desarrollar habilidades de debugging en entornos multihilo
- Dominar la sincronización y coordinación entre hilos
- Aplicar teoría de sistemas operativos en problemas reales

## ⚙️ Uso del programa

### 📝 Sintaxis

```bash
./philosophers [número_de_filósofos] [tiempo_muerte] [tiempo_comer] [tiempo_dormir] [número_comidas]
```

### 📋 Parámetros

- **número_de_filósofos**: Número de filósofos y tenedores (1-200)
- **tiempo_muerte**: Tiempo en ms que un filósofo puede estar sin comer antes de morir
- **tiempo_comer**: Tiempo en ms que tarda un filósofo en comer
- **tiempo_dormir**: Tiempo en ms que tarda un filósofo en dormir
- **número_comidas** (opcional): Número de veces que cada filósofo debe comer

### 🚀 Ejemplos de uso

#### Ejemplo básico (5 filósofos, ninguno debe morir)

```bash
./philosophers 5 800 200 200
```

#### Ejemplo con límite de comidas

```bash
./philosophers 5 800 200 200 7
```

#### Caso extremo (debe morir)

```bash
./philosophers 4 310 200 100
```

#### Caso de un solo filósofo

```bash
./philosophers 1 800 200 200
```

### 📊 Interpretando la salida

```
[timestamp_ms] [filósofo_id] [acción]
```

**Acciones posibles:**

- `has taken a fork` - Ha tomado un tenedor
- `is eating` - Está comiendo
- `is sleeping` - Está durmiendo
- `is thinking` - Está pensando
- `died` - Ha muerto

## 🏗️ Arquitectura del proyecto

### 📁 Estructura de archivos

```
philosophers/
├── Makefile
├── README.md
├── include/
│   └── philosophers.h
└── src/
    ├── main.c
    ├── init.c
    ├── simulation.c
    ├── actions.c
    ├── utils.c
    └── cleanup.c
```

### 🧱 Componentes principales

#### 🏛️ Estructuras de datos

```c
typedef struct s_philosopher
{
    int             id;
    int             meals_eaten;
    long            last_meal_time;
    pthread_t       thread;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
    t_simulation    *sim;
}   t_philosopher;

typedef struct s_simulation
{
    int             num_philosophers;
    int             time_to_die;
    int             time_to_eat;
    int             time_to_sleep;
    int             meals_required;
    long            start_time;
    int             simulation_end;
    pthread_mutex_t print_mutex;
    pthread_mutex_t death_mutex;
    pthread_mutex_t *forks;
    t_philosopher   *philosophers;
}   t_simulation;
```

#### 🔄 Flujo de ejecución

1. **Inicialización**: Parsing de argumentos, creación de estructuras y mutexes
2. **Creación de hilos**: Lanzamiento de un hilo por cada filósofo
3. **Simulación**: Cada filósofo ejecuta su ciclo de vida independientemente
4. **Monitoreo**: Hilo principal verifica condiciones de finalización
5. **Limpieza**: Liberación de recursos y sincronización de hilos

## 🧪 Casos de prueba recomendados

### ✅ Casos que NO deben morir

```bash
./philosophers 5 800 200 200        # Caso básico estable
./philosophers 5 800 200 200 7      # Con límite de comidas
./philosophers 4 410 200 200        # Límite justo
./philosophers 100 800 200 200      # Muchos filósofos
```

### ❌ Casos que SÍ deben morir

```bash
./philosophers 4 310 200 100        # Tiempo insuficiente
./philosophers 1 800 200 200        # Un solo filósofo (imposible comer)
./philosophers 2 300 200 100        # Dos filósofos, tiempo ajustado
```

### 🔍 Casos límite

```bash
./philosophers 1 400 200 200        # Caso mínimo
./philosophers 200 800 200 200      # Caso máximo
./philosophers 5 400 100 100        # Tiempos mínimos
```

## 🐛 Debugging y herramientas

### 🔧 Compilación con flags de debug

```bash
make debug  # Compila con -g -fsanitize=thread
```

### 🕵️ Herramientas útiles

```bash
# Detección de race conditions
gcc -fsanitize=thread -g philosophers.c

# Detección de leaks de memoria
valgrind --tool=memcheck --leak-check=full ./philosophers 5 800 200 200

# Análisis de deadlocks
valgrind --tool=helgrind ./philosophers 5 800 200 200
```

### 📊 Scripts de prueba

```bash
# Prueba de estabilidad (100 ejecuciones)
for i in {1..100}; do ./philosophers 5 800 200 200 7; done

# Prueba de límites de tiempo
./philosophers 4 310 200 100 | grep "died"
```

## ⚠️ Problemas comunes y soluciones

### 🔄 Race Conditions

- **Problema**: Múltiples hilos accediendo al mismo recurso
- **Solución**: Proteger acceso con mutexes
- **Ejemplo**: Usar mutex para imprimir mensajes

### 🔒 Deadlocks

- **Problema**: Filósofos esperando indefinidamente por tenedores
- **Solución**: Ordenar la toma de tenedores o usar timeouts
- **Estrategia**: Filósofos pares toman tenedor izquierdo primero

### ⏱️ Timing Issues

- **Problema**: Imprecisión en medición de tiempo
- **Solución**: Usar gettimeofday() y cálculos precisos
- **Tip**: Verificar tiempo antes de cada acción crítica

### 🍴 Fork Management

- **Problema**: Gestión incorrecta de tenedores
- **Solución**: Asegurar liberación simétrica de recursos
- **Patrón**: Siempre liberar en orden inverso a la adquisición

## 🎓 Conceptos clave aprendidos

### 🧵 Programación Concurrente

- **Threads**: Creación y gestión de hilos con pthread
- **Mutexes**: Sincronización y protección de recursos compartidos
- **Atomicidad**: Operaciones que no pueden ser interrumpidas
- **Sincronización**: Coordinación entre múltiples hilos

### 🔒 Problemas de Concurrencia

- **Race Conditions**: Comportamiento dependiente del timing
- **Deadlocks**: Bloqueo mutuo de recursos
- **Starvation**: Privación prolongada de recursos
- **Priority Inversion**: Inversión de prioridades

### ⏰ Gestión de Tiempo

- **Precisión temporal**: Medición exacta de intervalos
- **Timeouts**: Límites de tiempo para operaciones
- **Scheduling**: Planificación de tareas concurrentes

## 🏆 Criterios de evaluación

### ✅ Funcionalidad (60%)

- Compilación sin errores ni warnings
- Gestión correcta de argumentos de entrada
- Implementación completa del ciclo de vida del filósofo
- Detección precisa de muerte por hambre
- Finalización correcta con número de comidas

### 🧵 Concurrencia (25%)

- Uso correcto de pthreads
- Sincronización apropiada con mutexes
- Ausencia de race conditions
- Prevención efectiva de deadlocks

### 💾 Gestión de Memoria (10%)

- Sin memory leaks
- Liberación correcta de todos los recursos
- Gestión apropiada de mutexes y threads

### 📝 Calidad de Código (5%)

- Cumplimiento de la Norma 42
- Código limpio y bien estructurado
- Documentación adecuada

## 🚀 Mejoras y extensiones

### 🔧 Optimizaciones avanzadas

- Implementar algoritmo de Chandy-Misra para prevención de deadlocks
- Usar atomic operations para contadores compartidos
- Implementar priority scheduling para filósofos hambrientos

### 📊 Métricas y análisis

- Contador de race conditions evitadas
- Tiempo promedio entre comidas
- Distribución de uso de tenedores
- Análisis de eficiencia del algoritmo

### 🎮 Funcionalidades bonus

- Interfaz gráfica para visualizar el estado
- Logs detallados con timestamps precisos
- Configuración dinámica de parámetros
- Simulación con diferentes estrategias de scheduling

---

💡 **Tip final**: La clave del éxito en `philosophers` está en la sincronización precisa y la gestión cuidadosa de recursos. Piensa como un director de orquesta coordinando múltiples músicos - cada hilo debe tocar su parte en el momento exacto para crear una sinfonía perfecta. 🎼✨

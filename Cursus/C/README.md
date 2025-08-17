# 🌟 Introducción

## 🚀 Proyectos de lenguaje C en 42 Madrid

Este repositorio contiene una colección de proyectos realizados como parte del programa de formación en 42 Madrid. Cada proyecto está diseñado para desarrollar habilidades en programación en C, siguiendo estrictas normas de codificación y buenas prácticas. A continuación, se describen algunos aspectos clave:

- **📏 Normas estrictas**: Los proyectos deben cumplir con la Norma de 42, asegurando un código limpio, estructurado y sin errores de estilo.
- **🧠 Gestión de memoria**: Se requiere una gestión adecuada de la memoria, evitando fugas y liberando todos los recursos asignados.
- **🔍 Evaluación rigurosa**: Los proyectos son evaluados tanto por compañeros como por herramientas automatizadas como Deepthought.
- **✨ Bonus y modularidad**: Se fomenta la implementación de funcionalidades adicionales (bonus) en archivos separados, promoviendo la modularidad del código.
- **🛠️ Uso de Makefiles**: Los proyectos que necesiten de un Makefile deben incluir un Makefile funcional que facilite la compilación y limpieza del entorno de trabajo.

Estos proyectos no solo fortalecen las bases de la programación en C, sino que también preparan a los estudiantes para enfrentar desafíos reales en el desarrollo de software.

## 📚 Ejercicios a realizar
- [📂 Libft](./Libft/README.md)
- [🖨️ Printf](./printf/README.md)
- [📜 Get Next Line](./get_next_line/README.md)
- [🔗 Pipex](./pipex/README.md)
- [🔄 Push Swap](./push_swap/README.md)
- [🎮 So_long](./so_long/README.md)

## 🛠️ Herramientas opcionales a instalar

### 🧹 Norminette

La **Norminette** es una herramienta de análisis estático de código utilizada en la 42 Network para garantizar que el código fuente cumpla con las normas de estilo y convenciones establecidas por la escuela. Estas normas están diseñadas para fomentar la legibilidad, la consistencia y las buenas prácticas en la programación.

🔑 **Puntos clave que verifica la Norminette**:
- Longitud máxima de líneas y funciones.
- Correcto uso de espacios y tabulaciones.
- Nombres de variables y funciones descriptivos y en el formato adecuado.
- Organización y estructura del código, como el uso correcto de llaves y la separación de funciones.

#### 🛠️ Instalación

1. Clonar el repositorio de GitHub:
```bash
git clone https://github.com/42school/norminette.git norminette
```

2. Entrar en el directorio del repositorio clonado:
```bash
cd norminette
```

3. Ejecutar el comando de instalación de la herramienta:
```bash
python3 -m pip install norminette
```

#### ▶️ Ejecución

Para ejecutar la Norminette en tu proyecto, usa el siguiente comando en la terminal:

```bash
norminette
```

#### ❓ Solución a problemas comunes

Si aparece el error:
```bash
zsh: command not found: norminette
```

Sigue estos pasos:

1. **🔍 Verifica la ruta del ejecutable de Norminette**  
    Ejecuta:
    ```bash
    python3 -m site --user-base
    ```
    Esto debería devolver una ruta como:
    ```bash
    /Users/adrian_9559/Library/Python/3.9
    ```

2. **📂 Accede al directorio del ejecutable**  
    Cambia al directorio correspondiente:
    ```bash
    cd /Users/adrian_9559/Library/Python/3.9/bin
    ```

3. **🛠️ Añade la ruta al archivo PATH**  
    Agrega la ruta al archivo de configuración de tu terminal (`~/.zshrc` o `~/.zprofile`):
    ```bash
    echo 'export PATH=$PATH:/Users/adrian_9559/Library/Python/3.9/bin' >> ~/.zshrc
    ```

4. **🔄 Aplica los cambios**  
    Recarga la configuración de tu terminal:
    ```bash
    source ~/.zshrc
    ```

5. **✅ Verifica la instalación**  
    Comprueba que **Norminette** está correctamente instalado:
    ```bash
    norminette --version
    ```

#### 📖 Documentación original

Consulta la [documentación oficial](https://github.com/42school/norminette/tree/master#readme) para más detalles.

### 🤖 Francinette

La **Francinette** es una herramienta de evaluación automatizada diseñada para probar y validar los proyectos de 42. Permite a los estudiantes verificar el cumplimiento de los requisitos del proyecto y detectar errores antes de la evaluación oficial.

#### 🛠️ Instalación

1. Ejecutar el script de instalación:
```bash
bash -c "$(curl -fsSL https://raw.githubusercontent.com/WaRtr0/francinette-image/master/install.sh)"
```

#### ▶️ Ejecución

Para ejecutar la herramienta, asegúrate de estar en el directorio del proyecto. Luego, utiliza:
```bash
paco
```

#### ❓ Solución a problemas comunes

Si aparece el error:
```bash
zsh: command not found: paco
```

Sigue los mismos pasos descritos en la sección de **Norminette** para añadir la ruta al archivo PATH.

#### 📖 Documentación original

Consulta la [documentación oficial](https://github.com/xicodomingues/francinette/tree/master#readme) para más detalles.

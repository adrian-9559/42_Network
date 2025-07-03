# Introducción

El proyecto **Born2beroot** es una introducción al mundo de la administración de sistemas y la virtualización. 🌐 A través de este ejercicio, aprenderás a configurar y gestionar un servidor virtualizado, implementando buenas prácticas de seguridad y optimización. 🔒 Este proyecto está diseñado para ayudarte a comprender los fundamentos de los sistemas operativos y la administración de servidores, habilidades esenciales para cualquier desarrollador o administrador de sistemas. 🛠️

El objetivo principal es instalar y configurar una máquina virtual con un sistema operativo basado en Linux, siguiendo una serie de requisitos específicos. 🚀 Este proyecto te permitirá explorar conceptos como la gestión de usuarios, permisos, particiones, servicios y configuraciones de red. 🌟

Además, **Born2beroot** es un desafío que fomenta la autonomía y la resolución de problemas, preparándote para proyectos más avanzados en el futuro. 🔑 La clave del éxito radica en documentar cada paso del proceso y garantizar que tu configuración sea robusta y segura. 🧹 ¡Prepárate para sumergirte en el fascinante mundo de la administración de sistemas y llevar tus habilidades al siguiente nivel! 💻✨

## Instrucciones generales

- El uso de VirtualBox es obligatorio (o UTM en caso de que VirtualBox no funcione en tu máquina).
- Solo debes entregar un archivo llamado signature.txt en la raíz de tu repositorio. Debes pegar en él la firma del disco virtual de tu máquina. Ve a Entrega y evaluación para más información.

# Intrucciones para realizar el proyecto
En este apartado encontrarás una guía paso a paso para llevar a cabo el proyecto **Born2beroot**. Se detallarán las acciones necesarias desde la preparación del entorno hasta la configuración de la máquina virtual, asegurando que cumplas con todos los requisitos y buenas prácticas recomendadas. Sigue cada sección cuidadosamente para lograr una instalación y configuración exitosa.

## 1. Descargar la ISO
Antes de comenzar la instalación, es necesario descargar la imagen ISO del sistema operativo que vas a utilizar en tu máquina virtual. Puedes elegir entre **Debian** o **Rocky Linux**, según tus preferencias y los requisitos del proyecto.

- [Descargar Debian](https://www.debian.org/index.es.html#:~:text=operativo%20completamente%20libre!-,Descargar,-Otras%20descargas)
- [Descargar Rocky](https://rockylinux.org/es-ES#:~:text=by%20the%20community.-,Download,-Migrate)

Asegúrate de seleccionar la versión adecuada (generalmente la versión estable más reciente) y la arquitectura compatible con tu hardware (normalmente x86_64 o amd64).

Una vez descargada la ISO, guárdala en una ubicación accesible, ya que la necesitarás para crear la máquina virtual en el siguiente paso.

**En mi caso he seleccionado Debian**

## 2. Creación de la máquina virtual
**"Importante"** Si no tienes VirtualBox, aquí te dejo el link de descarga de la aplicación. [**Descarga 🔎**](https://www.virtualbox.org/wiki/Downloads)

1.  **Crear una máquina virtual**
    Para crear una máquina virtual, tenemos que darle a ``New\Nueva``.
    <div>
        <img src="./imagenes/BotonNew.png">
    </div>

2.  **Selección de opciones principales**
    Una vez dentro, tenemos que poner nombre a la máquina virtual, despues seleccionamos la ISO del sistema que deseamos hacer la máquina virtual.
    <div>
        <img src="./imagenes/VentanaCreacionMaquinas.png">
    </div>

3.  **Hardware principal de la máquina virtual**
    En esta ventana, tenemos que indicar la cantidad de memoria RAM que va a utilizar la máquina y el número de núcleos que va a utilizar.
    <div>
        <img src="./imagenes/VentanaSeleccionRAMCPU.png">
    </div>

4.  **Memoria de la máquina virtual**
    En este paso vamos a asignar que la reserva de memoria de la máquina sea en formato de *Virtual Hard Disk* y vamos a darle 10 GB de almacenamiento.
    <div>
        <img src="./imagenes/VentanaSeleccionDiscoDuro.png">
    </div>

5.  **Información de la máquina virtual**
    En esta última ventana nos aparece toda la información importante de la máquina virtual.
    <div>
        <img src="./imagenes/VentanaInformacionMaquinaVirtual.png">
    </div>

## 3. Instalación del Sistema Operativo
En este apartado se explicará el proceso de instalación del sistema operativo elegido en la máquina virtual. Se detallarán los pasos clave para llevar a cabo una instalación limpia y segura, asegurando que el entorno esté correctamente configurado desde el inicio. Sigue atentamente las instrucciones para evitar errores y garantizar que tu sistema esté listo para las siguientes fases del proyecto.

1.  **Elección de idioma**
    He elegido inglés porque es el idioma estándar en informática y facilita el acceso a documentación y soporte técnico.
    <div>
        <img src="./imagenes/1.png">
    </div>

2.  **Selección de región**
    Selecciona tu zona geográfica y país para configurar correctamente la localización del sistema. Esto afectará la zona horaria y algunos ajustes regionales.
    <div style="display: flex; gap: 2%; align-items: flex-start;">
        <img src="./imagenes/2.png" width="32%">
        <img src="./imagenes/3.png" width="32%">
        <img src="./imagenes/4.png" width="32%">
    </div>

3.  **Selección del lenguaje del teclado**
    Elige la distribución de teclado adecuada para tu idioma y tipo de teclado (por ejemplo, "Spanish" o "English (US)") para que las teclas funcionen correctamente.

    <div style="display: flex; gap: 2%; align-items: flex-start;">
        <img src="./imagenes/5.png" width="48%">
        <img src="./imagenes/6.png" width="48%">
    </div>

4.  **Nombre del sistema**
    En este paso debes asignar un nombre único a tu sistema (hostname). El nombre del sistema identifica tu máquina en la red y es útil para su administración. Elige un nombre descriptivo y fácil de recordar, evitando espacios y caracteres especiales. En este caso, tiene que ser tu login seguido de 42.

    <div>
        <img src="./imagenes/7.png">
    </div>

5.  **Configuración del dominio del servidor**
    En este paso puedes dejar el campo de dominio vacío si no cuentas con uno propio, ya que no es obligatorio para el proyecto. Si decides establecer un dominio, debe ser un nombre válido que identifique tu red local (por ejemplo, `miempresa.local`). Para la mayoría de los casos en Born2beroot, simplemente pulsa "Continue" sin rellenar este campo.

    <div>
        <img src="./imagenes/8.png">
    </div>

6.  **Contraseña del usuario root**
    Durante la instalación, se te pedirá establecer una contraseña para el usuario `root`. Elige una contraseña segura que combine letras mayúsculas, minúsculas, números y símbolos. Recuerda anotarla en un lugar seguro, ya que será necesaria para realizar tareas administrativas en el sistema. Evita contraseñas simples o fáciles de adivinar para proteger tu servidor de accesos no autorizados.

    <div style="display: flex; gap: 2%; align-items: flex-start;">
        <img src="./imagenes/9.png" width="48%">
        <img src="./imagenes/10.png" width="48%">
    </div>

7.  **Usuario**
    En este paso debes crear un usuario no privilegiado que utilizarás para las tareas diarias en el sistema. Introduce el nombre completo del usuario y el nombre de usuario (login), que normalmente será tu login de 42.

    En este apartado ponemos el nombre completo del usuario.

    <div>
        <img src="./imagenes/11.png">
    </div>

    En esta parte introduce el nombre de usuario (login), que habitualmente corresponde a tu identificador de 42.  

    <div>
        <img src="./imagenes/12.png">
    </div>

    Después de definir el nombre de usuario, deberás establecer una contraseña segura para este usuario no privilegiado. Es recomendable que la contraseña cumpla con los siguientes requisitos:<br>
    - Al menos 8 caracteres.<br>
    - Incluya letras mayúsculas y minúsculas.<br>
    - Contenga números y símbolos.<br>
    Esto garantiza una mayor seguridad para tu sistema. Recuerda guardar la contraseña en un lugar seguro, ya que la necesitarás para iniciar sesión y realizar tareas cotidianas. 

    <div style="display: flex; gap: 2%; align-items: flex-start;">
        <img src="./imagenes/13.png" width="48%">
        <img src="./imagenes/14.png" width="48%">
    </div>

8.  **Zona horaria del sistema**
    Selecciona la zona horaria correspondiente a tu ubicación. Esto es importante para que el sistema registre correctamente la hora local y los eventos programados funcionen adecuadamente. Por ejemplo, si te encuentras en España, selecciona "Europe/Madrid".

    <div>
        <img src="./imagenes/15.png">
    </div>

9.  **Encriptado del disco duro**
    Durante la instalación, selecciona la opción de cifrado del disco para proteger los datos almacenados en tu máquina virtual. El instalador te preguntará si deseas utilizar el cifrado con LVM (Logical Volume Manager). Elige "Guided - use entire disk and set up encrypted LVM" y sigue las instrucciones para establecer una contraseña de cifrado. Esta contraseña será necesaria cada vez que inicies el sistema, así que guárdala en un lugar seguro. El cifrado del disco añade una capa adicional de seguridad, asegurando que los datos no puedan ser accedidos sin autorización incluso si alguien obtiene acceso físico al archivo del disco virtual.

    <div>
        <img src="./imagenes/16.png">
    </div>


10. **Selección de particiones**
    Selecciona la unica partición del sistema que existe en ese momento.

    <div>
        <img src="./imagenes/17.png">
    </div>

11. **Configuración de particiones**
    En este apartado seleccionamos la opción de particionado manual y eliminamos todas las particiones existentes, si las hubiera. Luego, creamos una única partición para `/home`, asignándole todo el espacio disponible. Deja sin crear particiones para `/` (raíz) y `swap`, de modo que todo el sistema se instale en `/home`. Confirma los cambios y continúa con la instalación. Esta configuración es poco habitual, pero cumple con el requisito de tener solo la partición de home.

    <div>
        <img src="./imagenes/18.png">
    </div>

# Preguntas de corrección

## ¿Que es una Máquina Virtual?
Una VM es una aplicación que le permite instalar un sistema operativo adicional en su máquina física, lo que le permite ejecutar ambos sistemas simultáneamente.

## Beneficios de usar Máquinas Virtuales
Principales beneficios de las máquinas virtuales :
- Rentable : los costos de mantenimiento son prácticamente cero ya que la VM comparte componentes físicos con su computadora.
- Seguridad : En caso de riesgo de seguridad, su equipo principal permanece seguro. Por ejemplo, si un virus afecta la máquina virtual, puede desinstalarla en segundos sin consecuencias para el sistema host.

## Selección de ISO
**Debian**: Es una distribución reconocida por su estabilidad, amplia documentación y gran comunidad de soporte. Es ideal para quienes buscan un sistema robusto, seguro y fácil de mantener, siendo especialmente recomendable para entornos de aprendizaje y servidores de propósito general.

**Rocky Linux**: Está orientada al ámbito empresarial y es compatible con RHEL (Red Hat Enterprise Linux). Destaca por sus avanzadas medidas de seguridad, soporte a largo plazo y el uso de gestores de paquetes como `yum` y `dnf`, lo que facilita la administración de software en entornos complejos y profesionales.

La elección entre Debian y Rocky Linux dependerá de tus necesidades: si buscas simplicidad y estabilidad, Debian es una excelente opción; si prefieres un entorno más cercano al estándar empresarial, Rocky Linux es recomendable.

## ¿Cuales son las diferencias entre **APT** y **Aptitude**?
**APT**: Ejecuta únicamente los comandos especificados en la línea de comando, gestionando paquetes de manera sencilla y directa.

**Aptitude**: Es una versión más avanzada de APT que ofrece una interfaz interactiva y distingue entre los paquetes instalados explícitamente y sus dependencias. Además, elimina automáticamente las dependencias que ya no se utilizan, facilitando la gestión y limpieza del sistema.

## ¿Qué es **AppArmor**?
**AppArmor** es un sistema de control de acceso obligatorio (MAC) utilizado por defecto en Debian para reforzar la seguridad del sistema. Permite definir perfiles de seguridad para cada aplicación, limitando estrictamente los recursos y archivos a los que pueden acceder. De este modo, incluso si una aplicación es comprometida, AppArmor reduce el impacto restringiendo sus acciones solo a lo estrictamente necesario para su funcionamiento.

# 📝 **Nota de la corrección**  
🎯 **Puntuación obtenida:** **100** / 125  

🔍 **Consejo:** Revisa los puntos donde perdiste puntuación para aprender de ellos y evitar errores similares en el futuro. 🚀  

✨ ¡Sigue adelante y no te rindas! 🌈

# Herramientas recomendadas

- **VirtualBox/UTM**: Para la virtualización de tu máquina. [**Descarga**](https://www.virtualbox.org/wiki/Downloads)
- **SSH**: Para la gestión remota del servidor.

¡Buena suerte con tu proyecto Born2beroot! 🚀


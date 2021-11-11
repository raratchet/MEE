# BIENVENIDO A MODULAR EDUCATIONAL ENGINE (MEE)

Modular Educational Engine consiste en crear un motor de videojuegos 2D modular, que permitar crear los diferentes
sistemas que conforman un motor de juegos por separado, para de esa manera facilitar el 
aprendizaje de como funcionan y se construyen los motores de juegos.

MEE al igual que sus módulos se encuentran compilados como librería dinámica. 
Esto es con la intención de que un juego hecho con el motor no arrastre las dependecias del motor, 
y sea más fácil su uso.

Sobre el motor:
Modular Educational Engine no es un motor por si solo, es el conjunto de motor y 
módulos y juego que componen un programa. La interacción de estas tres partes las que permiten
tener un programa funcional. El juego es el punto de entrada al programa.

El hecho de que MEE y módulos sean librerias dinámicas permite que estos elementos se puedan 
reemplazar con relativa facilidad sin afectar al propio motor, otros módulos, o a la parte del juego. 
Esto es especialmente útil para hacer parches en caso de que se detecten errores o en caso de desarrollos incrementales,
donde las funcionalidades del motor o de algún módulo crecen mientras se sigue con el desarrollo.

La intención de MEE es que forme parte del aprendizaje de un alumno que se inicia en el desarrollo 
de videojuegos.
El alumno:
- Desarrolla su primer juego
- Mejora sus habilidades de programación
- Comprende como funcionan los engines (aunque sea a un nivel básico)
- Crea su propio módulo para el motor
- Crea herramientas y mejora al motor con nuevos plugins.

Esa sería una línea que se espera de este proyecto. Un crecimiento incremental, el alumno puede
ver su progreso, mantener y mejorar lo que ya ha trabajado conforme avanza en su crecimiento y educación.

Conceptos clave:
El motor se conforma de tres elementos fundamentales. Módulo, Motor y Juego.
Los Módulos incorporan la funcionalidad. Ej: Dibujar en pantalla o manejar el input.
El Motor incorpora herramientas, convenciones y revisa el correcto funcionamiento de las partes.
El Juego incorpora la lógica que hace a un juego.

El motor no tiene dependencias fuertes con ningun módulo, pero sí tiene requerimientos básicos para los módulos.
Esto quiere decir que el juego no tiene queañadir ninguna depencias además del motor. 
Para lograr esto el motor se víncula dinámicamente con los módulos. Puedes leer más de este proceso en el artículo de módulos. 
Para esto el motor proporciona unos header files a manera de interfaces entre un módulo X y el motor, que contienen
los requisitos.

## Cómo usar MEE 

### Módulos

La información que necesitas para entender cómo crear un módulo la puedes ver ~~aquí~~.

### MODULAR ENGINE GAME

Actualmente el motor no cuenta con un editor de niveles y el pipline para crear un juegos
sigue muy verde y con constantes cambios, sin embargo si lo que buscas es hacer un juego con el motor para probrar tus 
módulos o simplemente por la aventura ,puedes consultar esta página. __MEG__

## Documentación en progreso

Esta documentación aún está en progreso y se encuentra mayoritariamente en inglés, por lo que te pido una disculpa si el contenido que buscas
no está o está incompleto.

Puedes enviar tu feedback al siguiente correo maximiliano.herrera@saei.mx


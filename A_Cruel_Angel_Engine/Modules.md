# Módulos
En esta página se explica qué es y cómo funcioanan y se elabora un módulo para MEE.

> **Aviso:** Los módulos están pensados para gente que ya tiene un nivel
intermedio o superior en programación y en C++, por lo que no es recomendado
para principiantes.

## Entendiendo que es un módulo.

Un módulo es un tipo de ~~plugin~~ para MEE que aporta funcionamiento básico para el
motor, esto quiere decir que compone un subsistema del motor para que este funcione
adecuadamente.

> **Algunos ejemplos son:** 
>- Renderizado
>- Sonido
>- Input
>- Física

Los módulos siempre deben proporcionar al motor lo que el este considera indispensable para
su funcionamiento. Estos requiermientos pueden variar según el subsistema que se esté trabajando,
y es importante que revises la guía para el subsistema para el que trabajas.

## Comunicación motor <-> módulo

MEE propociona varios *header files*, uno para cada subsitema, que existen a manera de interfaz entre un módulo 
y el motor. En estos archivos se encuentran contenidos las firmas para todas las funciones
que el motor considera para dicho subsistema.
> **Nota:** No todas las funciones en los *header files* se consideran
 indispensables para el motor. Esto último se encuentra indicado en cada función.

## Entendiendo las etapas.

Los módulos tienen 6 funciones que sirven para ejecutar código en distintos puntos
de la ejecucción del motor *(puedes consultar el diagrama de flujo del engine para saber en que punto  se encuentra cada una)*. 
Dichas funciones son:

- OnInit
- OnLoad
- OnUpdate
- OnPostUdate
- OnDraw
- OnShutdown

De estas funciones *OnInit, OnLoad y OnShutdown* son obligatorias en su implementación.
No contener una o más de estás funciones dara como resultado un error en la carga del módulo.

OnInit entrega como parámetro un *int*, que representa el *plugin_id* que se le fue dado
al módulo en su etapa de carga.

>**Aviso:** Es importante que dentro de OnInit se haga el enlazamiento de funciones, pues es al terminar esta etapa 
que el motor hace la verificación de las funciones indispensables. Si una o más funciones indispensables no están listas en este punto
el motor lazará un error.


## Enlazando funciones al motor.

En el *header file* de cada submódulo existen una serie de funciones 
para enlazar una función de un módulo al engine. Estas funciones requieren
un *plugin id* y el nombre de la función que se va enlazar.

>**Aviso:** Para enlazar una función usando este método es importante que la función
esté declarada como:

```cpp
extern "C" __declspec(dllexport)
```

>pues las funciones se cargan adquiriendo su memoria del dll. Existen macros dentro de los *header files*
para alivarte este paso.

>**Precaución:** Estas funciones  de enlazamiento  convierten la función dada
a una función compatible con la firma dada por el motor. Es importante que los
parámetros originales de la función sean compatibles con la firma. Fallar en este
paso da lugar a un comportamiento indefindo.

Dentro de los *header files* se encuetran los *functors* que el motor usa para hacer
las llamadas al módulo, puedes enlazar cada una de las funciones manualmente, aunque esto 
no es recomendado.


## Integrando tu módulo al motor

Una vez tengas compilado tu módulo debes colcarlo en la carpeta Plugins contenido dentro de su propia carpeta.
Además deberá tener a su lado un archivo info.yaml donde se específique su nombre, su versión 
y en caso de tenerlas sus dependecias a otros plugins. Una vez que tengas todo esto el motor debería poder
detectarlo y cargarlo.

>**Aviso:** Sin la presencia del archivo info.yaml el módulo no podrá ser cargado,
y el motor lo ignorará.




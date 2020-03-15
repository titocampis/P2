PAV - P2: detección de actividad vocal (VAD)
============================================

Esta práctica se distribuye a través del repositorio GitHub [Práctica 2](https://github.com/albino-pav/P2),
y una parte de su gestión se realizará mediante esta web de trabajo colaborativo.  Al contrario que Git,
GitHub se gestiona completamente desde un entorno gráfico bastante intuitivo. Además, está razonablemente
documentado, tanto internamente, mediante sus [Guías de GitHub](https://guides.github.com/), como
externamente, mediante infinidad de tutoriales, guías y vídeos disponibles gratuitamente en internet.


Inicialización del repositorio de la práctica.
----------------------------------------------

Para cargar los ficheros en su ordenador personal debe seguir los pasos siguientes:

*	Abra una cuenta GitHub para gestionar esta y el resto de prácticas del curso.
*	Cree un repositorio GitHub con el contenido inicial de la práctica (sólo debe hacerlo uno de los
	integrantes del grupo de laboratorio, cuya página GitHub actuará de repositorio central):
	-	Acceda la página de la [Práctica 3](https://github.com/albino-pav/P2).
	-	En la parte superior derecha encontrará el botón **`Fork`**. Apriételo y, después de unos segundos,
		se creará en su cuenta GitHub un proyecto con el mismo nombre (**P2**). Si ya tuviera uno con ese 
		nombre, se utilizará el nombre **P2-1**, y así sucesivamente.
*	Habilite al resto de miembros del grupo como *colaboradores* del proyecto; de este modo, podrán
	subir sus modificaciones al repositorio central:
	-	En la página principal del repositorio, en la pestaña **:gear:`Settings`**, escoja la opción 
		**Collaborators** y añada a su compañero de prácticas.
	-	Éste recibirá un email solicitándole confirmación. Una vez confirmado, tanto él como el
		propietario podrán gestionar el repositorio, por ejemplo: crear ramas en él o subir las
		modificaciones de su directorio local de trabajo al repositorio GitHub.
*	En la página principal del repositorio, localice el botón **Branch: master** y úselo para crear
	una rama nueva con los primeros apellidos de los integrantes del equipo de prácticas separados por
	guion (**fulano-mengano**).
*	Todos los miembros del grupo deben realizar su copia local en su ordenador personal.
	-	Copie la dirección de su copia del repositorio apretando en el botón **Clone or download**.
		Asegúrese de usar *Clone with HTTPS*.
	-	Abra una sesión de Bash en su ordenador personal y vaya al directorio **PAV**. Desde ahí, ejecute:

		```.sh
		git clone dirección-del-fork-de-la-práctica
		```

	-	Vaya al directorio de la práctica `cd P2`.
	-	Cambie a la rama **fulano-mengano** con la orden:

		```.sh
		git checkout fulano-mengano
		```

*	A partir de este momento, todos los miembros del grupo de prácticas pueden trabajar en su directorio
	local del modo habitual.
	-	También puede utilizar el repositorio remoto como repositorio central para el trabajo colaborativo
		de los distintos miembros del grupo de prácticas; o puede serle útil usarlo como copia de seguridad.
	-	Cada vez que quiera subir sus cambios locales al repositorio GitHub deberá confirmar los
		cambios en su directorio local:

		```.sh
		git add .
		git commit -m "Mensaje del commit"
		```

		y, a continuación, subirlos con la orden:

		```.sh
		git push -u origin fulano-mengano
		```

*	Al final de la práctica, la rama **fulano-mengano** del repositorio GitHub servirá para remitir la
	práctica para su evaluación utilizando el mecanismo *pull request*.
	-	Vaya a la página principal de la copia del repositorio y asegúrese de estar en la rama
		**fulano-mengano**.
	-	Pulse en el botón **New pull request**, y siga las instrucciones de GitHub.


Entrega de la práctica.
-----------------------

Responda, en este mismo documento (README.md), los ejercicios indicados a continuación. Este documento es
un fichero de texto escrito con un formato denominado _**markdown**_. La principal característica de este
formato es que, manteniendo la legibilidad cuando se visualiza con herramientas en modo texto (`more`,
`less`, editores varios, ...), permite amplias posibilidades de visualización con formato en una amplia
gama de aplicaciones; muy notablemente, **GitHub**, **Doxygen** y **Facebook** (ciertamente, :eyes:).

En GitHub. cuando existe un fichero denominado README.md en el directorio raíz de un repositorio, se
interpreta y muestra al entrar en el repositorio.

Debe redactar las respuestas a los ejercicios usando Markdown. Puede encontrar información acerca de su
sintáxis en la página web [Sintaxis de Markdown](https://daringfireball.net/projects/markdown/syntax).
También puede consultar el documento adjunto [MARKDOWN.md](MARKDOWN.md), en el que se enumeran los elementos
más relevantes para completar la redacción de esta práctica.

Recuerde realizar el *pull request* una vez completada la práctica.

Ejercicios
----------

### Etiquetado manual de los segmentos de voz y silencio

- Etiquete manualmente los segmentos de voz y silencio del fichero grabado al efecto. Inserte, a 
  continuación, una captura de `wavesurfer` en la que se vea con claridad la señal temporal, el contorno de
  potencia y la tasa de cruces por cero, junto con el etiquetado manual de los segmentos.

#### ***Preparación de ficheros***

Lo primero que hay que hacer para poder calcular la precisión de un detector de voz, es generar nosotros un fichero de etiqutas etiquetas, donde determinemos claramente donde hay voz y donde no. Este fichero de etiquetas lo compararemos con el fichero de etiquetas generado por nuestro programa.

Así, generamos una señal de audio y con audacity aplicamos las etiquetas correspondientes

<img src="img/audio+etiquetas.png" width="640" align="center">

A continuación adjuntamos una captura de los valores de nuestras etiquetas:

<img src="img/numetiq.png" width="640" align="center">

Además nuestros contorno de potencia y tasa de cruces por cero son los siguientes:

<img src="img/analisisfrec.png" width="640" align="center">


FALTA CRUCES!!!

Con el código que nos viene ya implementado (que etiqueta de forma aleatoria) generamos aleatoriamente un fichero de etiquetas .lab que podremos observar con audacity

NO SE HACERLO EN AUDACITY!!

//FOTO DE AUDACITY AUDIO Y ETIQUETA + ETIQUETA GENERADA POR EL PROGRAMA QUE ESTÁ SUBIDA AL DRIVE .LAB

COMPARAR LAS DOS FOTOS!!!

- A la vista de la gráfica, indique qué valores considera adecuados para las magnitudes siguientes:

FALTA GRAFICA!!!

	* Incremento del nivel potencia en dB, respecto al nivel correspondiente al silencio inicial, para estar
      seguros de que un segmento de señal se corresponde con voz.

	* Duración mínima razonable de los segmentos de voz y silencio.

	* ¿Es capaz de sacar alguna conclusión a partir de la evolución de la tasa de cruces por cero?

A continuación adjuntamos las potencias del audio, para poder ver las diferencias:

Potencia de silencio

<img src="img/silencio.png" width="640" align="center">

Potencia de voz (concretamente a)

<img src="img/a.png" width="640" align="center">

Como podemos observar. la media del silencio es de unos -72dB, mientras que en el segmento con habla tenemos unos -57dB. Por lo tanto, tenemos una diferencia de alrededor de 20dB.

### Desarrollo del detector de actividad vocal

- Complete el código de los ficheros de la práctica para implementar un detector de actividad vocal tan
  exacto como sea posible. Tome como objetivo la maximización de la puntuación-F `TOTAL`.
  
#### ***Estructura***

El programa que implementaremos se basará en una máquina de estados, con los siguientes estados: silence, voice, maybe silence, maybe voice. Para definir en qué estado nos encontramos y cual pasamos, nos fijamos en la potencia y en unos umbrales (k0,k1,k2) que nosotros nos definimos. El nivel k0 será el nivel de silencio, por debajo de este umbral seguro que hay silencio, el nivel k2 será el nivel de voz, por encima de este seguro que hay voz. Entre estos y k1 se encuentran los estados intermedios: maybe voice y maybe silence. Estos dos últimos los utilizamos para no confundir silencios de los propios fonemas (que algunos los presentan) con silencios reales y al contrario, no detectar voz con picos de silencio. En estos dos estados sólo si nos mantenemos en ellos cierto tiempo, pasaremos a los estados silence y voice.

#### ***Niveles de referencia (k0, k1, k2)***

Para empezar, no adaptamos el umbral de decisión a los niveles de la señal, pues estos pueden cambiar según la señal que tengamos. Por eso, para determinar el k0 cogeremos unas cuantas muestras del inicio de la señal (que sabemos que será silencio) y medimos la potencia del ruido, y con eso, determinamos el k0. A partir de k0 calculamos k1 y k2 con unas ciertas constantes alfa.

<img src="img/codigo2.jpeg" width="640" align="center">
<img src="img/codigo1.jpeg" width="640" align="center">

#### ***Diagrama de estados del detector***

Empezamos definiendo las siguientes constantes, que nos ayudarán a decidir cuando o cuando no cambiar de un estado a otro, además de los umbrales de decisión.

Empezamos definiendo las anteriores constantes, que nos ayudarán a decidir cuando o cuando no cambiar de un estado a otro, además de los umbrales de decisión.

Y en función de estos umbrales, nos montaremos nuestro diagrama de estados:

- Si nos encontramos en silencio, si la potencia de la señal pasa el umbral k1 nos dirigiremos a maybe_voice.

- Si nos encontramos en voz, si la potencia de la señal baja del umbral k2 nos dirigiremos a maybe_silence.

- Si nos encontramos en maybe_voice o maybe_silence, si la potencia de la señal supera el umbral k2 nos dirigiremos a voice y si  baja del k1 nos iremos a silence.

Todo esto está implementado en la función vad.c

#### ***Generando los ficheros .vad***

Una vez tenemos los estados, ahora es necesario que el programa nos etiquete automáticamente cuando tenemos silencio y cuando no, para poder compararlo con el resto de etiquetas. Nuestro programa etiquetará todos los ficheros de años anteriores y comparará resultados, para obtener un f-score.

Para ello será necesario hacer un código que determine cuando o cuando no, escribir en el fichero .vad. Todo esto se hará en el main_vad.c Nuestra solución es sencilla y no es ni mucho menos la más óptima, pero consideramos, que dentro de nuestras capacidades y valorando el tiempo invertido en la realización de esta práctica, es la que debemos entregar.

Lo que nosotros queríamos implementar era un sistema que pudiera corregir situaciones como esta: 

<img src="img/codigo4.jpeg" width="640" align="center">

Y que los estados UNDEFINED maybe voice y maybe silence en lugar de printarse como tal, se printaran como el siguiente estado. Intentamos una versión pero funcionaba estrepitosamente, así que en nuestra última versión, decidimos que estos estados UNDEF serán printados como el estado anterior.

Todo esto está implementado en main_vad.c

#### ***Resultados***

Después de compilar y ejecutar los ficheros oportunos, obtenemos los resultados.

<img src="img/codigo3.jpeg" width="640" align="center">


- Inserte una gráfica en la que se vea con claridad la señal temporal, el etiquetado manual y la detección
  automática conseguida para el fichero grabado al efecto. 

- Explique, si existen. las discrepancias entre el etiquetado manual y la detección automática.

- Evalúe los resultados sobre la base de datos `db.v4` con el script `vad_evaluation.pl` e inserte a 
  continuación las tasas de sensibilidad (*recall*) y precisión para el conjunto de la base de datos (sólo
  el resumen).


### Trabajos de ampliación

#### Cancelación del ruido en los segmentos de silencio

- Si ha desarrollado el algoritmo para la cancelación de los segmentos de silencio, inserte una gráfica en
  la que se vea con claridad la señal antes y después de la cancelación (puede que `wavesurfer` no sea la
  mejor opción para esto, ya que no es capaz de visualizar varias señales al mismo tiempo).

#### Gestión de las opciones del programa usando `docopt_c`

- Si ha usado `docopt_c` para realizar la gestión de las opciones y argumentos del programa `vad`, inserte
  una captura de pantalla en la que se vea el mensaje de ayuda del programa.


### Contribuciones adicionales y/o comentarios acerca de la práctica

- Indique a continuación si ha realizado algún tipo de aportación suplementaria (algoritmos de detección o 
  parámetros alternativos, etc.).

- Si lo desea, puede realizar también algún comentario acerca de la realización de la práctica que considere
  de interés de cara a su evaluación.


### Antes de entregar la práctica

Recuerde comprobar que el repositorio cuenta con los códigos correctos y en condiciones de ser 
correctamente compilados con la orden `meson bin; ninja -C bin`. El programa generado (`bin/vad`) será
el usado, sin más opciones, para realizar la evaluación *ciega* del sistema.

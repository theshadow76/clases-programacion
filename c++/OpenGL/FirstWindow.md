## Vamos a crear nuestra primera ventana en OpenGL!
en este tutorial vamos a crear una ventana en OpenGL con el lenguage c++. Pero antes de empezar, quien soy?
Hola me llamo Vigo Walker en el momento de escribir esto, estoy aprendiendo lo mas que pueda de c++ y haciendo tutoriales en <a href="https://github.com">github</a>
para mejorar mas!

ahora empezamos.


## Importar las librarias
de primero tenemos que importar las siguientes libraries:

<code>
  #include <iostream>
  #include "glad.h"
  #include <GLFW/glfw3.h>
 </code>
  
  el <code>#include <iostream></code> es la libraria normal para prender cualquier programa de <strong>c++</strong>
  el <code>#include "glad.h" y el #include <GLFW/glw3.h></code> son las librerias que usamos en OpenGL en C++. 
  pero te estaras darando cuenta que el <strong>glad.h</strong> esta entre comillas, eso es porque es un archivo local, glad nose instala como otras librarias por ejemplo GLFW. Con GLFW es donde toda la parte grafica pasa, es lo que usas para iniciar todo y programar tus graficos.
  
  ## iniciar GLFW
  para prender GLFW vamos a usar <code>glfwInit();</code>, es muy importante iniciar estas cosas, por ejemplo una ves me paso que no encontraba el error
  de una inteligencia artificial asta que me di cuenta que nunca la inicie.
  
  ## iniciar y detectar version de OpenGL
  en momento de escribir esto, yo estoy usando OpenGL v3.3, en el cual le tengo que decir a GLFW cual es mi version de OpenGL.
  para eso usamos:
  ```cpp
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  ```
  
  ## Crear la ventana
  para crear la ventana vamos a necesitar este codigo:
  ```cpp
    GLFWwindow* window = glfwCreateWindow(800, 800, "TestScreen", NULL, NULL);
  ```
  esto va a dlecarar la variable <strong>window</strong> y le va a dar el valor de la ventana, primero tienes que decir que quieres de resolucion, le vamos a dar 800 de x y 800 de y. 
  despues, vas a decir que titulo quieres, en este caso sera TestSceen.
  despues, vas a decir si quieres que la pantalla se completa, en este caso vamos a decir que no con NULL.
  
  ## detectar problemas al abrir la ventana
  algo muy importante que hacer cuando trabajas con UI's es error handling, no es lo mejor que se te crashee el pc por no haber puesto error handling.
  entonces para eso vamos a poner el siguente codigo:
  ```cpp
    if (!window) {
        cout << "Window started with problems" << endl;
        glfwTerminate();
        return -1;
    }
  ```
  eso va a ver si tiene error y returnear un codigo de error -1 para que el compilador apage el programa altiro
  
  ## ploteando la ventana
  GLFW no es inteligente en saber que quieres con la ventana, entonces le tenemos que decir que hacer.
  para eso, vamos a usar el codigo siguiente:
  ```cpp
    glfwMakeContextCurrent(window);
  ```
  y en este caso window es nuestra variable que contiene los datos de la ventana.
  
  ## cerrar la ventana
  en un programa con UI tienes que darle la posibilidad de cerrar el programa, por que osino no lo vas a poder cerrar y eso no es bueno.
  entonces para eso ponemos el codigo siguiente:
  ```cpp
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }
  ```
  esto significa que el programa va a correr asta que haya un evento de cerrar la ventana.
  
  ## terminar el proceso
  ahora que ya iniciamos la ventana, tenemos que terminar todo, para eso vamos a necesitar el codigo siguiente:
  ```cpp
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
  ```
  primero tenemos que destruir la ventana, despues terminar el proceso y porfin decirle al compilador de terminar.
  
  muchas gracias por seguir este tutorial!
  sigueme en: <a href="https://www.instagram.com/vigo_walker/">instagram</a>

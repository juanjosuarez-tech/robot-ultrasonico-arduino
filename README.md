# 🤖 Robot ultrasónico con Arduino 

Código fuente y documentación de un **robot ultrasónico construido con Arduino**, diseñado para detectar y esquivar obstáculos automáticamente.  

### Descripción  
Este proyecto utiliza un sensor ultrasónico para medir distancias y controlar el movimiento de un robot 2WD. El Arduino Uno procesa la información y envía comandos a los motores a través del driver L298N, mientras que un servomotor ayuda a ajustar la posición del sensor ultrasónico para una mejor detección de obstáculos.  

###  Componentes principales  
- Arduino Uno  
- Driver de motores L298N  
- Servomotor  
- Motores DC con caja reductora  
- Sensor ultrasónico (HC-SR04)  
- Portapilas + batería de 9V con conector jack para alimentar el Arduino  
- Jumpers macho-hembra y macho-macho  
- 2 llantas normales y 1 llanta loca  
- Chasis 2WD o una base para montar todos los componentes  

### 📂 Contenido
- source-code.ino → Código fuente para Arduino IDE
- README.md → Descripción general del proyecto
- image-robot.jpg → Imagen del resultado final

###  ¿Cómo usar?
1. Ensambla todos los componentes como se muestra en el diagrama de conexión.  
2. Carga el código fuente en tu Arduino Uno usando Arduino IDE.  
3. Alimenta el sistema con el portapilas y la batería.  
4. Coloca el robot en el suelo y observa cómo esquiva los obstáculos.  

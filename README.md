 Seguidor de Línea V1.0

## Descripción General
 Se trata de un robot automático de una única placa cuyo propósito es seguir una línea (usualmente negra sobre un fondo blanco) utilizando sensores.  
 Es mayormente utilizado para la enseñanza de pid en instituciones y competir regionalmente.
[![](Bloques)](https://imgur.com/HsKrPqC)
---

## Diagrama de Bloques

---

##  Esquemático
En este esquemático se muestran las secciones del robot con sus debidos componentes y especificaciones.  
![Esquemático](images/esquematico.png)

---

##  Etapas Funcionales

### Etapa 1: Fuente de Alimentación
Fuente de alimentación que provee energía a todo el robot.  
Incluye un interruptor de palanca para alternar entre encendido y apagado.  
**Componentes:**  
- Bornera de dos entradas  
- Palanca de Arduino  

---

### Etapa 2: LED de Encendido
Indica cuándo el robot está encendido.  
**Componentes:**  
- Diodo LED  
- Resistencia 1kΩ  

---

### Etapa 3: Regulador de Tensión
Regula el voltaje que utiliza el circuito.  
**Componentes:**  
- L7805  
- 3 capacitores cerámicos 104  
- 1 capacitor electrolítico 16V x 100µF  

---

### Etapa 4: Driver de Motores
Driver **TB6612FNG** encargado de controlar la dirección de los motores.  
**Componentes:**  
- TB6612FNG  
- 2 capacitores cerámicos 105  
- 2 borneras de doble entrada  

---

### Etapa 5: Arduino Nano
Se encarga de almacenar el código del robot y enviar órdenes.  
**Componentes:**  
- Arduino Nano  

---

### Etapa 6: Sensores Infrarrojos
Detectan la línea que debe seguir el robot.  
**Componentes:**  
- Sensores foto-reflectivos QTR-8A  

---

## PCB
El seguidor de línea se conforma de una única placa:  
- **Tamaño:** 126 mm x 104,5 mm  
- **Pistas de cobre:** 0,7 mm y 1 mm en la capa B.Cu  

### Top View
![Top View](images/pcb_top.png)

### Gerber View
![Gerber View](images/pcb_gerber.png)

---

## Reparación de Problemas
Diagrama de flujo para la resolución de posibles problemas del robot:  
![Diagrama de Problemas](images/flow_problemas.png)

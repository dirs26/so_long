# 🕹️ so_long

**so_long** es un pequeño juego en 2D desarrollado en C como parte del currículo de la escuela 42. El objetivo del juego es mover un personaje a través de un mapa, recolectar todos los objetos y alcanzar la salida. ¡Cuidado con quedarte atrapado o no recogerlo todo!

<p align="center">
  <img src="https://img.shields.io/badge/42%20Project-So_Long-blue?style=flat-square" alt="42 Project">
  <img src="https://img.shields.io/badge/Language-C-informational?style=flat-square&logo=c">
  <img src="https://img.shields.io/badge/Graphics-MiniLibX-green?style=flat-square">
</p>

---

## 🎮 Gameplay

- El jugador se mueve con las teclas `W`, `A`, `S`, `D`.
- Debes recoger todos los coleccionables (C) antes de poder acceder a la salida (E).
- El mapa debe tener al menos un jugador (P), una salida (E) y un coleccionable (C).
- Los mapas son leídos desde archivos con extensión `.ber`.

---

## 📦 Estructura del proyecto
so_long/
├── assets/ # Sprites del juego
├── maps/ # Mapas de ejemplo en formato .ber
├── srcs/ # Código fuente principal
├── includes/ # Headers
├── Makefile # Compilación del proyecto
├── so_long.c # Punto de entrada
└── README.md # Este archivo

---

## Compila el proyecto con
make
- Asegúrate de tener la MiniLibX y las dependencias instaladas correctamente en tu entorno de 42.

## 🗺️ Ejecución
./so_long maps/map1.ber

- Puedes crear tus propios mapas siguiendo estas reglas:
- El mapa debe ser rectangular.
- Debe estar rodeado completamente por paredes (1).
- Debe tener exactamente:
- 1 jugador (P)
- Al menos 1 coleccionable (C)
- 1 salida (E)


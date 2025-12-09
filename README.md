# Sistema de Gestión Electoral en C++

## Descripción
Sistema para procesar datos electorales del SERVEL, desarrollado como parte del curso de Estructuras de Datos.

## Características
- Lectura de archivos CSV con datos de electores.
- Gestión de información mediante objetos y vectores.
- Consultas por RUT, comuna y estadísticas electorales.
- Implementación de clases:
  - Elector
  - Fecha
  - Direccion

## Funcionalidades
- Cantidad total de electores.
- Electores habilitados y vocales de mesa.
- Electores por comuna (ordenados alfabéticamente).
- Consulta de información por RUT.
- Votantes habilitados por comuna.
- Listado de vocales de mesa.

## Tecnologías
- C++
- Programación Orientada a Objetos
- Manejo de archivos
- Vectores y algoritmos de ordenamiento

## Instalación y Ejecución

### Compilar
\`\`\`bash
g++ -o programa main.cpp Direccion.cpp Elector.cpp Fecha.cpp
\`\`\`

### Ejecutar
\`\`\`bash
./programa.exe     # Windows
./programa         # Linux/macOS
\`\`\`

## Estructura del Proyecto
\`\`\`
TALLER1_EDD/
├── main.cpp
├── Elector.h/cpp
├── Fecha.h/cpp
├── Direccion.h/cpp
├── servel.txt
└── README.md
\`\`\`

## Autor
Constanza Olivos Fernández  
Estructuras de Datos - 2022

## Notas
Proyecto académico desarrollado para el curso de Estructuras de Datos.

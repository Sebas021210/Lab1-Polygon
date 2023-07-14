#include <iostream>
#include "Color.h"
#include "Framebuffer.h"
#include "Point.h"
#include "Linea.h"
#include "Poligono.h"
#include "Relleno.h"

void render() {
    Framebuffer framebuffer(800, 600, Color(0, 0, 0)); // Crear instancia de Framebuffer con ancho, alto y color de borrado
    framebuffer.setCurrentColor(Color(255, 255, 255)); // Establecer color actual para los puntos y líneas

<<<<<<< HEAD
=======
    // Polígono 1
    Point::Vertex2 vertices1[] = {
            {165, 380},
            {185, 360},
            {180, 330},
            {207, 345},
            {233, 330},
            {230, 360},
            {250, 380},
            {220, 385},
            {205, 410},
            {193, 383}
    };

    framebuffer.setCurrentColor(Color(255, 255, 255)); // Establecer color blanco para la orilla
    Poligono::drawPoligono(vertices1, sizeof(vertices1) / sizeof(vertices1[0]), framebuffer);

    framebuffer.setCurrentColor(Color(255, 255, 0)); // Establecer color amarillo para el relleno del polígono
    Relleno::fillPolygon(vertices1, sizeof(vertices1) / sizeof(vertices1[0]), framebuffer);


>>>>>>> Poligon-1
    framebuffer.renderBuffer(); // Generar el archivo BMP
}

int main() {
    render();

    return 0;
}

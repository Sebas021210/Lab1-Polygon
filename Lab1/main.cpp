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

    // Polígono 2
    Point::Vertex2 vertices2[] = {
            {321, 335},
            {288, 286},
            {339, 251},
            {374, 302}
    };

    framebuffer.setCurrentColor(Color(255, 255, 255)); // Establecer color blanco para la orilla
    Poligono::drawPoligono(vertices2, sizeof(vertices2) / sizeof(vertices2[0]), framebuffer);

    framebuffer.setCurrentColor(Color(0, 0, 255)); // Establecer color azul para el relleno del polígono
    Relleno::fillPolygon(vertices2, sizeof(vertices2) / sizeof(vertices2[0]), framebuffer);

    framebuffer.renderBuffer(); // Generar el archivo BMP
}

int main() {
    render();

    return 0;
}

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

    // Polígono 3
    Point::Vertex2 vertices3[] = {
            {377, 249},
            {411, 197},
            {436, 249}
    };

    framebuffer.setCurrentColor(Color(255, 255, 255)); // Establecer color blanco para la orilla
    Poligono::drawPoligono(vertices3, sizeof(vertices3) / sizeof(vertices3[0]), framebuffer);

    framebuffer.setCurrentColor(Color(255, 0, 0)); // Establecer color rojo para el relleno del polígono
    Relleno::fillPolygon(vertices3, sizeof(vertices3) / sizeof(vertices3[0]), framebuffer);

    framebuffer.renderBuffer(); // Generar el archivo BMP
}

int main() {
    render();

    return 0;
}

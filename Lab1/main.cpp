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

    // Polígono 4
    Point::Vertex2 vertices4[] = {
            {413, 177},
            {448, 159},
            {502, 88},
            {553, 53},
            {535, 36},
            {676, 37},
            {660, 52},
            {750, 145},
            {761, 179},
            {672, 192},
            {659, 214},
            {615, 214},
            {632, 230},
            {580, 230},
            {597, 215},
            {552, 214},
            {517, 144},
            {466, 180}
    };

    framebuffer.setCurrentColor(Color(255, 255, 255)); // Establecer color blanco para la orilla
    Poligono::drawPoligono(vertices4, sizeof(vertices4) / sizeof(vertices4[0]), framebuffer);

    framebuffer.setCurrentColor(Color(0, 255, 0)); // Establecer color verde para el relleno del polígono
    Relleno::fillPolygon(vertices4, sizeof(vertices4) / sizeof(vertices4[0]), framebuffer);

    // Polígono 5
    Point::Vertex2 vertices5[] = {
            {682, 175},
            {708, 120},
            {735, 148},
            {739, 170}
    };

    framebuffer.setCurrentColor(Color(255, 255, 255)); // Establecer color blanco para la orilla
    Poligono::drawPoligono(vertices5, sizeof(vertices5) / sizeof(vertices5[0]), framebuffer);

    framebuffer.setCurrentColor(Color(0, 0, 0)); // Establecer color negro para el relleno del polígono
    Relleno::fillPolygon(vertices5, sizeof(vertices5) / sizeof(vertices5[0]), framebuffer);

    framebuffer.renderBuffer(); // Generar el archivo BMP
}

int main() {
    render();

    return 0;
}

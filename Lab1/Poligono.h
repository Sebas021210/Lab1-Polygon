#pragma once
#include "Framebuffer.h"
#include "Point.h"
#include "Linea.h"

class Poligono {
public:
    static void drawPoligono(const Point::Vertex2* puntos, int numPuntos, Framebuffer& framebuffer) {
        if (numPuntos < 2) {
            return; // No se puede dibujar un polígono con menos de 2 puntos
        }

        for (int i = 0; i < numPuntos - 1; ++i) {
            Linea::linea(puntos[i], puntos[i + 1], framebuffer);
        }

        Linea::linea(puntos[numPuntos - 1], puntos[0], framebuffer);
    }
};

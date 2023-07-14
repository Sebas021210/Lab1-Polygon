#pragma once
#include "Point.h"
#include "Framebuffer.h"

class Relleno {
public:
    static void fillPolygon(const Point::Vertex2* vertices, int numVertices, Framebuffer& framebuffer) {
        if (numVertices < 3) {
            return; // No se puede rellenar un polígono con menos de 3 vértices
        }

        // Encontrar los límites horizontales del polígono
        int minX = vertices[0].x;
        int maxX = vertices[0].x;
        for (int i = 1; i < numVertices; ++i) {
            if (vertices[i].x < minX) {
                minX = vertices[i].x;
            }
            if (vertices[i].x > maxX) {
                maxX = vertices[i].x;
            }
        }

        // Escanear cada línea horizontal y verificar si está dentro del polígono
        for (int y = 0; y < framebuffer.getHeight(); ++y) {
            bool insidePolygon = false;
            for (int i = 0, j = numVertices - 1; i < numVertices; j = i++) {
                if ((vertices[i].y > y) != (vertices[j].y > y) &&
                    (y - vertices[i].y) * (vertices[j].x - vertices[i].x) < (vertices[j].y - vertices[i].y) * (minX - vertices[i].x)) {
                    insidePolygon = !insidePolygon;
                }
            }

            // Si la línea horizontal está dentro del polígono, dibujar los puntos correspondientes
            if (insidePolygon) {
                for (int x = minX; x <= maxX; ++x) {
                    framebuffer.point(Point::Vertex2{x, y});
                }
            }
        }
    }
};

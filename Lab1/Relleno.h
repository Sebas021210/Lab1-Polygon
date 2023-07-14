#pragma once
#include "Point.h"
#include "Framebuffer.h"

class Relleno {
public:
    static void fillPolygon(const Point::Vertex2* vertices, int numVertices, Framebuffer& framebuffer) {
        if (numVertices < 3) {
            return; // No se puede rellenar un polígono con menos de 3 vértices
        }

        // Encontrar los límites verticales del polígono
        int minY = vertices[0].y;
        int maxY = vertices[0].y;
        for (int i = 1; i < numVertices; ++i) {
            if (vertices[i].y < minY) {
                minY = vertices[i].y;
            }
            if (vertices[i].y > maxY) {
                maxY = vertices[i].y;
            }
        }

        // Escanear cada línea horizontal y verificar si está dentro del polígono
        for (int y = minY; y <= maxY; ++y) {
            // Encontrar los puntos de intersección con los lados del polígono
            std::vector<int> intersections;
            for (int i = 0, j = numVertices - 1; i < numVertices; j = i++) {
                int x1 = vertices[i].x;
                int y1 = vertices[i].y;
                int x2 = vertices[j].x;
                int y2 = vertices[j].y;

                if ((y1 <= y && y2 > y) || (y1 > y && y2 <= y)) {
                    int intersection = static_cast<int>(x1 + (static_cast<double>(y - y1) / (y2 - y1)) * (x2 - x1));
                    intersections.push_back(intersection);
                }
            }

            // Ordenar las intersecciones de izquierda a derecha
            std::sort(intersections.begin(), intersections.end());

            // Rellenar los píxeles entre las intersecciones
            for (size_t i = 0; i < intersections.size(); i += 2) {
                int startX = intersections[i];
                int endX = intersections[i + 1];

                // Dibujar los puntos entre las intersecciones
                for (int x = startX; x <= endX; ++x) {
                    framebuffer.point(Point::Vertex2{x, y});
                }
            }
        }
    }
};

#pragma once
#include "Point.h"

class Linea {
public:
    static void linea(const Point::Vertex2& inicio, const Point::Vertex2& fin, Framebuffer& framebuffer) {
        int x0 = inicio.x;
        int y0 = inicio.y;
        int x1 = fin.x;
        int y1 = fin.y;

        int dx = std::abs(x1 - x0);
        int dy = std::abs(y1 - y0);
        int sx = (x0 < x1) ? 1 : -1;
        int sy = (y0 < y1) ? 1 : -1;
        int err = dx - dy;

        while (true) {
            framebuffer.point(Point::Vertex2{ x0, y0 });

            if (x0 == x1 && y0 == y1) {
                break;
            }

            int err2 = 2 * err;

            if (err2 > -dy) {
                err -= dy;
                x0 += sx;
            }

            if (err2 < dx) {
                err += dx;
                y0 += sy;
            }
        }
    }
};

#pragma once
#include <vector>
#include <fstream>
#include "Color.h"
#include "Point.h"

class Framebuffer {
public:
    Framebuffer(int width, int height, const Color& clearColor);
    void clear();
    void setCurrentColor(const Color& color);
    void point(const Point::Vertex2& vertex);
    void renderBuffer();

    int getHeight() const {
        return height;
    }

private:
    std::vector<Color> framebuffer;
    Color clearColor;
    Color currentColor;
    int width;
    int height;
};

Framebuffer::Framebuffer(int width, int height, const Color& clearColor)
        : width(width), height(height), clearColor(clearColor) {
    framebuffer.resize(width * height);
}

void Framebuffer::clear() {
    for (int i = 0; i < width * height; ++i) {
        framebuffer[i] = clearColor;
    }
}

void Framebuffer::setCurrentColor(const Color& color) {
    currentColor = color;
}

void Framebuffer::point(const Point::Vertex2& vertex) {
    int x = vertex.x;
    int y = vertex.y;
    if (x >= 0 && x < width && y >= 0 && y < height) {
        int index = y * width + x;
        framebuffer[index] = currentColor;
    }
}

void Framebuffer::renderBuffer() {
    std::ofstream file("out.bmp", std::ios::binary);
    if (!file) {
        std::cerr << "Error al abrir el archivo." << std::endl;
        return;
    }

    // Encabezado del archivo BMP
    const int fileSize = 54 + (width * height * 3); // Tamaño total del archivo BMP
    const int dataOffset = 54; // Desplazamiento de los datos de píxeles

    char bmpFileHeader[14] = {
            'B', 'M',                                      // Tipo de archivo BMP
            static_cast<char>(fileSize), static_cast<char>(fileSize >> 8), static_cast<char>(fileSize >> 16), static_cast<char>(fileSize >> 24),  // Tamaño del archivo
            0, 0, 0, 0,                                    // Reservado
            static_cast<char>(dataOffset), static_cast<char>(dataOffset >> 8), static_cast<char>(dataOffset >> 16), static_cast<char>(dataOffset >> 24) // Desplazamiento de los datos de píxeles
    };

    char bmpInfoHeader[40] = {
            40, 0, 0, 0,                                   // Tamaño de la información del archivo
            static_cast<char>(width), static_cast<char>(width >> 8), static_cast<char>(width >> 16), static_cast<char>(width >> 24),  // Ancho
            static_cast<char>(height), static_cast<char>(height >> 8), static_cast<char>(height >> 16), static_cast<char>(height >> 24),  // Alto
            1, 0,                                          // Planos
            24, 0,                                         // Bits por píxel (RGB de 24 bits)
            0, 0, 0, 0,                                    // Compresión (sin comprimir)
            0, 0, 0, 0,                                    // Tamaño de los datos de píxeles
            0, 0, 0, 0,                                    // Resolución horizontal
            0, 0, 0, 0,                                    // Resolución vertical
            0, 0, 0, 0,                                    // Colores en la paleta
            0, 0, 0, 0                                     // Colores importantes
    };

    // Escribir los encabezados en el archivo BMP
    file.write(bmpFileHeader, 14);
    file.write(bmpInfoHeader, 40);

    // Escribir los píxeles en el archivo BMP
    for (int y = height - 1; y >= 0; --y) {
        for (int x = 0; x < width; ++x) {
            int index = y * width + x;
            Color pixelColor = framebuffer[index];
            char pixelData[3] = { static_cast<char>(pixelColor.getBlue()), static_cast<char>(pixelColor.getGreen()), static_cast<char>(pixelColor.getRed()) };
            file.write(pixelData, 3);
        }
    }

    file.close();
    std::cout << "Archivo BMP generado exitosamente." << std::endl;
}

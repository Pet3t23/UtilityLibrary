#pragma once
#include "MathEngine.h"

class Vector4 {
public:
    // Componentes del vector: x, y, z, w
    float x, y, z, w;

    /**
     * @brief Constructor por defecto.
     * Establece todas las componentes en cero.
     */
    Vector4() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) {}

    /**
     * @brief Constructor con parámetros especificados.
     * Permite inicializar el vector con valores definidos para cada componente.
     * @param x Valor para la componente x.
     * @param y Valor para la componente y.
     * @param z Valor para la componente z.
     * @param w Valor para la componente w.
     */
    Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

    /**
     * @brief Sobrecarga del operador de adición.
     * Realiza la suma componente a componente entre dos vectores.
     * @param other Vector a sumar.
     * @return Un nuevo vector resultante de la suma.
     */
    Vector4 operator+(const Vector4& other) const {
        return Vector4(this->x + other.x, this->y + other.y, this->z + other.z, this->w + other.w);
    }

    /**
     * @brief Sobrecarga del operador de sustracción.
     * Resta las componentes de dos vectores.
     * @param other Vector a restar.
     * @return Un nuevo vector resultante de la resta.
     */
    Vector4 operator-(const Vector4& other) const {
        return Vector4(this->x - other.x, this->y - other.y, this->z - other.z, this->w - other.w);
    }

    /**
     * @brief Sobrecarga del operador de multiplicación por un escalar.
     * Escala cada componente del vector por el valor proporcionado.
     * @param scalar El valor escalar por el cual se multiplican las componentes.
     * @return Un nuevo vector con las componentes escaladas.
     */
    Vector4 operator*(float scalar) const {
        return Vector4(this->x * scalar, this->y * scalar, this->z * scalar, this->w * scalar);
    }

    /**
     * @brief Calcula la magnitud (longitud) del vector.
     * La magnitud es la raíz cuadrada de la suma de los cuadrados de las componentes.
     * Utiliza la función sqrt del MathEngine para el cálculo.
     * @return La magnitud del vector.
     */
    float magnitude() const {
        return MathEngine::sqrt((x * x) + (y * y) + (z * z) + (w * w));
    }

    /**
     * @brief Normaliza el vector.
     * Retorna un vector con la misma dirección y una magnitud de uno.
     * Si la magnitud es cero, se retorna un vector nulo (0, 0, 0, 0).
     * @return El vector normalizado.
     */
    Vector4 normalize() const {
        float mag = magnitude();
        return (mag != 0.0f) ? Vector4(x / mag, y / mag, z / mag, w / mag) : Vector4(0.0f, 0.0f, 0.0f, 0.0f);
    }

    /**
     * @brief Devuelve un puntero no constante a los datos del vector.
     * @return Un puntero a la primera componente del vector.
     */
    float* data() {
        return &x;
    }

    /**
     * @brief Devuelve un puntero constante a los datos del vector.
     * @return Un puntero constante a la primera componente del vector.
     */
    const float* data() const {
        return &x;
    }
};

#pragma once
#include "MathEngine.h"

class Vector3 {
public:
    // Componentes del vector en los ejes x, y, z
    float x, y, z;

    /**
     * @brief Constructor por defecto.
     * Establece las coordenadas x, y, z en cero.
     */
    Vector3() : x(0.0f), y(0.0f), z(0.0f) {}

    /**
     * @brief Constructor con parámetros específicos.
     * Inicializa las componentes del vector con los valores proporcionados.
     * @param x Valor para la coordenada x.
     * @param y Valor para la coordenada y.
     * @param z Valor para la coordenada z.
     */
    Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

    /**
     * @brief Sobrecarga del operador de suma.
     * Realiza la suma de dos vectores componente por componente.
     * @param other El vector que se suma.
     * @return Un nuevo vector que representa la suma.
     */
    Vector3 operator+(const Vector3& other) const {
        return Vector3(this->x + other.x, this->y + other.y, this->z + other.z);
    }

    /**
     * @brief Sobrecarga del operador de resta.
     * Resta las componentes de dos vectores.
     * @param other El vector que se resta.
     * @return Un nuevo vector con el resultado de la resta.
     */
    Vector3 operator-(const Vector3& other) const {
        return Vector3(this->x - other.x, this->y - other.y, this->z - other.z);
    }

    /**
     * @brief Sobrecarga del operador de multiplicación por un escalar.
     * Multiplica cada componente del vector por un escalar dado.
     * @param scalar El valor escalar por el cual se multiplican las componentes.
     * @return Un nuevo vector con las componentes escaladas.
     */
    Vector3 operator*(float scalar) const {
        return Vector3(this->x * scalar, this->y * scalar, this->z * scalar);
    }

    /**
     * @brief Calcula la longitud (magnitud) del vector.
     * La longitud se obtiene como la raíz cuadrada de la suma de los cuadrados de las componentes.
     * Utiliza la función sqrt definida en MathEngine.h.
     * @return La magnitud del vector.
     */
    float magnitude() const {
        return MathEngine::sqrt((x * x) + (y * y) + (z * z));
    }

    /**
     * @brief Normaliza el vector.
     * Devuelve un vector en la misma dirección, pero con longitud igual a uno.
     * Si la magnitud es cero, devuelve un vector nulo (0, 0, 0).
     * @return El vector normalizado.
     */
    Vector3 normalize() const {
        float mag = magnitude();
        return (mag != 0.0f) ? Vector3(x / mag, y / mag, z / mag) : Vector3(0.0f, 0.0f, 0.0f);
    }

    /**
     * @brief Obtiene un puntero a los datos.
     * @return Un puntero no constante al primer elemento del vector.
     */
    float* data() {
        return &x;
    }

    /**
     * @brief Obtiene un puntero constante a los datos.
     * @return Un puntero constante al primer elemento del vector.
     */
    const float* data() const {
        return &x;
    }
};

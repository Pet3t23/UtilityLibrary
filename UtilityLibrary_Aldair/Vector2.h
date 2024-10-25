#pragma once
#include "MathEngine.h"

class Vector2 {
public:
    // Componentes del vector en los ejes x e y
    float x;
    float y;

    /**
     * @brief Constructor por defecto.
     * Establece las coordenadas x e y en cero.
     */
    Vector2() : x(0.0f), y(0.0f) {}

    /**
     * @brief Constructor con parámetros.
     * Asigna los valores proporcionados a las componentes del vector.
     * @param xVal Valor para la componente x.
     * @param yVal Valor para la componente y.
     */
    Vector2(float xVal, float yVal) : x(xVal), y(yVal) {}

    /**
     * @brief Sobrecarga del operador de suma.
     * Realiza la suma componente por componente de dos vectores.
     * @param other El vector a sumar.
     * @return Un nuevo vector con la suma de las componentes.
     */
    Vector2 operator+(const Vector2& other) const {
        return Vector2(this->x + other.x, this->y + other.y);
    }

    /**
     * @brief Sobrecarga del operador de resta.
     * Calcula la diferencia componente por componente de dos vectores.
     * @param other El vector a restar.
     * @return Un nuevo vector con las componentes resultantes.
     */
    Vector2 operator-(const Vector2& other) const {
        return Vector2(this->x - other.x, this->y - other.y);
    }

    /**
     * @brief Sobrecarga del operador de multiplicación por un escalar.
     * Multiplica cada componente del vector por el escalar dado.
     * @param scalar El valor escalar por el cual se multiplican las componentes.
     * @return Un nuevo vector con las componentes multiplicadas.
     */
    Vector2 operator*(float scalar) const {
        return Vector2(this->x * scalar, this->y * scalar);
    }

    /**
     * @brief Calcula la longitud del vector.
     * La longitud se determina como la raíz cuadrada de la suma de los cuadrados de las componentes.
     * Utiliza la función sqrt de MathEngine.h.
     * @return La longitud del vector.
     */
    float magnitude() const {
        return Math_Engine::sqrt((x * x) + (y * y));
    }

    /**
     * @brief Normaliza el vector.
     * Devuelve un nuevo vector con la misma dirección, pero con longitud igual a uno.
     * Si el vector original tiene longitud cero, retorna (0, 0).
     * @return El vector normalizado.
     */
    Vector2 normalize() const {
        float mag = magnitude();
        return (mag != 0.0f) ? Vector2(x / mag, y / mag) : Vector2(0.0f, 0.0f);
    }

    /**
     * @brief Obtiene un puntero a los datos.
     * @return Un puntero no constante a la primera componente.
     */
    float* data() {
        return &x;
    }

    /**
     * @brief Obtiene un puntero constante a los datos.
     * @return Un puntero constante a la primera componente.
     */
    const float* data() const {
        return &x;
    }
};

#pragma once

namespace MathEngine {
    // Código proporcionado por "Roberto Charreton".
    // Constantes matemáticas
    constexpr float PI = 3.14159265358979323846f;
    constexpr float E = 2.71828182845904523536f;

    /**
     * @brief Calcula la raíz cuadrada utilizando el método de Newton-Raphson.
     * Este método iterativo se utiliza para aproximar la raíz cuadrada de un número dado.
     * @param value El número para el cual se calcula la raíz cuadrada.
     * @return La raíz cuadrada aproximada del valor proporcionado. Si el valor es negativo, retorna 0.
     */
    inline float sqrt(float value) {
        if (value < 0.0f) {
            return 0.0f;
        }
        float x = value;
        float y = 1.0f;
        const float epsilon = 0.00001f; // Tolerancia para el cálculo de precisión.
        while ((x - y) > epsilon) {
            x = 0.5f * (x + y);
            y = value / x;
        }
        return x;
    }

    /**
     * @brief Calcula el seno de un ángulo en radianes.
     * Utiliza la serie de Taylor para aproximar el seno.
     * @param angle Ángulo en radianes.
     * @return El seno del ángulo especificado.
     */
    inline float sin(float angle) {
        float result = 0.0f;
        float term = angle;
        const float angle_squared = angle * angle;
        int n = 1;
        // Itera hasta que el término sea suficientemente pequeño
        while (term > 1e-6f || term < -1e-6f) {
            result += term;
            term *= -angle_squared / ((2 * n) * (2 * n + 1));
            ++n;
        }
        return result;
    }

    /**
     * @brief Calcula el coseno de un ángulo en radianes.
     * El coseno se calcula utilizando la relación entre seno y coseno.
     * @param angle Ángulo en radianes.
     * @return El coseno del ángulo dado.
     */
    inline float cos(float angle) {
        return sin(angle + (PI / 2.0f));
    }

    /**
     * @brief Calcula la tangente de un ángulo en radianes.
     * La tangente se define como el cociente del seno y el coseno.
     * @param angle Ángulo en radianes.
     * @return La tangente del ángulo, o 0 si el coseno es cero para evitar la división por cero.
     */
    inline float tan(float angle) {
        float sine = sin(angle);
        float cosine = cos(angle);
        return (cosine != 0.0f) ? (sine / cosine) : 0.0f;
    }
};

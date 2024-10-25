#pragma once

namespace MathEngine {
    // C�digo proporcionado por "Roberto Charreton".
    // Constantes matem�ticas
    constexpr float PI = 3.14159265358979323846f;
    constexpr float E = 2.71828182845904523536f;

    /**
     * @brief Calcula la ra�z cuadrada utilizando el m�todo de Newton-Raphson.
     * Este m�todo iterativo se utiliza para aproximar la ra�z cuadrada de un n�mero dado.
     * @param value El n�mero para el cual se calcula la ra�z cuadrada.
     * @return La ra�z cuadrada aproximada del valor proporcionado. Si el valor es negativo, retorna 0.
     */
    inline float sqrt(float value) {
        if (value < 0.0f) {
            return 0.0f;
        }
        float x = value;
        float y = 1.0f;
        const float epsilon = 0.00001f; // Tolerancia para el c�lculo de precisi�n.
        while ((x - y) > epsilon) {
            x = 0.5f * (x + y);
            y = value / x;
        }
        return x;
    }

    /**
     * @brief Calcula el seno de un �ngulo en radianes.
     * Utiliza la serie de Taylor para aproximar el seno.
     * @param angle �ngulo en radianes.
     * @return El seno del �ngulo especificado.
     */
    inline float sin(float angle) {
        float result = 0.0f;
        float term = angle;
        const float angle_squared = angle * angle;
        int n = 1;
        // Itera hasta que el t�rmino sea suficientemente peque�o
        while (term > 1e-6f || term < -1e-6f) {
            result += term;
            term *= -angle_squared / ((2 * n) * (2 * n + 1));
            ++n;
        }
        return result;
    }

    /**
     * @brief Calcula el coseno de un �ngulo en radianes.
     * El coseno se calcula utilizando la relaci�n entre seno y coseno.
     * @param angle �ngulo en radianes.
     * @return El coseno del �ngulo dado.
     */
    inline float cos(float angle) {
        return sin(angle + (PI / 2.0f));
    }

    /**
     * @brief Calcula la tangente de un �ngulo en radianes.
     * La tangente se define como el cociente del seno y el coseno.
     * @param angle �ngulo en radianes.
     * @return La tangente del �ngulo, o 0 si el coseno es cero para evitar la divisi�n por cero.
     */
    inline float tan(float angle) {
        float sine = sin(angle);
        float cosine = cos(angle);
        return (cosine != 0.0f) ? (sine / cosine) : 0.0f;
    }
};

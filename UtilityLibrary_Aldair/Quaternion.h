#pragma once
#include "MathEngine.h"
#include "Vector3.h"

class Quaternion {
public:
    // Componentes del cuaternión: w, x, y, z
    float w, x, y, z;

    /**
     * @brief Constructor por defecto.
     * Inicializa el cuaternión con valores cero para todas las componentes.
     */
    Quaternion() : w(0.0f), x(0.0f), y(0.0f), z(0.0f) {}

    /**
     * @brief Constructor parametrizado.
     * Permite establecer valores específicos para cada componente del cuaternión.
     * @param w Valor para la componente w.
     * @param x Valor para la componente x.
     * @param y Valor para la componente y.
     * @param z Valor para la componente z.
     */
    Quaternion(float w, float x, float y, float z) : w(w), x(x), y(y), z(z) {}

    /**
     * @brief Constructor para crear un cuaternión a partir de un ángulo y un eje.
     * Genera un cuaternión que representa una rotación 3D usando un ángulo en radianes y un eje de rotación.
     * @param angle Ángulo de rotación en radianes.
     * @param axis Eje alrededor del cual se realiza la rotación.
     */
    Quaternion(float angle, const Vector3& axis) {
        float halfAngle = angle * 0.5f;
        float sinHalf = MathEngine::sin(halfAngle);
        w = MathEngine::cos(halfAngle);
        x = axis.x * sinHalf;
        y = axis.y * sinHalf;
        z = axis.z * sinHalf;
    }

    /**
     * @brief Sobrecarga del operador de suma.
     * Realiza la suma de dos cuaterniones, componente por componente.
     * @param other El cuaternión a sumar.
     * @return El resultado de la suma.
     */
    Quaternion operator+(const Quaternion& other) const {
        return Quaternion(w + other.w, x + other.x, y + other.y, z + other.z);
    }

    /**
     * @brief Sobrecarga del operador de resta.
     * Resta los componentes de otro cuaternión a este cuaternión.
     * @param other El cuaternión a restar.
     * @return El resultado de la resta.
     */
    Quaternion operator-(const Quaternion& other) const {
        return Quaternion(w - other.w, x - other.x, y - other.y, z - other.z);
    }

    /**
     * @brief Sobrecarga del operador de multiplicación por escalar.
     * Multiplica cada componente del cuaternión por un valor escalar.
     * @param scalar El valor escalar.
     * @return El cuaternión resultante.
     */
    Quaternion operator*(float scalar) const {
        return Quaternion(w * scalar, x * scalar, y * scalar, z * scalar);
    }

    /**
     * @brief Sobrecarga del operador de multiplicación entre cuaterniones.
     * Realiza la multiplicación de dos cuaterniones, aplicando las reglas de la multiplicación cuaterniónica.
     * @param other El cuaternión a multiplicar.
     * @return El producto de los dos cuaterniones.
     */
    Quaternion operator*(const Quaternion& other) const {
        return Quaternion(
            w * other.w - x * other.x - y * other.y - z * other.z,
            w * other.x + x * other.w + y * other.z - z * other.y,
            w * other.y - x * other.z + y * other.w + z * other.x,
            w * other.z + x * other.y - y * other.x + z * other.w
        );
    }

    /**
     * @brief Calcula la longitud del cuaternión.
     * La longitud se determina como la raíz cuadrada de la suma de los cuadrados de los componentes.
     * @return La magnitud del cuaternión.
     */
    float magnitude() const {
        return MathEngine::sqrt(w * w + x * x + y * y + z * z);
    }

    /**
     * @brief Devuelve el cuaternión normalizado.
     * Si la longitud es cero, se retorna un cuaternión con todas sus componentes en cero.
     * @return El cuaternión normalizado.
     */
    Quaternion normalize() const {
        float mag = magnitude();
        return (mag != 0.0f) ? Quaternion(w / mag, x / mag, y / mag, z / mag) : Quaternion(0.0f, 0.0f, 0.0f, 0.0f);
    }

    /**
     * @brief Calcula el conjugado del cuaternión.
     * Invierte el signo de las partes vectoriales (x, y, z).
     * @return El conjugado del cuaternión.
     */
    Quaternion conjugate() const {
        return Quaternion(w, -x, -y, -z);
    }

    /**
     * @brief Calcula el inverso del cuaternión.
     * Devuelve el conjugado dividido por la magnitud al cuadrado.
     * @return El cuaternión inverso.
     */
    Quaternion inverse() const {
        float magSquared = w * w + x * x + y * y + z * z;
        return (magSquared != 0.0f) ? conjugate() * (1.0f / magSquared) : Quaternion(0.0f, 0.0f, 0.0f, 0.0f);
    }

    /**
     * @brief Rota un vector utilizando este cuaternión.
     * La rotación se aplica usando el cuaternión como rotación en el espacio tridimensional.
     * @param v El vector a rotar.
     * @return El vector rotado.
     */
    Vector3 rotate(const Vector3& v) const {
        Quaternion qv(0.0f, v.x, v.y, v.z);
        Quaternion result = (*this) * qv * this->inverse();
        return Vector3(result.x, result.y, result.z);
    }

    /**
     * @brief Devuelve un puntero a los datos del cuaternión (no constante).
     * @return Un puntero a la primera componente.
     */
    float* data() {
        return &w;
    }

    /**
     * @brief Devuelve un puntero a los datos del cuaternión (constante).
     * @return Un puntero constante a la primera componente.
     */
    const float* data() const {
        return &w;
    }
};

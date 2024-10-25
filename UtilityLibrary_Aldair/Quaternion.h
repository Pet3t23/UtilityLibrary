#pragma once
#include "MathEngine.h"
#include "Vector3.h"

class Quaternion {
public:
    // Componentes del cuaterni�n: w, x, y, z
    float w, x, y, z;

    /**
     * @brief Constructor por defecto.
     * Inicializa el cuaterni�n con valores cero para todas las componentes.
     */
    Quaternion() : w(0.0f), x(0.0f), y(0.0f), z(0.0f) {}

    /**
     * @brief Constructor parametrizado.
     * Permite establecer valores espec�ficos para cada componente del cuaterni�n.
     * @param w Valor para la componente w.
     * @param x Valor para la componente x.
     * @param y Valor para la componente y.
     * @param z Valor para la componente z.
     */
    Quaternion(float w, float x, float y, float z) : w(w), x(x), y(y), z(z) {}

    /**
     * @brief Constructor para crear un cuaterni�n a partir de un �ngulo y un eje.
     * Genera un cuaterni�n que representa una rotaci�n 3D usando un �ngulo en radianes y un eje de rotaci�n.
     * @param angle �ngulo de rotaci�n en radianes.
     * @param axis Eje alrededor del cual se realiza la rotaci�n.
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
     * @param other El cuaterni�n a sumar.
     * @return El resultado de la suma.
     */
    Quaternion operator+(const Quaternion& other) const {
        return Quaternion(w + other.w, x + other.x, y + other.y, z + other.z);
    }

    /**
     * @brief Sobrecarga del operador de resta.
     * Resta los componentes de otro cuaterni�n a este cuaterni�n.
     * @param other El cuaterni�n a restar.
     * @return El resultado de la resta.
     */
    Quaternion operator-(const Quaternion& other) const {
        return Quaternion(w - other.w, x - other.x, y - other.y, z - other.z);
    }

    /**
     * @brief Sobrecarga del operador de multiplicaci�n por escalar.
     * Multiplica cada componente del cuaterni�n por un valor escalar.
     * @param scalar El valor escalar.
     * @return El cuaterni�n resultante.
     */
    Quaternion operator*(float scalar) const {
        return Quaternion(w * scalar, x * scalar, y * scalar, z * scalar);
    }

    /**
     * @brief Sobrecarga del operador de multiplicaci�n entre cuaterniones.
     * Realiza la multiplicaci�n de dos cuaterniones, aplicando las reglas de la multiplicaci�n cuaterni�nica.
     * @param other El cuaterni�n a multiplicar.
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
     * @brief Calcula la longitud del cuaterni�n.
     * La longitud se determina como la ra�z cuadrada de la suma de los cuadrados de los componentes.
     * @return La magnitud del cuaterni�n.
     */
    float magnitude() const {
        return MathEngine::sqrt(w * w + x * x + y * y + z * z);
    }

    /**
     * @brief Devuelve el cuaterni�n normalizado.
     * Si la longitud es cero, se retorna un cuaterni�n con todas sus componentes en cero.
     * @return El cuaterni�n normalizado.
     */
    Quaternion normalize() const {
        float mag = magnitude();
        return (mag != 0.0f) ? Quaternion(w / mag, x / mag, y / mag, z / mag) : Quaternion(0.0f, 0.0f, 0.0f, 0.0f);
    }

    /**
     * @brief Calcula el conjugado del cuaterni�n.
     * Invierte el signo de las partes vectoriales (x, y, z).
     * @return El conjugado del cuaterni�n.
     */
    Quaternion conjugate() const {
        return Quaternion(w, -x, -y, -z);
    }

    /**
     * @brief Calcula el inverso del cuaterni�n.
     * Devuelve el conjugado dividido por la magnitud al cuadrado.
     * @return El cuaterni�n inverso.
     */
    Quaternion inverse() const {
        float magSquared = w * w + x * x + y * y + z * z;
        return (magSquared != 0.0f) ? conjugate() * (1.0f / magSquared) : Quaternion(0.0f, 0.0f, 0.0f, 0.0f);
    }

    /**
     * @brief Rota un vector utilizando este cuaterni�n.
     * La rotaci�n se aplica usando el cuaterni�n como rotaci�n en el espacio tridimensional.
     * @param v El vector a rotar.
     * @return El vector rotado.
     */
    Vector3 rotate(const Vector3& v) const {
        Quaternion qv(0.0f, v.x, v.y, v.z);
        Quaternion result = (*this) * qv * this->inverse();
        return Vector3(result.x, result.y, result.z);
    }

    /**
     * @brief Devuelve un puntero a los datos del cuaterni�n (no constante).
     * @return Un puntero a la primera componente.
     */
    float* data() {
        return &w;
    }

    /**
     * @brief Devuelve un puntero a los datos del cuaterni�n (constante).
     * @return Un puntero constante a la primera componente.
     */
    const float* data() const {
        return &w;
    }
};

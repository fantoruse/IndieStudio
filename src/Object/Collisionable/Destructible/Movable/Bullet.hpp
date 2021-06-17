/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include "MovableObject.hpp"

#ifndef INDIESTUDIO_BULLET_HPP
#define INDIESTUDIO_BULLET_HPP

/**
 * @class Bullet
 *
 * @brief Bullet to kill other player
 */
class Bullet: public MovableObject {
public:
    /**
     * @brief Construct a new Bullet object
     *
     * @param pos
     * @param size
     */
    Bullet(const coords &pos, float angle);

    /**
     * @brief once bullet was shot, it follows a vector and being updated by this
     * method
     *
     */
    void constant_move() noexcept;
    /**
     * @brief set a new dir
     *
     * @param direction
     */
    void move(const coords &direction) noexcept override;
    /**
     * @brief bounce when hit surface
     *
     */
    void bounce() noexcept;

    static const std::string modelPath;
    static const std::string texturePath;
private:
    coords _direction;
    coords _prevPos;
};

#endif //INDIESTUDIO_BULLET_HPP

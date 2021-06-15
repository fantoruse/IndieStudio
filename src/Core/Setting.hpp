/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** Settings
*/

#ifndef SETTINGS_HPP_
#define SETTINGS_HPP_

#include <string>
#include <array>
#include <cstddef>

struct Players {
    Players() : ai(true), name("BOT" + std::to_string(std::rand() % 10)) {}
    bool ai;
    std::string name;
};

/**
 * @class setting
 * @brief store game settings
 */
struct Setting {
    Setting(int widthScreen = 1920, int heightScreen = 1080, const std::size_t &fps = 60, float musicVol = 1.0f, float soundVol = 1.0f);
    // Setting(int widthScreen = 1920, int heightScreen = 1080, const std::size_t &fps = 60);
    Setting(const Setting &settings);
    std::array<Players, 4> _players;
    float _musicVol;
    float _soundVol;
    int _widthScreen;
    int _heightScreen;
    int _fps;
};

#endif /* !SETTINGS_HPP_ */

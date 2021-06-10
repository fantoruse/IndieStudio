/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include <utility>
#include <string>
#include <memory>
#include "Scene/AScene.hpp"

class Core {
    public:
    enum Scenes {
        QUIT = -1,
        MENU
    };
        Core(int screenWidth = 1920, int screenHeight = 1080, std::string const &title = "default", std::size_t const fps = 60);
        ~Core();

        void start();

    protected:
    private:
        std::vector<std::unique_ptr<AScene>> _vecScenes;
        int _screenWidth;
        int _screenHeight;
        int _scenePos;
        std::string _title;
        std::size_t _fps;
};

#endif /* !CORE_HPP_ */
/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** IScene
*/

#ifndef ISCENE_HPP_
#define ISCENE_HPP_

#include "Raylib/Raylib.hpp"

enum Scenes {
    QUIT = -1,
    MENU,
    NEW_GAME,
    GAME,
    LOAD,
    OPTION,
    LEADERBOARD
};

class IScene {
    public:
        virtual ~IScene() {};
        virtual void InitAssets() = 0;
        virtual Scenes run(Raylib &lib, Scenes const &prevScene) = 0;

    protected:
    private:
};

#endif /* !ISCENE_HPP_ */
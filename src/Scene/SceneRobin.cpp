/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** SceneRobin
*/

#include <iostream>
#include <functional>

#include "SceneRobin.hpp"
#include "Core.hpp"
#include "Tank.hpp"
#include "Map/Map.hpp"


#include "Raylib/Raylib.hpp"
#include "Object/AObject.hpp"
#include "Object/Ground/Ground.hpp"
#include "Object/UiObject/UiObject.hpp"
#include "Object/Collisionable/Wall/Wall.hpp"

const std::vector<std::string> _assetsPath {
    "asset/background_asset/ground.png",
    "asset/OBJFormat/ground.obj",
};

SceneRobin::SceneRobin(Setting &settings) : AScene(settings)
{
    auto const &map = std::make_unique<Map>();
    map->createDestructibleMap(std::make_pair(-5, -5), std::make_pair(5, 5));
    map->createContourMap(std::make_pair(-10, 10), std::make_pair(-8, 8));

    _objects.emplace_back(std::make_shared<Ground>(coords(0, 0, 0), std::make_pair(40, 22), std::pair<std::string, std::string>(_assetsPath.at(0), _assetsPath.at(1))));
    for (auto const &block : map->_objectNoDestructibleList)
        _objects.emplace_back(std::make_shared<Wall>(block));
    for (auto const &block : map->_objectDestructibleList)
        _objects.emplace_back(std::make_shared<DestructibleWall>(block));
    _objects.emplace_back(std::make_shared<Tank>("grosTankSaMere", coords(0,0,0), std::make_pair(10, 10), std::make_pair(Tank::sandCamo, Tank::body), std::make_pair(Tank::greenCamo, Tank::turret)));
    setInputsTank(_settings._keysPlayerOne, _objects.back());
    _objects.emplace_back(std::make_shared<Tank>("petitTankMignon", coords(6,0,0), std::make_pair(10, 10), std::make_pair(Tank::sandCamo, Tank::body), std::make_pair(Tank::greenCamo, Tank::turret)));
    setInputsTank(_settings._keysPlayerTwo, _objects.back());
}

SceneRobin::~SceneRobin()
{
    _objects.clear();
}

Scenes SceneRobin::run(Raylib &lib, Scenes const &prevScene)
{
    while (lib.gameLoop()) {
        triggerInputActions(lib);
        lib.printObjects(_objects);
    }
    return (Scenes::QUIT);
}
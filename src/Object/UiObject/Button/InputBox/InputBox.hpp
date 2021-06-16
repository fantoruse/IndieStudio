/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** InputBox
*/

#ifndef INPUTBOX_HPP_
#define INPUTBOX_HPP_

#include "UiObject/Button/Button.hpp"

class InputBox : public button::Button
{
    public:
        InputBox(const coords &pos, const std::pair<int, int> &size, const std::array<std::string, 3> &path, int sizeText, float scale, std::pair<RGB, RGB> color);
        ~InputBox();
        void changeText(char input, const std::pair<float, float> &pos);
};

#endif /* !INPUTBOX_HPP_ */
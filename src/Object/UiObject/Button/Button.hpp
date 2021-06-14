/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** Button
*/

#ifndef BUTTON_HPP_
#define BUTTON_HPP_

#include "UiObject.hpp"

enum buttonState_e
{
    NOTHING,
    OVER,
    CLICKED
};

class Button : public UiObject
{
    public:
        Button(const coords &pos, const std::pair<int, int> &size, const std::string &path, const std::string &text, float scale, std::pair<RGB, RGB> color);
        ~Button();
        void setText(const std::string &newText) noexcept;
        const std::string getText() const noexcept;
        const coords getTextPos() const noexcept;
        bool isInside(const std::pair<float, float> &pos) const;
        void setState(const std::pair<float, float> &pos, std::array<std::string, 3> arr, bool clicked);

    private:
        std::string _text;
        coords _textPos;
};

#endif /* !BUTTON_HPP_ */
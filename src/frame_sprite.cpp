#include "frame_sprite.h"
#include <iostream>

namespace Graphics {

    FrameSprite::FrameSprite(const std::string& file_path , const sf::IntRect& rect) {

        texture = new sf::Texture();

        if(!texture->loadFromFile(file_path , rect )) {
            std::cerr << "Error loading " << file_path << "\n";
            return;
        }

        std::cout << "Texture is loaded.\n";
        sprite = new sf::Sprite();
        sprite->setTexture(*texture);
    }


    FrameSprite::FrameSprite(sf::Texture* texture , const sf::IntRect& rect) {

        this->texture = texture;

        sprite = new sf::Sprite();
        sprite->setTexture(*texture);
        sprite->setTextureRect(rect);
    }


    
    void FrameSprite::draw(sf::RenderWindow& window) {
        window.draw(*sprite);
    }

    void FrameSprite::set_pos(int x , int y)  {
        sprite->setPosition(x , y);
    }


};

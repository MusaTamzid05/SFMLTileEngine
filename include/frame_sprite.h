#ifndef FRAME_SPRITE_H
#define FRAME_SPRITE_H


#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>


namespace Graphics {
    
    struct FrameSprite {

        sf::Texture* texture;
        sf::Sprite* sprite;

        FrameSprite(const std::string& file_path , const sf::IntRect& rect);
        FrameSprite(sf::Texture* texture ,  const sf::IntRect& rect);
        void draw(sf::RenderWindow& window);

        void set_pos(int x , int y);

    };
};


#endif

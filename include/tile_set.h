#ifndef TILE_SET_H
#define TILE_SET_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <string>
#include <vector>

#include "frame_sprite.h"

namespace Graphics {

    class TileSet {

        public:
            TileSet(const std::string& image_path , int rows , int cols);
            void draw(sf::RenderWindow& window);

        private:


            int rows;
            int cols;

            sf::Texture* m_texture;
            std::vector<std::vector<FrameSprite>> tiles;

            void generate_map();
    };

};
#endif

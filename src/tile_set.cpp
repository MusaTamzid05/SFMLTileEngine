#include "tile_set.h"
#include "util.h"
#include <iostream>

namespace Graphics {

    TileSet::TileSet(const std::string& image_path , int rows , int cols):
    rows(rows),
    cols(cols){

        m_texture = new sf::Texture();

        if(!m_texture->loadFromFile(image_path)) {
            std::cerr << "Could not load " << image_path << " for map generation.\n";
            return;
        }


        generate_map();

    }

    void TileSet::generate_map() {

        int width = m_texture->getSize().x;
        int height = m_texture->getSize().y;

        std::cout << "width : " << width << " height : "  << height << "\n";

        int row_incrementer = width  / rows;
        int col_incrementer = height  / cols;


        for(int col = 0 ; col < height ; col += col_incrementer) {

            std::vector<FrameSprite> sprites;

            for(int row = 0 ; row < width ; row += row_incrementer ) {
                sprites.push_back(FrameSprite(m_texture , sf::IntRect( row , col , row +  row_incrementer , col +  col_incrementer )));

                sprites[sprites.size() - 1].set_pos(row , col);
                std::cout << row << " " <<  " " << col << " " << row + row_incrementer << " " << col + col_incrementer << "\n";

            }

            tiles.push_back(sprites);

        }

    }
    
    void TileSet::draw(sf::RenderWindow& window) {

        for(unsigned int row = 0 ; row < tiles.size() ; row++)
            for(unsigned int col = 0 ; col < tiles[row].size() ; col++)
                tiles[row][col].draw(window);

    }
};

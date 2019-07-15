#include "game.h"
#include <iostream>
#include <stdlib.h>
#include <string>


namespace GameEngine{

    Game::Game(const std::string& window_name , int width , int height):
    tileset("../res/tileset.png" , 64 , 24){
        m_window = new sf::RenderWindow(sf::VideoMode(width , height) , window_name);


    }

    Game::~Game(){
        delete m_window;
    }

    void Game::run(float minimum_framerate){

        time_per_frame = sf::seconds(1.0f/ minimum_framerate);

        sf::Clock clock;
        sf::Time time_since_last_update = sf::Time::Zero;

        while(m_window->isOpen()) {
            process_event();
            time_since_last_update += clock.restart();
            update_if_time(time_since_last_update);
            render();
        }

    }

    void Game::update_if_time(sf::Time& time_since_last_update) {

        while(time_since_last_update > time_per_frame) {
            time_since_last_update -= time_per_frame;
            process_event();
            update(time_per_frame);
        }
    }

    void Game::process_event(){

        sf::Event event;

        while(m_window->pollEvent(event)){

            if(event.type == sf::Event::Closed)
                m_window->close();
        }

    }

    void Game::update(sf::Time& delta_time){

    }

    void Game::render(){

        m_window->clear();
        tileset.draw(*m_window);
        m_window->display();
    }






};

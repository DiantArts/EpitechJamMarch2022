///////////////////////////////////////////////////////////////////////////
// Precompilled headers
///////////////////////////////////////////////////////////////////////////
#include <pch.hpp>

///////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////
#include <xrn/Ecs.hpp>
#include <Game/Scene.hpp>
#include <Game/Menu.hpp>
#include <Game/FinalScreen.hpp>
#include <Game/Window.hpp>


///////////////////////////////////////////////////////////////////////////
auto main()
    -> int
try {
    ::sf::Music music;
    if (!music.openFromFile("./data/musics/dreams.wav")) {
        throw ::std::runtime_error{ "music failed to load" };
    }
    music.play();

    std::srand(std::time(nullptr));
    ::xrn::Window window;

    while (window.isOpen()) {
        { // menu
            ::xrn::Menu menu{ window };
            while (window.isOpen() && !menu.isOver()) {
                if (!window.handleEvents(menu)) {
                    if (menu.isOver()) {
                        return EXIT_SUCCESS;
                    } else {
                        break;
                    }
                }
                if (!menu.update()) {
                    if (menu.isOver()) {
                        return EXIT_SUCCESS;
                    } else {
                        break;
                    }
                }
                menu.draw();
            }
        }
        ::std::size_t score{ 0 };
        { // main game
            ::xrn::Scene scene{ window };
            while (window.isOpen() && !scene.isOver()) {
                if (!window.handleEvents(scene)) {
                    if (scene.isOver()) {
                        return EXIT_SUCCESS;
                    } else {
                        break;
                    }
                }
                if (!scene.update()) {
                    score = scene.getScore();
                    break;
                }
                scene.draw();
            }
        }
        // final screen
        if (score) {
            ::xrn::FinalScreen finalScreen{ window, score };
            while (window.isOpen() && !finalScreen.isOver()) {
                if (!window.handleEvents(finalScreen)) {
                    if (finalScreen.isOver()) {
                        return EXIT_SUCCESS;
                    } else {
                        break;
                    }
                }
                if (!finalScreen.update()) {
                    if (finalScreen.isOver()) {
                        return EXIT_SUCCESS;
                    } else {
                        break;
                    }
                }
                finalScreen.draw();
            }
        }
    }
    return EXIT_SUCCESS;
} catch (const ::std::exception& e) {
   ::std::cerr << "ERROR: " << e.what() <<::std::endl;
    return EXIT_FAILURE;
} catch (...) {
   ::std::cerr << "ERROR: unknown" <<::std::endl;
    return EXIT_FAILURE;
}

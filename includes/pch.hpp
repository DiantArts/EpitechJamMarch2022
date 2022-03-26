//
// Akanya, Engine
// includes/pch
// g++ -x c++-header -Wpedantic -Wall -Wextra -Wno-volatile -Wno-address -Wno-nonnull-compare -std=c++20 -Ofast -pipe -o includes/pch.hpp.gch -Iincludes -Isources -Ilibraries -Iexterns includes/pch.hpp
//

#ifndef ___INCLUDE_GUARD_INCLUDES_PCH_HPP___
#define ___INCLUDE_GUARD_INCLUDES_PCH_HPP___



#include <stack>
#include <vector>
#include <list>
#include <deque>
#include <array>
#include <set>
#include <map>
#include <queue>
#include <unordered_set>
#include <unordered_map>

#include <algorithm>
#include <chrono>
#include <fstream>
#include <functional>
#include <iostream>
#include <memory>
#include <mutex>
#include <ranges>
#include <span>
#include <sstream>
#include <stdexcept>
#include <string>
#include <string_view>
#include <variant>
#include <thread>
#include <utility>
#include <concepts>
#include <bitset>
#include <initializer_list>
#include <compare>
#include <cstring>

#include <experimental/type_traits>

using ::std::string_literals::operator""s;
using ::std::literals::string_view_literals::operator""sv;
using ::std::chrono_literals::operator""ms;

// suppresses warnings
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#include <Cbitset/Cbitset.hpp>
#pragma GCC diagnostic pop

#include <debugMacros.hpp>


#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Audio/Music.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

namespace xrn::component {
    class Drawable;
    class Movable;
    class Gravity;
    class Hitbox;
    class Text;
}

namespace xrn {
    class Window;
    class Scene;
}

// #define DEBUG_HITBOX

template <
    typename T
> ::std::ostream& operator<<(::std::ostream& os, const ::sf::Vector2<T>& vec)
{
    os << '[' << vec.x << ", " << vec.y << ']';
    return os;
}

template <
    typename T
> ::std::ostream& operator<<(::std::ostream& os, const ::sf::Rect<T>& rec)
{
    os << '[' << rec.left << ", " << rec.top << ", " << rec.width << ", " << rec.height << ']';
    return os;
}



#endif // ___INCLUDE_GUARD_INCLUDES_PCH_HPP___

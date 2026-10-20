// maybe something here...
#include "vector_util.h"
#include <SFML/System/Vector2.hpp>

struct BasicTransform {
    // Fields
    sf::Vector2f scale;
    sf::Vector2f translation;

    // Methods
    BasicTransform(
        const sf::Vector2f &scale = sf::Vector2f(1.0f, 1.0f), 
        const sf::Vector2f& translation = sf::Vector2f(0.0f, 0.0f)) {
            // Using default translation as (0, 0)
            // And default scaling as 1 * original
            
            this->scale = scale;
            this->translation = translation;
        }
    
    sf::Vector2f applyPoint(const sf::Vector2f& p) const {
        return (p * scale) + translation;
    }

    sf::Vector2f applyVector(const sf::Vector2f& p) const {
        return (p * scale);
    }

    bool operator==(const BasicTransform& other) const {
        bool condition = 
            (this->scale == other.scale) 
            && (this->translation == other.translation);

        return condition;
    }
};

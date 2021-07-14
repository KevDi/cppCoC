#include "player/player.hpp"

#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace jd::coc::model {
    Player::Player(std::string_view data) {
        json json_data = json::parse(data);
        tag_ = json_data["tag"].get<std::string>();
        name_ = json_data["name"].get<std::string>();
    }

    std::string Player::tag() const {
        return tag_;
    }

    std::string Player::name() const {
        return name_;
    }
}  // namespace jd::coc::model
#include "player/player.hpp"

#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace jd::coc::model {

    struct Player::PlayerImpl {
        std::string tag{};
        std::string name{};
        int exp_level{0};
        int townhall_level{0};
    };

    Player::Player() : pimpl_{std::make_unique<PlayerImpl>()} {}

    Player::Player(std::string_view data) : pimpl_{std::make_unique<PlayerImpl>()} {
        load_data(data);
    }

    Player::~Player() = default;

    std::string Player::tag() const {
        return pimpl_->tag;
    }

    std::string Player::name() const {
        return pimpl_->name;
    }

    int Player::exp_level() const {
        return pimpl_->exp_level;
    }

    int Player::townhall_level() const {
        return pimpl_->townhall_level;
    }

    void Player::load_data(std::string_view data) {
        json json_data = json::parse(data);
        pimpl_->tag = json_data["tag"].get<std::string>();
        pimpl_->name = json_data["name"].get<std::string>();
        pimpl_->exp_level = json_data["expLevel"].get<int>();
        pimpl_->townhall_level = json_data["townHallLevel"].get<int>();
    }
}  // namespace jd::coc::model
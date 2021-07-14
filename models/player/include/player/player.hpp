#ifndef PLAYER_H
#define PLAYER_H

#include <memory>
#include <string>
#include <string_view>
namespace jd {
    namespace coc {
        namespace model {
            class Player {
                class PlayerImpl;

               public:
                explicit Player(std::string_view data);
                Player();
                ~Player();
                std::string tag() const;
                std::string name() const;
                int exp_level() const;
                int townhall_level() const;
                int townhall_weapon_level() const;
                void load_data(std::string_view data);

               private:
                std::unique_ptr<PlayerImpl> pimpl_;
            };
        }  // namespace model
    }      // namespace coc
}  // namespace jd

#endif
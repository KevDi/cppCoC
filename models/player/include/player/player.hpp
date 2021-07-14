#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <string_view>
namespace jd {
    namespace coc {
        namespace model {
            class Player {
               public:
                explicit Player(std::string_view data);
                std::string tag() const;
                std::string name() const;

               private:
                std::string tag_{};
                std::string name_{};
            };
        }  // namespace model
    }      // namespace coc
}  // namespace jd

#endif
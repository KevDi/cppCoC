#include <gmock/gmock.h>

#include <fstream>
#include <player/player.hpp>

using namespace testing;
using namespace jd::coc::model;

TEST(Player, TagIsSetAfterLoadingTheData) {
    std::ifstream ifile{"resource/player.json"};
    std::string example;
    ifile.seekg(0, std::ios::end);
    example.reserve(ifile.tellg());
    ifile.seekg(0, std::ios::beg);

    example.assign((std::istreambuf_iterator<char>(ifile)), std::istreambuf_iterator<char>());

    Player player{example};

    ASSERT_THAT(player.tag(), Eq("#123456789"));
}
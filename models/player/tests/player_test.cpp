#include <gmock/gmock.h>

#include <fstream>
#include <player/player.hpp>

using namespace testing;
using namespace jd::coc;

class Player : public Test {
   public:
    void SetUp() override {
        std::ifstream ifile{"resource/player.json"};
        std::string example;
        ifile.seekg(0, std::ios::end);
        example.reserve(ifile.tellg());
        ifile.seekg(0, std::ios::beg);

        example.assign((std::istreambuf_iterator<char>(ifile)), std::istreambuf_iterator<char>());

        player_.load_data(example);
    }

    model::Player player_{};
};

TEST_F(Player, LoadDataSetsTheTag) {
    ASSERT_THAT(player_.tag(), Eq("#123456789"));
}

TEST_F(Player, LoadDataSetsTheName) {
    ASSERT_THAT(player_.name(), Eq("User"));
}

TEST_F(Player, LoadDataSetsTheExpLevel) {
    ASSERT_THAT(player_.expLevel(), Eq(42));
}

TEST_F(Player, LoadDataSetsTheTownhallLevel) {
    ASSERT_THAT(player_.townhall_level(), Eq(13));
}
#include <gmock/gmock.h>

#include <fstream>
#include <player/player.hpp>

using namespace testing;
using namespace jd::coc;

static const std::string PLAYER_JSON_PATH = "resource/player.json";
static const std::string ALTERNATIVE_PLAYER_JSON_PATH = "resource/player_alternative.json";
class Player : public Test {
   public:
    void SetUp() override {
        player_.load_data(load_file(PLAYER_JSON_PATH));
    }

    std::string load_file(const std::string& filename) {
        std::ifstream ifile{filename};
        std::string example;
        ifile.seekg(0, std::ios::end);
        example.reserve(ifile.tellg());
        ifile.seekg(0, std::ios::beg);

        example.assign((std::istreambuf_iterator<char>(ifile)), std::istreambuf_iterator<char>());
        return example;
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
    ASSERT_THAT(player_.exp_level(), Eq(42));
}

TEST_F(Player, LoadDataSetsTheTownhallLevel) {
    ASSERT_THAT(player_.townhall_level(), Eq(13));
}

TEST_F(Player, LoadDataSetsTownhallWeaponLevel) {
    ASSERT_THAT(player_.townhall_weapon_level(), Eq(5));
}

TEST_F(Player, LoadDataSetsTownhallWeaponLevelToZeroIfNotFound) {
    player_.load_data(load_file(ALTERNATIVE_PLAYER_JSON_PATH));

    ASSERT_THAT(player_.townhall_weapon_level(), Eq(0));
}
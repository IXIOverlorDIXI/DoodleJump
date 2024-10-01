#include "DefaultGameSprites.h"

std::string DGS::BackgroundSprite = std::string("bck@2x.png");

std::string DGS::DoodleLeftSprite = std::string("ghost-left@2x.png");
std::string DGS::DoodleRightSprite = std::string("ghost-right@2x.png");
std::string DGS::DoodleUpSprite = std::string("doodle-up-sprite.png");
std::string DGS::DoodleBulletSprite = std::string("bullet-sprite.png");

std::string DGS::DefaultPlatformSprite = std::string("doodle-platform.png");

std::string DGS::DefaultEnemySprite = std::string("enemy-sprite.png");

std::string DGS::JetpackSprite = std::string("jetpack-sprite.png");
std::string DGS::HatSprite = std::string("hat-sprite.png");

std::string DGS::DefaultSpringSprite = std::string("default-spring-sprite.png");
std::string DGS::TrampolineSprite = std::string("trampoline-sprite.png");

std::string DGS::UI::OverallScoreSprite = std::string("score-sprite.png");
std::string DGS::UI::JumpedOnScoreSprite = std::string("platform-jumped-on-score-sprite.png");
std::string DGS::UI::JumpedOverScoreSprite = std::string("platform-jumped-over-score-sprite.png");

std::vector<std::string> DGS::UI::NumbersSprites = {
	"0-sprite.png",
	"1-sprite.png",
	"2-sprite.png",
	"3-sprite.png",
	"4-sprite.png",
	"5-sprite.png",
	"6-sprite.png",
	"7-sprite.png",
	"8-sprite.png",
	"9-sprite.png",
};

std::string DGS::SpriteRelativePath = std::string("..\\DoodleJump\\data\\");
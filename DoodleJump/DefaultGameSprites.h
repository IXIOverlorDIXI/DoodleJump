#pragma once

#include <vector>

#include "string"

#define DGS DefaultGameSprites

class DefaultGameSprites {
public:
    static std::string BackgroundSprite;

    static std::string DoodleLeftSprite;
    static std::string DoodleRightSprite;
    static std::string DoodleUpSprite;
    static std::string DoodleBulletSprite;

    static std::string DefaultEnemySprite;

    static std::string JetpackSprite;
    static std::string HatSprite;

    static std::string DefaultSpringSprite;
    static std::string TrampolineSprite;

    static std::string DefaultPlatformSprite;

    static std::string SpriteRelativePath;

    class UI
    {
    public:
        static std::string OverallScoreSprite;
        static std::string JumpedOnScoreSprite;
        static std::string JumpedOverScoreSprite;

        static std::vector<std::string> NumbersSprites;
    };
};
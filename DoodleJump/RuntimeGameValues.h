#pragma once

#define RGV RuntimeGameValues

class RuntimeGameValues
{
public:
    static float VerticalScale;
    static float HorisontalScale;
    
    static float PlayerOverallScore;
    static int PlayerPlatformJumpedOnCounter;
    static int PlayerPlatformJumpedOverCounter;

    static bool IsLeftArrowPressed;
    static bool IsRightArrowPressed;
    static bool IsLeftMouseBottonPressed;
    static bool IsLeftMouseBottonReleased;

    static int MouseXPosition;
    static int MouseYPosition;

    static bool IsAlive;
    static bool BlindMode;

    static int LastTickDuration;
    static int LastTickDistance;
};
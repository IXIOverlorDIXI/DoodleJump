#include "RuntimeGameValues.h"

float RGV::VerticalScale = 1;
float RGV::HorisontalScale = 1;

float RGV::PlayerOverallScore = 0.0;
int RGV::PlayerPlatformJumpedOnCounter = 0;
int RGV::PlayerPlatformJumpedOverCounter = 0;

bool RGV::IsLeftArrowPressed = false;
bool RGV::IsRightArrowPressed = false;
bool RGV::IsLeftMouseBottonPressed = false;
bool RGV::IsLeftMouseBottonReleased = false;

int RGV::MouseXPosition = 0;
int RGV::MouseYPosition = 0;

bool RGV::IsAlive = false;
bool RGV::BlindMode = false;

int RGV::LastTickDuration = 0;
int RGV::LastTickDistance = 0;
#pragma once

#include "raylib.h"

class Platform
{
public:
    Platform(float X_, float Y_, float Width_, float Height_, KeyboardKey KeyUp_, KeyboardKey KeyDown_);

    void Draw();
    void Update();

    void RestartLocation();
    void SetSpeed(float NewSpeed) { Speed = NewSpeed; }
    void AddScore() { ++Score; }

    int GetScore() const { return Score; }
    float GetWeight() const { return Width; }
    float GetHeight() const { return Height; }
    Rectangle GetRectangle() const;

private:
    int Score = 0;
    float StartLocX = 0;
    float X, Y;
    float Width = 30.f;
    float Height;
    float Speed = 7.f;
    KeyboardKey KeyUp;
    KeyboardKey KeyDown;
};

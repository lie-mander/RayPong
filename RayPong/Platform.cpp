#include "Platform.h"
#include "raylib.h"

const Color CUSTOM_PURPLE{218, 112, 214, 255};

Platform::Platform(float X_, float Y_, float Width_, float Height_, KeyboardKey KeyUp_, KeyboardKey KeyDown_)
    : X(X_), Y(Y_), Width(Width_), Height(Height_), KeyUp(KeyUp_), KeyDown(KeyDown_), StartLocX(X_)
{
}

void Platform::Draw()
{
    DrawRectangleRounded(Rectangle{X, Y, Width, Height}, 1.f, 0, CUSTOM_PURPLE);
}

void Platform::Update() 
{
    if (IsKeyDown(KeyUp))
    {
        Y -= Speed;
    }
    else if (IsKeyDown(KeyDown))
    {
        Y += Speed;
    }

    if (Y + Height >= GetScreenHeight())
    {
        Y = GetScreenHeight() - Height;
    }
    if (Y <= 0.f)
    {
        Y = 0.f;
    }
}

void Platform::RestartLocation() 
{
    X = StartLocX;
    Y = (GetScreenHeight() / 2) - (Height / 2);
}

Rectangle Platform::GetRectangle() const
{
    Rectangle Result;
    Result.x = X;
    Result.y = Y;
    Result.width = Width;
    Result.height = Height;

    return Result;
}

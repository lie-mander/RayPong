#include "Ball.h"
#include "Platform.h"
#include "raylib.h"

const Color CUSTOM_ORANGE{255, 140, 0, 255};

Ball::Ball(float X_, float Y_, float Radius_, float Speed_) : X(X_), Y(Y_), Radius(Radius_), Speed_X(Speed_), Speed_Y(Speed_) {}

void Ball::Draw()
{
    DrawCircle(X, Y, Radius, CUSTOM_ORANGE);
}

bool Ball::Update(Platform& Platform_1, Platform& Platform_2)
{
    X += Speed_X;
    Y += Speed_Y;

    CheckCollisionWithWalls(); 
    CheckCollisionWithPlayers(Platform_1, Platform_2);

    if (X - Radius <= 0.f)
    {
        Platform_2.AddScore();
        return true;
    }
    else if (X + Radius >= GetScreenWidth())
    {
        Platform_1.AddScore();
        return true;
    }

    return false;
}

void Ball::RestartLocation() 
{
    int RandSpeed[2]{1, -1};
    int SelectRandSpeed = GetRandomValue(0, 1);
    Speed_X *= RandSpeed[SelectRandSpeed];

    X = GetScreenWidth() / 2;
    Y = GetScreenHeight() / 2;
}

void Ball::CheckCollisionWithPlayers(Platform& Platform_1, Platform& Platform_2)
{
    Vector2 Center;
    Center.x = X;
    Center.y = Y;

    if (CheckCollisionCircleRec(Center, Radius, Platform_1.GetRectangle()) ||
        CheckCollisionCircleRec(Center, Radius, Platform_2.GetRectangle()))
    {
        Speed_X *= -1.f;
    }
}

void Ball::CheckCollisionWithWalls() 
{
    if (Y + Radius >= GetScreenHeight() || Y - Radius <= 0.f)
    {
        Speed_Y *= -1.f;
    }
    if (X + Radius >= GetScreenWidth() || X - Radius <= 0.f)
    {
        Speed_X *= -1.f;
    }
}

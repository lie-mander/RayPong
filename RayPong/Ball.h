#pragma once

class Platform;

class Ball
{
public:
    Ball(float X_, float Y_, float Radius_, float Speed_);

    void Draw();

    // Return true if someone has score
    bool Update(Platform& Platform_1, Platform& Platform_2);
    void RestartLocation();

    void SetSpeedX(float NewSpeed) { Speed_X = NewSpeed; }
    void SetSpeedY(float NewSpeed) { Speed_Y = NewSpeed; }

private:
    float X, Y;
    float Speed_X, Speed_Y;
    float Radius;

    void CheckCollisionWithWalls();
    void CheckCollisionWithPlayers(Platform& Platform_1, Platform& Platform_2);
};
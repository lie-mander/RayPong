// Created by Liemander

#include "raylib.h"
#include "Ball.h"
#include "Platform.h"

const int SCREEN_WIDTH = 1600;
const int SCREEN_HEIGHT = 1200;
const float PLATFORM_WIDTH = 30.f;
const float PLATFORM_HEIGHT = 200.f;
const Color CUSTOM_GRAY{105, 105, 105, 255};

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "RayPong");
    SetTargetFPS(60);

    Ball Ball(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 20, 7);

    Platform Player_1(                                //
        10.f,                                         //
        (SCREEN_HEIGHT / 2) - (PLATFORM_HEIGHT / 2),  //
        PLATFORM_WIDTH,                               //
        PLATFORM_HEIGHT,                              //
        KeyboardKey ::KEY_W,                          //
        KeyboardKey::KEY_S                            //
    );

    Platform Player_2(                                //
        SCREEN_WIDTH - PLATFORM_WIDTH - 10.f,         //
        (SCREEN_HEIGHT / 2) - (PLATFORM_HEIGHT / 2),  //
        PLATFORM_WIDTH,                               //
        PLATFORM_HEIGHT,                              //
        KeyboardKey ::KEY_UP,                         //
        KeyboardKey::KEY_DOWN                         //
    );

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(CUSTOM_GRAY);

        // Updade objects
        if (Ball.Update(Player_1, Player_2))
        {
            Ball.RestartLocation();
            Player_1.RestartLocation();
            Player_2.RestartLocation();
        }

        Player_1.Update();
        Player_2.Update();

        // Drawing objects
        Ball.Draw();
        Player_1.Draw();
        Player_2.Draw();

        DrawText(TextFormat("%i", Player_1.GetScore()), (SCREEN_WIDTH / 2) - 400, 50, 100, WHITE);
        DrawText(TextFormat("%i", Player_2.GetScore()), (SCREEN_WIDTH / 2) + 400 - 50, 50, 100, WHITE);
        DrawLine(SCREEN_WIDTH / 2, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT, WHITE);
        DrawCircleLines(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 200, WHITE);

        EndDrawing();
    }

    return 0;
}

#include "raylib.h"
#include <cmath>
#include <iostream>

using namespace std;

#define MAX_COLUMNS 20

class Asteroid
{
    public:
        float x;
        float y;
        float size;
        float xAVel;
        float yAVel;
    
        Asteroid()
        {
            RandomizeAsteroid();
        }

        void RandomizeAsteroid()
        {
            int hold = GetRandomValue(0,3);
            switch(hold) 
            {
                case 0:
                    this->x = 0;
                    this->y = GetRandomValue(0,900);
                    this->xAVel = GetRandomValue(5,8);
                    this->yAVel = GetRandomValue(-5,5);
                    break;
                case 1:
                    this->x = 1600;
                    this->y = GetRandomValue(0,900);
                    this->xAVel = GetRandomValue(-8,-5);
                    this->yAVel = GetRandomValue(-5,5);
                    break;
                case 2:
                    this->x = GetRandomValue(0,1600);
                    this->y = 0;
                    this->xAVel = GetRandomValue(-5,5);
                    this->yAVel = GetRandomValue(5,8);
                    break;
                case 3:
                    this->x = GetRandomValue(0,1600);
                    this->y = 900;
                    this->xAVel = GetRandomValue(-5,5);
                    this->yAVel = GetRandomValue(-8,-5);
                    break;
            }
            this->size = GetRandomValue(30,90);

        }

        void UpdateAsteroid()
        {
            this->x += this->xAVel;
            this->y += this->yAVel;
            DrawCircle(this->x,this->y,this->size,BLACK);
            if(x < 0 || y < 0 || x > 1600 || y > 900)
                RandomizeAsteroid();
        }

        ~Asteroid()
        {

        }
};

int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1600;
    const int screenHeight = 900;

    InitWindow(screenWidth, screenHeight, "Asteroid Dodger");

    SetTargetFPS(60);

   
    while(!WindowShouldClose())
    {
        BeginDrawing();            
            static int state = 0;
            static float xPos = 800.0f, yPos = 450.0f, size = 40;
            static float xVel = 0, yVel = 0;         
            static Asteroid a,b,c,d,e,f,g,h;
            static float timer;  
            if(state == 2)
            {
                timer += GetFrameTime();
                ClearBackground(RAYWHITE);
                DrawFPS(0,0);
                DrawText(TextFormat("Elapsed Time: %02.02f", timer), 20, 100, 40, BLACK);
                cout << timer << endl;
                if(IsKeyDown(KEY_W))
                    yVel -= 0.24f;
                if(IsKeyDown(KEY_S))
                    yVel += 0.24f;
                if(IsKeyDown(KEY_A))
                    xVel -= 0.24f;
                if(IsKeyDown(KEY_D))
                    xVel += 0.24f;

                if(yVel > 0.0f)
                    yVel -= 0.04f;
                if(yVel < 0.0f)
                    yVel += 0.04f;
                if(xVel > 0.0f)
                    xVel -= 0.04f;
                if(xVel < 0.0f)
                    xVel += 0.04f;

                if(xVel < 0.04f && xVel > -0.04f)
                    xVel = 0.0f;
                if(yVel < 0.04f && yVel > -0.04f)
                    yVel = 0.0f;

                if(xVel > 6.0f)
                    xVel = 6.0f;
                if(xVel < -6.0f)
                    xVel = -6.0f;
                if(yVel > 6.0f)
                    yVel = 6.0f;
                if(yVel < -6.0f)
                    yVel = -6.0f;
                xPos += xVel;
                yPos += yVel;

                DrawCircle(xPos,yPos,size,MAROON);

                if(xPos < 0 || yPos < 0 || xPos > 1600 || yPos > 900)
                    state = 1;
                
                a.UpdateAsteroid();
                if(CheckCollisionCircles(Vector2{xPos,yPos},size,Vector2{a.x,a.y},a.size))
                    state = 1;

    
                b.UpdateAsteroid();
                if(CheckCollisionCircles(Vector2{xPos,yPos},size,Vector2{b.x,b.y},b.size))
                    state = 1;

                c.UpdateAsteroid();
                if(CheckCollisionCircles(Vector2{xPos,yPos},size,Vector2{c.x,c.y},c.size))
                    state = 1;

                d.UpdateAsteroid();
                if(CheckCollisionCircles(Vector2{xPos,yPos},size,Vector2{d.x,d.y},d.size))
                    state = 1;

                e.UpdateAsteroid();
                if(CheckCollisionCircles(Vector2{xPos,yPos},size,Vector2{e.x,e.y},e.size))
                    state = 1;

                f.UpdateAsteroid();
                if(CheckCollisionCircles(Vector2{xPos,yPos},size,Vector2{f.x,f.y},f.size))
                    state = 1;

                g.UpdateAsteroid();
                if(CheckCollisionCircles(Vector2{xPos,yPos},size,Vector2{g.x,g.y},g.size))
                    state = 1;

                h.UpdateAsteroid();
                if(CheckCollisionCircles(Vector2{xPos,yPos},size,Vector2{h.x,h.y},h.size))
                    state = 1;
            }
            else if(state == 1)
            {   
                cout << "Final time: " << timer << endl;
                ClearBackground(RAYWHITE);
                DrawText(TextFormat("Your Time: %02.02f", timer), 1600/2 - 300, 900/2 + 40, 70, BLACK);
                DrawText("Press Space to Restart", 1600/2 - 400, 900/2 + 100, 70, BLACK);
                if(IsKeyPressed(KEY_SPACE))
                {
                    state = 2;
                    xPos = 800.0f;
                    yPos = 450.0f;
                    size = 40;
                    xVel = 0;
                    yVel = 0;
                    timer = 0;
                    a.RandomizeAsteroid();
                    b.RandomizeAsteroid();
                    c.RandomizeAsteroid();
                    d.RandomizeAsteroid();
                    e.RandomizeAsteroid();
                    f.RandomizeAsteroid();
                    g.RandomizeAsteroid();
                    h.RandomizeAsteroid();
                }    
            }
            else if(state == 0)
            {
                ClearBackground(RAYWHITE);
                DrawText("Press Space to Start", 1600/2 - 400, 900/2 - 200, 70, BLACK);
                if(IsKeyPressed(KEY_SPACE))
                {
                    state = 2;
                    xPos = 800.0f;
                    yPos = 450.0f;
                    size = 40;
                    xVel = 0;
                    yVel = 0;
                    timer = 0;
                    a.RandomizeAsteroid();
                    b.RandomizeAsteroid();
                    c.RandomizeAsteroid();
                    d.RandomizeAsteroid();
                    e.RandomizeAsteroid();
                    f.RandomizeAsteroid();
                    g.RandomizeAsteroid();
                    h.RandomizeAsteroid();
                }
            }          
        EndDrawing();
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
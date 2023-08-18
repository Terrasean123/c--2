
#include "raylib.h"
#include "DataFile.h"

int main(int argc, char* argv[])
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    DataFile data;
    int currentRecordIdx = 0;

  

   DataFile::Record* currentRecord = data.GetRecord(currentRecordIdx, "npc_data.dat");
    Texture2D recordTexture = LoadTextureFromImage(currentRecord->image);


    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        if (IsKeyPressed(KEY_LEFT))
        {
            currentRecordIdx--;
            if (currentRecordIdx < 0)
            {
                currentRecordIdx = 0;
            }
            delete currentRecord;
            currentRecord = data.GetRecord(currentRecordIdx, "npc_data.dat");
            UnloadTexture(recordTexture);
            recordTexture = LoadTextureFromImage(currentRecord->image);
            UnloadImage(currentRecord->image);

        }

        if (IsKeyPressed(KEY_RIGHT))
        {
            currentRecordIdx++;
            if (currentRecordIdx >= data.GetRecordCount())
            {
                // previously the record iterator was going out of bounds of the vector array 
                currentRecordIdx = data.GetRecordCount()-1;
            }

            delete currentRecord;

            currentRecord = data.GetRecord(currentRecordIdx, "npc_data.dat");
            UnloadTexture(recordTexture);
            recordTexture = LoadTextureFromImage(currentRecord->image);
            UnloadImage(currentRecord->image);

        }


        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(recordTexture, 300, 50, WHITE);

        DrawText("NAME", 10, 50, 20, LIGHTGRAY);
        DrawText(currentRecord->name.c_str(), 10, 80, 20, LIGHTGRAY);

        DrawText("AGE", 10, 120, 20, LIGHTGRAY);
        DrawText(to_string(currentRecord->age).c_str(), 10, 150, 20, LIGHTGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
#include <raylib.h>
#include <iostream>
#include <vector>

using namespace std;

class KeyBox{
    public:
        char KeyType;
        Vector2 KeyPos;
        KeyBox(char T,float P){
            KeyType = T;
            KeyPos = {P*140,-140};
        }
};

struct TempKeys{
    char KT;
    float KP;
};

int main(){
    InitWindow(1400,720,"keybrrr");
    SetTargetFPS(60);
    Texture2D Sprite_Keys = LoadTexture("./assets/sed.png");
    float Speed = 1.5;

    TempKeys KeyArr[9] = {{'a',0},{'s',1},{'d',2},{'f',3},{'g',4},{'h',5},{'j',6},{'k',7},{'l',8}};
    
    vector<KeyBox> KeyCurr;
    int randomvalue;
    char currpressed;
    int ScoreBoard = 0;
    KeyCurr.push_back(KeyBox(KeyArr[4].KT,KeyArr[4].KP));
    while(!WindowShouldClose()){
        if(KeyCurr.back().KeyPos.y > 0){
            randomvalue = GetRandomValue(0,8);
            KeyCurr.push_back(KeyBox(KeyArr[randomvalue].KT,KeyArr[randomvalue].KP));
            }
        if(KeyCurr.front().KeyPos.y > 650){
            KeyCurr.clear();
            KeyCurr.push_back(KeyBox(KeyArr[4].KT,KeyArr[4].KP));
            ScoreBoard = 0;
            Speed = 1.5;
        }
        BeginDrawing();
        ClearBackground(BLACK);
        for(int i = 0;i<(int)KeyCurr.size();++i){
            DrawTextureRec(Sprite_Keys, Rectangle{KeyCurr[i].KeyPos.x, 0, 140, 140},KeyCurr[i].KeyPos,RAYWHITE);
            DrawText(to_string(ScoreBoard).c_str(),1260,100,30,RAYWHITE);
            //DrawTextureEx(Sprite_Keys,KeyCurr[i].KeyPos,0,1,RAYWHITE);
            KeyCurr[i].KeyPos.y += Speed;
            }
        EndDrawing();
        currpressed = GetCharPressed();
        if(currpressed != 0){
            if(currpressed == KeyCurr.front().KeyType){
                if(KeyCurr.front().KeyPos.y>0){
                    KeyCurr.erase(KeyCurr.begin());
                    ScoreBoard ++;
                }
            }
            else{
            KeyCurr.clear();
            KeyCurr.push_back(KeyBox(KeyArr[4].KT,KeyArr[4].KP));
            ScoreBoard = 0;
            Speed = 1.5;
            };
        }
        Speed += 0.01;
    }
    CloseWindow();
    return 0;
}

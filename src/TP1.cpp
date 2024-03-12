#include "entrypoint.h"
#include <stdio.h>

//Creer votre class Engin ici et appeler une fonction start que vous définisser à la classe dans la fonction raylib_start plus bas.
void raylib_start(void){

// std::vector<int> gGrid;

// void CreateGrid(int w, int h) {
// int size = w * h;
// gGrid.resize(size, 0 );
// }
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
CreateGrid( 4, 4 );
}


void DrawGrid(const std::vector<int>& grid, int w, int h,int size) {
for (size_t i = 0 ; i < grid.size(); i++) {
Rectangle dst;
dst.x = (i % w) * size;
dst.y = (i / w) * size;
dst.w = size;
dst.h = size;
if(grid[i] == 0){
DrawRectangleRec(dst,WHITE);
DrawRectangleLinesEx(dst,2.0f,BLACK);
}
else{
DrawRectangleRec(dst,RED);
}
}
}

void SetValueGridSpace(int w, int x, int y, int value) {
//Pour trouver l'index:
// y * width + x
// 3 * 4 + 2 == 14
int idx = y * w + x;
gGrid[idx] = value;
}
void SetValueWorldSpace(int w, int x, int y, int size, int value){
// 64 / tuile == 64 / 32 == 2
int _x = x / size;
// 96 / tuile == 96 / 32 == 3
int _y = y / size;
SetValueGridSpace(w, _x, _y, value);
}


}
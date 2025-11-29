#include "settings.h"
#include "raylib.h"

namespace Game{

bool CheckMaskCollision(Texture2D imgAt, Vector2 posA, Texture2D imgBt, Vector2 posB) {
    auto imgA = LoadImageFromTexture(imgAt);
    auto imgB = LoadImageFromTexture(imgBt);
    Rectangle rectA = { posA.x, posA.y, (float)imgA.width, (float)imgA.height };
    Rectangle rectB = { posB.x, posB.y, (float)imgB.width, (float)imgB.height };

    if (!CheckCollisionRecs(rectA, rectB)) return false;

    float overlapX = fmaxf(rectA.x, rectB.x);
    float overlapY = fmaxf(rectA.y, rectB.y);
    float overlapW = fminf(rectA.x + rectA.width, rectB.x + rectB.width) - overlapX;
    float overlapH = fminf(rectA.y + rectA.height, rectB.y + rectB.height) - overlapY;

    if (overlapW <= 0 || overlapH <= 0) return false;

    Color *pixelsA = LoadImageColors(imgA);
    Color *pixelsB = LoadImageColors(imgB);

    for (int y = 0; y < (int)overlapH; y++) {
        for (int x = 0; x < (int)overlapW; x++) {
            int ax = (int)(overlapX - rectA.x) + x;
            int ay = (int)(overlapY - rectA.y) + y;
            int bx = (int)(overlapX - rectB.x) + x;
            int by = (int)(overlapY - rectB.y) + y;

            Color ca = pixelsA[ay * imgA.width + ax];
            Color cb = pixelsB[by * imgB.width + bx];

            if (ca.a > 0 && cb.a > 0) {
                UnloadImageColors(pixelsA);
                UnloadImageColors(pixelsB);
                return true;
            }
        }
    }

    UnloadImageColors(pixelsA);
    UnloadImageColors(pixelsB);
    return false;
}


}
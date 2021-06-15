#include "BattleRoom.h"

bool BattleRoom::init() {
    centerX = .0f, centerY = .0f;
    x = 0, y = 0;
    visTime = 0, nextDIR = 0;
    nextRoom = nullptr, prevRoom = nullptr;

    memset(visDir, 0, sizeof(visDir));

    //enemyCtr = EnemyController::create(); //controll enemy behaviors
    return true;
}

void BattleRoom::setCenter(float X, float Y) { centerX = X, centerY = Y; }

float BattleRoom::getCenterX() { return centerX; }

float BattleRoom::getCenterY() { return centerY; }

INT32 BattleRoom::getX() { return x; }

INT32 BattleRoom::getY() { return y; }

void BattleRoom::createMap() {
    const float X = centerX - FLOORWIDTH * (SIZEROOM / 2);
    const float Y = centerY + FLOORWIDTH * (SIZEROOM / 2);

    float curX = X, curY = Y;
    for (INT32 y = SIZEROOM - 1; y >= 0; y--) {
        for (INT32 x = 0; x < SIZEROOM; x++) {
            Sprite* tmpSprite = nullptr;
            if (y == 0 || y == SIZEROOM - 1 || x == 0 || x == SIZEROOM - 1) {
                tmpSprite = Sprite::create("Map//wall1.png");
                this->addChild(tmpSprite, 1);
            }
            else {
                tmpSprite = Sprite::create("Map//floor1.png");
                this->addChild(tmpSprite, 0);
            }

            //assert(tmpSprite == nullptr);
            tmpSprite->setPosition(Point(curX, curY));

            vecBG.pushBack(tmpSprite);
            curX += FLOORWIDTH;
        }
        curX = X, curY -= FLOORHEIGHT;
    }
}

void connect(BattleRoom* other) {

}

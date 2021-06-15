#include "safescene.h"
#include "Knight.h"
Scene* SafeScene::createScene() { return SafeScene::create(); }

void SafeScene::update(float delta) {
    float posX1 = bgSprite1->getPositionX();
    float posX2 = bgSprite2->getPositionX();

    float iSpeed = 3;

    posX1 -= iSpeed;
    posX2 -= iSpeed;

    Size mapSize = bgSprite1->getContentSize();

    if (posX1 <= -mapSize.width / 2.0) posX1 += mapSize.width * 2 + mapSize.width / 2;

    if (posX2 <= -mapSize.width / 2.0) posX2 += mapSize.width * 2 + mapSize.width / 2;


    bgSprite1->setPositionX(posX1);

    bgSprite2->setPositionX(posX2);
}

bool SafeScene::init() {
    if (!Scene::init()) {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();

    // add knight to scene
    knight = Knight::KnightCreate("Character//Knight.png");
    knight->getSprite()->setPosition(visibleSize.width / 2+310, visibleSize.height / 2+270);
    addChild(knight->getSprite(),2);
    this->knight->getSprite()->setScaleX(1.2);
    this->knight->getSprite()->setScaleY(1.2);

    initBG();


    //this->scheduleUpdate();

    return true;
}

void SafeScene::initBG() {
    Size visibleSize = Director::getInstance()->getVisibleSize();

    //background sprite1
    this->bgSprite1 = Sprite::create("Scene//SafeScene.png");

    Size bgSize1 = this->bgSprite1->getBoundingBox().size;
    this->bgSprite1->setScale(visibleSize.width / bgSize1.width,
        visibleSize.height / bgSize1.height);

    this->bgSprite1->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));

    this->addChild(this->bgSprite1, 0);

    // background sprite2
    this->bgSprite2 = Sprite::create("Scene//SafeScene.png");

    Size bgSize2 = this->bgSprite2->getBoundingBox().size;
    this->bgSprite2->setScale(visibleSize.width / bgSize2.width,
        visibleSize.height / bgSize2.height);

    this->bgSprite2->setPosition(Point(
        visibleSize.width + visibleSize.width / 2, visibleSize.height / 2));

    this->addChild(this->bgSprite2, 0);
}


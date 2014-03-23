#include "HelloWorldScene.h"

using namespace cocos2d;

CCScene* HelloWorld::scene()
{
    CCScene *scene = CCScene::create();
    HelloWorld *layer = HelloWorld::create();
    scene->addChild(layer);
    return scene;
}

bool HelloWorld::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
	
    this->setTouchEnabled(true);
	
    CCSize size = CCDirector::sharedDirector()->getWinSize();

	ball = CCSprite::create("button.png");
    ball->setPosition( ccp(size.width/2, size.height/2) );
	ball->setTag(1);
    this->addChild(ball);
	
   return true;
}

void HelloWorld::xtTouchesBegan(CCPoint position)
{
    CCLog("xtTouchesBegan x: %f, y: %f", position.x, position.y);
}

void HelloWorld::xtTouchesEnded(CCPoint position)
{
    CCLog("xtTouchesEnded x: %f, y: %f", position.x, position.y);
}

void HelloWorld::xtSwipeGesture(XTTouchDirection direction, float distance, float speed)
{
    std::string directionStr = "";
	int directionX = 0;
	int directionY = 0;
    switch (direction) {
        case XTLayer::UP:
			directionStr = "UP";
			directionY = 1;
			break;
        case XTLayer::DOWN:
			directionStr = "DOWN";
			directionY = -1;
			break;
        case XTLayer::LEFT:
			directionStr = "LEFT";
			directionX = 1;
			break;
        case XTLayer::RIGHT:
			directionStr = "RIGHT";
			directionY = -1;
			break;
        default:
			break;
    }

	CCSize size = CCDirector::sharedDirector()->getWinSize();

	float duration = speed;
	float distX = ball->getPositionX() + size.width * 0.1 * directionX;
	float distY = ball->getPositionY() + size.height * 0.1 * directionY;
	CCMoveTo* actionMove = CCMoveTo::create(duration, ccp(distX, distY));
	
	ball->runAction(actionMove);
	
    CCLog("xtSwipeGesture direction: %s, distance: %f, speed: %f", directionStr.c_str(), distance, speed);
}
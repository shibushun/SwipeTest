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

	ball = CCSprite::create("ball.png");
	ball->setPosition( ccp(size.width/2, size.height/2) );
	this->addChild(ball);
	
	// show direction
	CCLabelTTF* directionLabel = CCLabelTTF::create("direction", "arial", 24);
	directionLabel->setPosition(ccp(size.width/2, size.height*4/5));
	directionLabel->setTag(1);
	this->addChild(directionLabel);
	
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
    std::string directionStr;
	int directionX, directionY;

    switch (direction) {
        case XTLayer::UP:
			directionStr = "UP";
			directionX = 0;
			directionY = 1;
			break;
        case XTLayer::DOWN:
			directionStr = "DOWN";
			directionX = 0;
			directionY = -1;
			break;
        case XTLayer::LEFT:
			directionStr = "LEFT";
			directionX = -1;
			directionY = 0;
			break;
        case XTLayer::RIGHT:
			directionStr = "RIGHT";
			directionX = 1;
			directionY = 0;
			break;
        default:
			break;
    }

	float duration = 1/speed;
	float distX = distance * directionX;
	float distY = distance * directionY;
	CCMoveBy* actionMove = CCMoveBy::create(duration, ccp(distX, distY));
	
	ball->runAction(actionMove);
	
    CCLog("xtSwipeGesture direction: %s, distance: %f, speed: %f", directionStr.c_str(), distance, speed);

	CCLabelTTF* label = (CCLabelTTF *)this->getChildByTag(1);
	label->setString(directionStr.c_str());
}

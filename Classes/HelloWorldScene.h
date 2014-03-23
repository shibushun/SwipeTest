#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "XTLayer.h"

class HelloWorld : public XTLayer
{
public:
    virtual bool init();
    static cocos2d::CCScene* scene();
    CREATE_FUNC(HelloWorld);
	
	CCSprite* ball;
	bool ballTouch;

	virtual void xtTouchesBegan(CCPoint position);
    virtual void xtTouchesEnded(CCPoint position);

    virtual void xtSwipeGesture(XTTouchDirection direction, float distance, float speed);
};

#endif // __HELLOWORLD_SCENE_H__
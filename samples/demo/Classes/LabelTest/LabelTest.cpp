#include "LabelTest.h"

#define CAColor_blueStyle ccc4(51,204,255,255)

LabelTest::LabelTest():
sum(30)
{
	CADrawerController* drawer = (CADrawerController*)CAApplication::getApplication()->getRootWindow()->getRootViewController();
	drawer->setTouchMoved(false);
}

LabelTest::~LabelTest()
{

}

void LabelTest::viewDidLoad()
{
	size = this->getView()->getBounds().size;
    
	CALabel* currentValue = CALabel::createWithCenter(CADipRect(size.width*0.5, size.height*0.1, size.width*0.5, size.height*0.1));
	currentValue->setText("60 seconds countdown");
	currentValue->setColor(CAColor_blueStyle);
	currentValue->setFontSize((_px(30)));
	currentValue->setTextAlignment(CATextAlignmentCenter);
	currentValue->setVerticalTextAlignmet(CAVerticalTextAlignmentCenter);
	this->getView()->addSubview(currentValue);

	number1 = CALabel::createWithCenter(CADipRect(size.width*0.5, size.height*0.2, size.width*0.5, size.height*0.1));
	number1->setTag(10);
	number1->setTextAlignment(CATextAlignmentCenter);
	number1->setVerticalTextAlignmet(CAVerticalTextAlignmentCenter);
	number1->setText("00");
	number1->setFontSize((_px(30)));
	number1->setColor(CAColor_blue);
	this->getView()->addSubview(number1);

	number2 = CALabel::createWithCenter(CADipRect(size.width*0.5, size.height*0.3, size.width*0.5, size.height*0.1));
	number2->setTag(11);
	number2->setTextAlignment(CATextAlignmentCenter);
	number2->setVerticalTextAlignmet(CAVerticalTextAlignmentCenter);
	number2->setText("00");
	number2->setFontSize((_px(40)));
	number2->setColor(CAColor_green);
	this->getView()->addSubview(number2);

	number3 = CALabel::createWithCenter(CADipRect(size.width*0.5, size.height*0.4, size.width*0.5, size.height*0.1));
	number3->setTag(12);
	number3->setTextAlignment(CATextAlignmentCenter);
	number3->setVerticalTextAlignmet(CAVerticalTextAlignmentCenter);
	number3->setText("00");
	number3->setFontSize((_px(50)));
	number3->setColor(CAColor_orange);
	this->getView()->addSubview(number3);

	CAScheduler::schedule(schedule_selector(LabelTest::numberChange),this,1,false);
}

void LabelTest::numberChange(float interval)
{
	char num[10] = "";
	sum=sum-1;
	sprintf(num,"%02d",sum);
	for (int i = 10; i < 13; i++)
	{
		CALabel* label = (CALabel*)this->getView()->getSubviewByTag(i);
		label->setText(num);
		label->visit();
		if (sum == 0)
		{
			CAScheduler::unschedule(schedule_selector(LabelTest::numberChange), this);
			label->setText("Over");
		}
	}
}

void LabelTest::viewDidUnload()
{
	CAScheduler::unschedule(schedule_selector(LabelTest::numberChange), this);
}
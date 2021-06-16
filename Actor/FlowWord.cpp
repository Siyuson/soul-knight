#include "FlowWord.h"
#include"Const/Const.h"

bool FlowWord::init()
{
	m_textLab = Label::createWithTTF("", "fonts/Marker Felt.ttf", 22);
	m_textLab->setColor(Color3B(255, 0, 0));
	m_textLab->setAnchorPoint(Point(0.5, 0.5));
	m_textLab->setGlobalZOrder(TOP);

	this->addChild(m_textLab);
	return true;
}

void FlowWord::showWord(int num, Point pos)
{
	if (num > 0) {
		m_textLab->setString("+" + Value(num).asString());
	}
	else {
		m_textLab->setString(Value(num).asString());
	}
	m_textLab->setPosition(pos);
	m_textLab->setVisible(true);

	/*创建一个延时动作*/
	auto delayTime = DelayTime::create(0.18f);

	auto callFunc = CallFunc::create([&]() {
		/* 动作结束，从父节点中删除自身 */
		m_textLab->removeFromParentAndCleanup(true);
		});

	auto actions = Sequence::create(delayTime, callFunc, NULL);

	m_textLab->runAction(actions);
}


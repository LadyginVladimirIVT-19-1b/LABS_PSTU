#pragma once
#include <iostream>
#include "Object.h"
#include "Event.h"

using namespace std;


class Object
{
public:
	Object(void);
	virtual void Show() = 0;
	virtual void Input() = 0;
	virtual ~Object(void);
	virtual void HandleEvent(const TEvent& e) = 0;
	virtual void average_age(const TEvent& e) = 0;
};


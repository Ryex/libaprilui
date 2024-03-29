/// @file
/// @author  Boris Mikic
/// @version 3.0
/// 
/// @section LICENSE
/// 
/// This program is free software; you can redistribute it and/or modify it under
/// the terms of the BSD license: http://www.opensource.org/licenses/bsd-license.php

#include <hltypes/hstring.h>

#include "AnimatorBlueChanger.h"

namespace aprilui
{
	namespace Animators
	{
		BlueChanger::BlueChanger(chstr name) : Animator(name)
		{
		}

		BlueChanger::~BlueChanger()
		{
		}

		Animator* BlueChanger::createInstance(chstr name)
		{
			return new BlueChanger(name);
		}

		float BlueChanger::_getObjectValue()
		{
			return (float)this->parent->getBlue();
		}

		void BlueChanger::_setObjectValue(float value)
		{
			this->parent->setBlue((unsigned char)value);
		}

		void BlueChanger::update(float k)
		{
			this->_valueUpdateUChar(k);
		}
		
	}
}

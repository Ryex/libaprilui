/// @file
/// @author  Boris Mikic
/// @version 3.0
/// 
/// @section LICENSE
/// 
/// This program is free software; you can redistribute it and/or modify it under
/// the terms of the BSD license: http://www.opensource.org/licenses/bsd-license.php

#include <hltypes/hstring.h>

#include "AnimatorRedChanger.h"

namespace aprilui
{
	namespace Animators
	{
		RedChanger::RedChanger(chstr name) : Animator(name)
		{
		}

		RedChanger::~RedChanger()
		{
		}

		Animator* RedChanger::createInstance(chstr name)
		{
			return new RedChanger(name);
		}

		float RedChanger::_getObjectValue()
		{
			return (float)this->parent->getRed();
		}

		void RedChanger::_setObjectValue(float value)
		{
			this->parent->setRed((unsigned char)value);
		}

		void RedChanger::update(float k)
		{
			this->_valueUpdateUChar(k);
		}
		
	}
}

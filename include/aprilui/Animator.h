/// @file
/// @author  Boris Mikic
/// @author  Kresimir Spes
/// @version 3.0
/// 
/// @section LICENSE
/// 
/// This program is free software; you can redistribute it and/or modify it under
/// the terms of the BSD license: http://www.opensource.org/licenses/bsd-license.php
/// 
/// @section DESCRIPTION
/// 
/// Defines an base class for animators.

#ifndef APRILUI_ANIMATOR_H
#define APRILUI_ANIMATOR_H

#include <gtypes/Rectangle.h>

#include "Object.h"

#include "apriluiExport.h"

namespace aprilui
{
	class apriluiExport Animator : public Object
	{
	public:
		friend class Object;

		Animator(chstr name);
		~Animator();
		
		HL_DEFINE_GETSET(AnimationFunction, animationFunction, AnimationFunction);
		HL_DEFINE_GETSET(float, value, Value);
		HL_DEFINE_GETSET(float, timer, Timer);
		HL_DEFINE_GETSET(float, delay, Delay);
		HL_DEFINE_GETSET(float, periods, Periods);
		HL_DEFINE_GETSET(float, amplitude, Amplitude);
		HL_DEFINE_GETSET(float, speed, Speed);
		HL_DEFINE_GETSET(float, offset, Offset);
		HL_DEFINE_GETSET(float, acceleration, Acceleration);
		HL_DEFINE_GETSET(int, discreteStep, DiscreteStep);
		HL_DEFINE_ISSET(reset, Reset);
		HL_DEFINE_ISSET(inheritValue, InheritValue);
		HL_DEFINE_GETSET(float, target, Target);
		HL_DEFINE_ISSET(useTarget, UseTarget);
		float (*getCustomFunction())(Animator*, float) { return this->customFunction; }
		void setCustomFunction(float (*value)(Animator*, float)) { this->customFunction = value; }

		bool isAnimated();
		bool isWaitingAnimation();
		bool isExpired();
		void setTime(float value);
		
		hstr getProperty(chstr name, bool* propertyExists);
		bool setProperty(chstr name, chstr value);

		void notifyEvent(chstr name, void* params);
		
		void update(float k);

		void OnDrawDebug();
		
	protected:
		float timeSinceLastFrame;
		float value;
		AnimationFunction animationFunction;
		float timer;
		float delay;
		float periods;
		float amplitude;
		float speed;
		float offset;
		float acceleration;
		int discreteStep;
		bool reset;
		bool inheritValue;
		float target;
		bool useTarget;
		float (*customFunction)(Animator*, float);
		
		float _calculateValue(float k);
		bool _checkUpdate(float k);

		void _valueUpdateSimple(float k);
		void _valueUpdateUChar(float k);

		virtual float _getObjectValue() = 0;
		virtual void _setObjectValue(float value) = 0;

	};

}

#endif

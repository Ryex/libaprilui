/// @file
/// @author  Kresimir Spes
/// @author  Boris Mikic
/// @version 3.0
/// 
/// @section LICENSE
/// 
/// This program is free software; you can redistribute it and/or modify it under
/// the terms of the BSD license: http://www.opensource.org/licenses/bsd-license.php
/// 
/// @section DESCRIPTION
/// 
/// Defines a callback object.

#ifndef APRILUI_CALLBACK_OBJECT_H
#define APRILUI_CALLBACK_OBJECT_H

#include <gtypes/Rectangle.h>
#include <hltypes/hstring.h>

#include "apriluiExport.h"
#include "Object.h"

namespace aprilui
{
	class apriluiExport CallbackObject : public Object
	{
	public:
		CallbackObject(chstr name, grect rect);
		~CallbackObject();
		static Object* createInstance(chstr name, grect rect);

		void (*getDrawCallback())(CallbackObject*) { return this->drawCallback; }
		void setDrawCallback(void (*value)(CallbackObject*)) { this->drawCallback = value; }
		void setUpdateCallback(void (*value)(float)) { this->updateCallback = value; }
		
		void update(float k);
		void OnDraw();

		bool onMouseDown(april::Key keyCode);
		bool onMouseUp(april::Key keyCode);
		bool onMouseMove();
		bool onMouseScroll(float x, float y);
		void mouseCancel();

	protected:
		void (*drawCallback)(CallbackObject*);
		void (*updateCallback)(float);

	};
}

#endif

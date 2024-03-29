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
/// Defines a color-quad object.

#ifndef APRILUI_COLORED_QUAD_H
#define APRILUI_COLORED_QUAD_H

#include <april/RenderSystem.h>
#include <gtypes/Rectangle.h>
#include <hltypes/hstring.h>

#include "apriluiExport.h"
#include "Object.h"

namespace aprilui
{
	class apriluiExport ColoredQuad : public Object
	{
	public:
		ColoredQuad(chstr name, grect rect);
		~ColoredQuad();
		static Object* createInstance(chstr name, grect rect);
		
		void OnDraw();

		bool onMouseDown(april::Key keyCode);
		bool onMouseUp(april::Key keyCode);
		
	};
}

#endif

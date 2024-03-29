/// @file
/// @author  Boris Mikic
/// @version 3.1
/// 
/// @section LICENSE
/// 
/// This program is free software; you can redistribute it and/or modify it under
/// the terms of the BSD license: http://www.opensource.org/licenses/bsd-license.php
/// 
/// @section DESCRIPTION
/// 
/// Defines a progress circle.

#ifndef APRILUI_PROGRESS_CIRCLE_H
#define APRILUI_PROGRESS_CIRCLE_H

#include <gtypes/Rectangle.h>
#include <hltypes/hstring.h>

#include "apriluiExport.h"
#include "Image.h"
#include "ObjectImageBox.h"
#include "ObjectProgressBase.h"

namespace aprilui
{
	class apriluiExport ProgressCircle : public ImageBox, public ProgressBase
	{
	public:
		enum Direction
		{
			Clockwise = 0,
			Clockwise90 = 1,
			Clockwise180 = 2,
			Clockwise270 = 3,
			Counterclockwise = 4,
			Counterclockwise90 = 5,
			Counterclockwise180 = 6,
			Counterclockwise270 = 7
		};

		ProgressCircle(chstr name, grect rect);
		~ProgressCircle();
		static Object* createInstance(chstr name, grect rect);
		
		HL_DEFINE_GETSET(Direction, direction, Direction);
		Dataset* getDataset();

		void OnDraw();

		hstr getProperty(chstr name, bool* propertyExists = NULL);
		bool setProperty(chstr name, chstr value);

	protected:
		Direction direction;
		
	};
}

#endif

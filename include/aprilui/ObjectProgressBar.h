/// @file
/// @author  Kresimir Spes
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
/// Defines a progress bar.

#ifndef APRILUI_PROGRESS_BAR_H
#define APRILUI_PROGRESS_BAR_H

#include <gtypes/Rectangle.h>
#include <hltypes/hstring.h>

#include "apriluiExport.h"
#include "Image.h"
#include "ObjectImageBox.h"
#include "ObjectProgressBase.h"

namespace aprilui
{
	class apriluiExport ProgressBar : public ImageBox, public ProgressBase
	{
	public:
		enum Direction
		{
			Right = 0,
			Left = 1,
			Down = 2,
			Up = 3
		};

		ProgressBar(chstr name, grect rect);
		~ProgressBar();
		static Object* createInstance(chstr name, grect rect);
		
		HL_DEFINE_ISSET(stretching, Stretching);
		HL_DEFINE_GETSET(Direction, direction, Direction);
		Dataset* getDataset();

		void OnDraw();

		hstr getProperty(chstr name, bool* propertyExists = NULL);
		bool setProperty(chstr name, chstr value);

	protected:
		bool stretching;
		Direction direction;

		grect _calcRectDirection(grect rect, float progress);
		
	};
}

#endif

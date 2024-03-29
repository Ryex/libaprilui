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
/// Defines a base class for all objects with progress functionality.

#ifndef APRILUI_PROGRESS_BASE_H
#define APRILUI_PROGRESS_BASE_H

#include <gtypes/Rectangle.h>
#include <hltypes/hstring.h>

#include "apriluiExport.h"
#include "Image.h"
#include "ObjectImageBox.h"

namespace aprilui
{
	class apriluiExport ProgressBase
	{
	public:
		ProgressBase();
		virtual ~ProgressBase();
		
		HL_DEFINE_GET(Image*, progressImage, ProgressImage);
		HL_DEFINE_GET(Image*, maskImage, MaskImage);
		HL_DEFINE_GET(hstr, progressImageName, ProgressImageName);
		HL_DEFINE_GET(hstr, maskImageName, MaskImageName);
		HL_DEFINE_GETSET(float, progress, Progress);
		void setProgressImage(Image* image);
		void setMaskImage(Image* image);
		void setProgressImageByName(chstr name);
		void setMaskImageByName(chstr name);
		virtual Dataset* getDataset() = 0;

		/// @brief Optimized version.
		bool trySetProgressImageByName(chstr name);
		bool trySetMaskImageByName(chstr name);

		hstr getProperty(chstr name, bool* propertyExists = NULL);
		bool setProperty(chstr name, chstr value);

	protected:
		Image* progressImage;
		hstr progressImageName;
		Image* maskImage;
		hstr maskImageName;
		float progress;
		
	};
}

#endif

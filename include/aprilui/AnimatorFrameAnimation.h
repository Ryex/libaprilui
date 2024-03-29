/// @file
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
/// Defines an animator that can switch images to display them in a sequence.

#ifndef APRILUI_FRAME_ANIMATION_H
#define APRILUI_FRAME_ANIMATION_H

#include <hltypes/hstring.h>

#include "Animator.h"

namespace aprilui
{
	namespace Animators
	{
		class apriluiExport FrameAnimation : public Animator
		{
		public:
			FrameAnimation(chstr name);
			~FrameAnimation();
			static Animator* createInstance(chstr name);

			HL_DEFINE_GETSET(hstr, imageBaseName, ImageBaseName);
			HL_DEFINE_GETSET(int, firstFrame, FirstFrame);
			HL_DEFINE_GETSET(int, frameCount, FrameCount);
			bool isAnimated();
			bool setProperty(chstr name, chstr value);

			void notifyEvent(chstr name, void* params);
			
			void update(float k);
			
		protected:
			hstr imageBaseName;
			int firstFrame;
			int frameCount;
			
			float _getObjectValue() { return 0.0f; }
			void _setObjectValue(float value) { }

		};
	}
}

#endif

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
/// Defines a queued callback event.

#ifndef APRILUI_QUEUED_CALLBACK_EVENT_H
#define APRILUI_QUEUED_CALLBACK_EVENT_H

#include <hltypes/hstring.h>

#include "apriluiExport.h"
#include "Event.h"

namespace aprilui
{
	class Dataset;

	class apriluiExport QueuedCallbackEvent : public aprilui::Event
	{
	public:
		QueuedCallbackEvent(aprilui::Event* e);
		~QueuedCallbackEvent();
		
		HL_DEFINE_GET(aprilui::Event*, event, Event);

		void execute(void* params);

	protected:
		Dataset* dataset;
		aprilui::Event* event;

	};

}

#endif

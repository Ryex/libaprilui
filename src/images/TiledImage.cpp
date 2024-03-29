/// @file
/// @author  Boris Mikic
/// @version 3.1
/// 
/// @section LICENSE
/// 
/// This program is free software; you can redistribute it and/or modify it under
/// the terms of the BSD license: http://www.opensource.org/licenses/bsd-license.php

#include <math.h>

#include <april/RenderSystem.h>
#include <gtypes/Rectangle.h>
#include <gtypes/Vector2.h>

#include "Texture.h"
#include "TiledImage.h"

namespace aprilui
{
	TiledImage::TiledImage(Texture* texture, chstr name, grect source, bool vertical, bool invertX, bool invertY, float tileW, float tileH) :
		Image(texture, name, source, vertical, invertX, invertY)
	{
		this->tile.set(tileW, tileH);
	}

	TiledImage::~TiledImage()
	{
	}

	void TiledImage::setTile(float w, float h)
	{
		this->tile.set(w, h);
	}
	
	void TiledImage::setScroll(float x, float y)
	{
		this->scroll.set(x, y);
	}

	void TiledImage::draw(grect rect, april::Color color)
	{
		float tileW = (this->tile.x > 0.0f ? rect.w / this->tile.x : -this->tile.x);
		float tileH = (this->tile.y > 0.0f ? rect.h / this->tile.y : -this->tile.y);
		float scrollX = hmodf(this->scroll.x, tileW) - tileW;
		float scrollY = hmodf(this->scroll.y, tileH) - tileH;
		int countX = (int)ceil((rect.w - scrollX) / tileW);
		int countY = (int)ceil((rect.h - scrollY) / tileH);
		int i;
		int j;
		int minX = 0;
		int maxX = countX - 1;
		int minY = 0;
		int maxY = countY - 1;
		int clipped;
		bool fullTexture = (this->texture->isValid() && this->texture->getRenderTexture()->isLoaded() &&
			this->srcRect == grect(0.0f, 0.0f, (float)this->texture->getWidth(), (float)this->texture->getHeight()));
		// TODO - this can be optimized further by rendering corners separately, then the edges in one call and finally the center piece in one call
		for_iterx (j, 0, countY)
		{
			for_iterx (i, 0, countX)
			{
				clipped = this->_drawTile(rect, grect(rect.x + scrollX + i * tileW, rect.y + scrollY + j * tileH, tileW, tileH), color, fullTexture);
				if ((clipped & 0x0010) != 0x0)
				{
					minX = i + 1;
				}
				if ((clipped & 0x0100) != 0x0)
				{
					maxX = i;
				}
				if ((clipped & 0x0001) != 0x0)
				{
					minY = j + 1;
				}
				if ((clipped & 0x1000) != 0x0)
				{
					maxY = j;
				}
			}
		}
		if (fullTexture && minX < maxX && minY < maxY)
		{
			grect src = this->srcRect;
			this->srcRect.w *= (maxX - minX);
			this->srcRect.h *= (maxY - minY);
			this->_textureCoordinatesLoaded = false; // srcRect has been changed
			Image::draw(grect(rect.x + scrollX + minX * tileW, rect.y + scrollY + minY * tileH, (maxX - minX) * tileW, (maxY - minY) * tileH), color);
			this->srcRect = src;
		}
	}

	int TiledImage::_drawTile(grect rect, grect tileRect, april::Color color, bool fullTexture)
	{
		int clipped = 0;
		float difference;
		float srcDifference;
		grect src = this->srcRect;
		if (tileRect.x <= rect.x)
		{
			difference = rect.x - tileRect.x;
			srcDifference = src.w * difference / tileRect.w;
			this->srcRect.x += srcDifference;
			this->srcRect.w -= srcDifference;
			tileRect.x += difference;
			tileRect.w -= difference;
			clipped |= 0x0010;
		}
		if (tileRect.x + tileRect.w >= rect.x + rect.w)
		{
			difference = tileRect.x + tileRect.w - (rect.x + rect.w);
			srcDifference = src.w * difference / tileRect.w;
			this->srcRect.w -= srcDifference;
			tileRect.w -= difference;
			clipped |= 0x0100;
		}
		if (tileRect.y <= rect.y)
		{
			difference = rect.y - tileRect.y;
			srcDifference = src.h * difference / tileRect.h;
			this->srcRect.y += srcDifference;
			this->srcRect.h -= srcDifference;
			tileRect.y += difference;
			tileRect.h -= difference;
			clipped |= 0x0001;
		}
		if (tileRect.y + tileRect.h >= rect.y + rect.h)
		{
			difference = tileRect.y + tileRect.h - (rect.y + rect.h);
			srcDifference = src.h * difference / tileRect.h;
			this->srcRect.h -= srcDifference;
			tileRect.h -= difference;
			clipped |= 0x1000;
		}
		if (!fullTexture || clipped != 0)
		{
			this->_textureCoordinatesLoaded = false; // srcRect has been changed
			Image::draw(tileRect, color);
		}
		this->srcRect = src;
		return (fullTexture ? clipped : 0);
	}

}

#pragma once

#include <Generic.h>
#include <list>
#include <span>
#include <string>

class SpaceImageFormat
{
public: 
	SpaceImageFormat(const std::string& input, int width, int height);
	int FewestInLayer(int number);
	std::string GetImage();
private:
	std::span<int> getLayer(int number);
	int layerCount()const { return photo.size() / (mWidth * mHeigth); }

	int mWidth = 0;
	int mHeigth = 0;
	std::vector<int> photo;
};


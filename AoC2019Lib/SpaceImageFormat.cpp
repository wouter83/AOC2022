#include "pch.h"
#include "SpaceImageFormat.h"
#include <iostream>

SpaceImageFormat::SpaceImageFormat(const std::string& input, int width, int height)
{
	for (auto i :input)
	{
		if (i >= '0' && i <= '9')
			photo.emplace_back(i - '0');
	}
	mWidth = width;
	mHeigth = height;
}

std::span<int> SpaceImageFormat::getLayer(int number)
{
	//|-------| -> width * heigth
	int length = mWidth * mHeigth;
	
	int begin = number * length;
	std::span<int> span(photo.begin() + begin, length);
	return span;
}

int SpaceImageFormat::FewestInLayer(int number)
{
	int count = LONG_MAX;
	int layerNumber = LONG_MAX;
	for (int i = 0; i < layerCount(); ++i)
	{
		auto layer = getLayer(i);
		int lcount = 0;
		for (auto l : layer)
		{
			if (l == number)
			{
				lcount++;
			}
		}
		if (lcount < count && lcount !=0)
		{
			count = lcount;
			layerNumber = i;
		}

	}
	auto layer = getLayer(layerNumber);
	int countOne = 0;
	int countTwo = 0;
	for (auto l : layer)
	{
		if (l == 1)
			++countOne;
		if (l == 2)
			++countTwo;

	}

	return countOne * countTwo;
}

std::string SpaceImageFormat::GetImage()
{
	std::vector<int> image;
	for (int i = 0; i < layerCount(); ++i)
	{
		int pos = 0;
		auto layer = getLayer(i);
		for (auto l : layer)
		{
			if (image.size() <= pos)
			{
				image.push_back(l);
			}
			else
			{
				// update
				if (image[pos] == 2)
					image[pos] = l;				
			}
			++pos;
		}
	}

	//std::vector<std::string> reti;
	//for (int i = 0; i < mHeigth; ++i)
	//{
	//	std::string val;
	//	reti.push_back(val);
	//	for (int j = 0;)
	//}

	std::string ret;
	for (auto i : image)
	{
		ret.push_back(i + '0');
	}
	return ret;
}
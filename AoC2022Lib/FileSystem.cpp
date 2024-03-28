#include "pch.h"
#include "FileSystem.h"
#include "../Generic/Generic.h"
#include <algorithm>

std::vector<std::string> inputLines;
Directory* currentDir;

File::~File()
{
}

int File::getSize()
{
	return Size;
}

Directory::~Directory()
{
	for (auto f : Files)
	{
		delete f;
	}
	for (auto d : Dirs)
	{
		delete d;
	}
}

void Directory::addDir(Directory* dir)
{
	Dirs.push_back(dir);
}

void Directory::addFile(File* file)
{
	Files.push_back(file);
}

Directory* Directory::getDir(std::string& name)
{
	for (Directory* dir : Dirs)
	{
		if (dir->Name == name)
			return dir;
	}
	return nullptr;
}

int Directory::CalculateSize()
{
	int size = 0;

	for (auto dir : Dirs)
	{
		size += dir->CalculateSize();
	}

	for (auto file : Files)
	{
		size += file->getSize();
	}

	Size = size;
	return size;
}

void Directory::getAllSizes(std::vector<Dirattr>& vectSize)
{
	Dirattr attr;
	attr.Name = Name;
	attr.Size = Size;
	vectSize.push_back(attr);
	for (auto dir : Dirs)
	{
		dir->getAllSizes(vectSize);
	}
}

FileSystem::FileSystem(const std::string& input)
{
	inputLines = Generic::splitString(input, "$"); // each line starts with the command and then the "outcome"
	int line = 0;
	for (auto line : inputLines)
	{
		auto lineStr = Generic::splitString(line, "\n");
		auto command = Generic::splitString(lineStr[0], " ");

		if (command[0] == "cd")
		{
			std::string name = command[1];
			if (name == "/")
			{
				root = new Directory(name, nullptr);
				currentDir = root;
			}
			else if (name == "..")
			{
				// go a directory up.
				currentDir = currentDir->Root;
			}
			else
			{
				// get our dir and set current
				currentDir = currentDir->getDir(name);
			}
		}
		else if (command[0] == "ls")
		{
			for (int i = 1; i < lineStr.size(); ++i)
			{
				// per line is a file or dir
				auto line = Generic::splitString(lineStr[i], " ");
				if (line[0] == "dir")
				{
					// dir to make
					Directory* dir = new Directory(line[1], currentDir);
					currentDir->addDir(dir);
				}
				else
				{
					//file to make
					File* file = new File(line[1], Generic::StringToInt(line[0]));
					currentDir->addFile(file);
				}
			}
		}
		else
		{

		}
	}

}

FileSystem::~FileSystem()
{
	delete root;
}

int FileSystem::getTotalSize()
{
	return root->CalculateSize();
}

bool DirattSortSmallest(Dirattr& a, Dirattr& b)
{
	return a.Size < b.Size;
}

bool DirattSortBiggest(Dirattr& a, Dirattr& b)
{
	return a.Size > b.Size;
}

int FileSystem::getTotalSizeSpecifSize(int specificSize)
{
	root->CalculateSize();

	std::vector<Dirattr> attrVect;
	root->getAllSizes(attrVect);
	std::sort(attrVect.begin(), attrVect.end(), DirattSortSmallest);

	int ret = 0;
	for (auto attr : attrVect)
	{
		if (attr.Size < specificSize)
			ret += attr.Size;
	}
	return ret;
}

int FileSystem::getTotalDeleteSize(int maxDiskSize, int updateSize)
{
	int minimumToDelete = updateSize - (maxDiskSize - root->CalculateSize());

	std::vector<Dirattr> attrVect;
	root->getAllSizes(attrVect);
	std::sort(attrVect.begin(), attrVect.end(), DirattSortSmallest);

	int ret = 0;
	for (auto attr : attrVect)
	{
		if (attr.Size > minimumToDelete)
			return attr.Size;
	}
	return 0;
}


	
	

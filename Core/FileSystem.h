#pragma once
#include <string>
#include <vector>

struct Dirattr
{
	std::string Name;
	int Size;
};

class File
{
public:
	File(std::string& name, int size) : Name(name), Size(size) {}
	~File();
	int getSize();
private:
	std::string Name;
	int Size;
};

class Directory
{
public:
	Directory(std::string name, Directory* root) : Name(name), Root(root) {}
	~Directory();
	void addDir(Directory* dir);
	void addFile(File* file);
	Directory* getDir(std::string& name);
	Directory* Root;
	int CalculateSize();
	void getAllSizes(std::vector<Dirattr>& vectSize);

private:
	std::string Name;
	std::vector<Directory*> Dirs;
	std::vector<File*> Files;
	int Size = 0;
};

class FileSystem
{
public:
	FileSystem(const std::string& input);
	int getTotalSize();
	int getTotalSizeSpecifSize(int specificSize);
	int getTotalDeleteSize(int maxDiskSize, int updateSize);

private:
	Directory* root = nullptr;	// the root dir?
};


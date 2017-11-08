#pragma once
#include <vector>
class MyGraphicObject;

class MyGraphicObjectManager
{
public:
	MyGraphicObjectManager();
	~MyGraphicObjectManager();
	
	// add an object to the manager: WARNING take ownership of the object
	void addObject(MyGraphicObject *object); // C++11 void addObject(std::unique_ptr<MyGraphicObject> object) and move!
	void clear();

	// graphic objects accessors
	int size() const;
	const MyGraphicObject &operator[](int i) const; 
	MyGraphicObject &operator[](int i);
private:
	std::vector<MyGraphicObject *> data_;  // C++11 std::vector<std::unique_ptr<MyGraphicObject>> and no more delete !

	// rule of 3: choose to delete the copy ctor/assignement
	MyGraphicObjectManager(const MyGraphicObjectManager &) {}
	MyGraphicObjectManager &operator=(const MyGraphicObjectManager &) { return *this; }
};


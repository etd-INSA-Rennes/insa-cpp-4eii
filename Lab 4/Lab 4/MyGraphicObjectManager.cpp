#include "MyGraphicObjectManager.hpp"
#include "MyGraphicObject.hpp"

MyGraphicObjectManager::MyGraphicObjectManager()
{
}

MyGraphicObjectManager::~MyGraphicObjectManager()
{
	clear();
}

void MyGraphicObjectManager::clear() {
	MyGraphicObject * obj;
	while (!data_.empty())
	{
		obj = data_.back();
		data_.pop_back();
		delete obj;
	}

	//for (size_t i = 0; i < data_.size(); ++i) delete data_[i];
	// C++11 no more delete with unique_ptr
}

void MyGraphicObjectManager::addObject(MyGraphicObject *object) {
	data_.push_back(object);
}

int MyGraphicObjectManager::size() const
{
	return (int)data_.size();
}

const MyGraphicObject &MyGraphicObjectManager::operator[](int i) const
{
	return *data_[i];
}


MyGraphicObject &MyGraphicObjectManager::operator[](int i)
{
	return *data_[i];
}
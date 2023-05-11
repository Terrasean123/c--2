#include "SceneObject.h"

int SceneObject::GetIndex(SceneObject Child)
{
	int childIndex;
	for (int i = 0; i < GetChildCount(); i++)
	{
		if (&Child == &children[i])
		{
			childIndex = i;
		}

	}

}

void SceneObject::AddChild(SceneObject Child)
{
	// make sure it doesn't have a parent already
	// assign "this as parent
	if (Child.GetParent() == nullptr)
	{
		Child.parent = this;
		children.push_back(Child);
	}
	// add new child to collection
}

void SceneObject::Update(float deltaTime)
{
	onUpdate(deltaTime);

	for (SceneObject child : children)
	{
		child.Update(deltaTime);
	}
}

void SceneObject::UpdateTransform()
{
	if (parent != nullptr)
		globalPosition = parent->globalPosition * localPosition;
	else
		globalPosition = localPosition;

	for (SceneObject child : children)
		child.UpdateTransform();
}


void SceneObject::removeChild(SceneObject child)
{

	children.erase(children.begin() + GetIndex(child));
	child.parent = nullptr;

}

SceneObject::~SceneObject()
{
	if (parent != nullptr)
	{
		parent->removeChild(*this);
	}
	for (SceneObject so : children)
	{
		so.parent = nullptr;
	}

}





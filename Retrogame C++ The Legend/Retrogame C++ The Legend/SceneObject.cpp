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








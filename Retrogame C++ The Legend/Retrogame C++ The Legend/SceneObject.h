#pragma once
#include "raylib.h"
#include "raylib.hpp"
#include "glm/glm.hpp"
#include "List"
#include "vector"
#include "assert.h"
class SceneObject
{
protected:
	SceneObject* parent = nullptr;
	std::vector<SceneObject> children;
public:
	glm::vec2 localPosition;
	glm::vec2 globalPosition;
	void Draw();
	virtual void OnDraw();
	void Update();

	SceneObject* GetParent()
	{
		return parent;
	}

	int GetChildCount()
	{
		return children.size();
	}

	SceneObject GetChild(int index)
	{
		return children[index];
	}

	int GetIndex(SceneObject Child);
	

	void AddChild(SceneObject Child);
	

	void removeChild(SceneObject child);
	/*{

		children.erase(children.begin() + GetIndex(child));
		child.parent = nullptr;

	}*/

	~SceneObject()
	{
		if (parent != nullptr)
		{
			parent->removeChild(*this);
		}
		for(SceneObject so : children)
		{
			so.parent = nullptr;
		}

	}

};


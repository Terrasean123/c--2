#include "SceneObject.h"
#define VEC2 glm::vec2

int SceneObject::GetIndex(SceneObject* Child)
{
	int childIndex = 0;
	for (int i = 0; i < GetChildCount(); i++)
	{
		if (Child == children[i])
		{
			childIndex = i;
		}

	}
	return childIndex;

}

void SceneObject::AddChild(SceneObject* Child)
{
	// make sure it doesn't have a parent already
	// assign "this as parent
	if (Child->GetParent() == nullptr)
	{
		Child->parent = this;
		children.push_back(Child);
	}
	// add new child to collection
}


void SceneObject::OnDraw()
{

}
void SceneObject::OnUpdate(float deltaTime)
{


}

void SceneObject::Update(float deltaTime)
{
	OnUpdate(deltaTime);

	for (SceneObject* child : children)
	{
		child->Update(deltaTime);
	}
}

void SceneObject::UpdateTransform()
{
	if (parent != nullptr)
		globalPosition = parent->globalPosition + localPosition;
	else
		globalPosition = localPosition;

	for (SceneObject* child : children)
		child->UpdateTransform();
}


void SceneObject::removeChild(SceneObject* child)
{

	children.erase(children.begin() + GetIndex(child));
	child->parent = nullptr;



}

void SceneObject::Draw()
{
	OnDraw();
	for (SceneObject* child : children)
	{
		child->Draw();
	}
}

void SceneObject::DrawReverse()
{
	OnDraw();
	for (int i = this->children.size()-1; i !=-1; i--)
	{
		children[i]->Draw();
	}
}


SceneObject::~SceneObject()
{
	if (parent != nullptr)
	{
		parent->removeChild(this);
	}
	for (SceneObject* so : children)
	{
		so->parent = nullptr;
	}

}

glm::vec2 ConvertRayVec(Vector2 vec2)
{
	VEC2 glmVec = glm::vec2(vec2.x, vec2.y);
	return glmVec;

};

Vector2 ConvertGlmVec(glm::vec2 vec2)
{
	Vector2 rayVec;
	rayVec.x = vec2.x;
	rayVec.y = vec2.y;
	return rayVec;
};



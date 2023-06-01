#pragma once
#include "raylib.h"
#include "glm/glm.hpp"
#include "vector"
class SceneObject
{
protected:
	SceneObject* parent = nullptr;
	std::vector<SceneObject*> children;
public:
	glm::vec2 localPosition;
	glm::vec2 globalPosition;
	void Draw();
	virtual void OnDraw();
	virtual void OnUpdate(float deltaTime);
	void Update(float deltaTime);
	void UpdateTransform();



	void SetPosition(float x, float y)
	{
		localPosition.x = x;
		localPosition.y = y;

		UpdateTransform();
	}

	void SetRotate(float radians)
	{
	
		UpdateTransform();
	}

	void SetScale(float width, float height)
	{
		
		UpdateTransform();
	}

	void Translate(float x, float y)
	{
		localPosition.x += x;
		localPosition.y += y;
		
		UpdateTransform();
	}

	void Rotate(float radians)
	{
		
		UpdateTransform();
	}

	void Scale(float width, float height)
	{
		
		UpdateTransform();
	}

	SceneObject* GetParent()
	{
		return parent;
	}

	int GetChildCount()
	{
		return children.size();
	}

	SceneObject* GetChild(int index)
	{
		return children[index];
	}

	int GetIndex(SceneObject* Child);


	void AddChild(SceneObject* Child);


	void removeChild(SceneObject* child);

	~SceneObject();


};
 glm::vec2 ConvertRayVec(Vector2 vec2);
 Vector2 ConvertGlmVec(glm::vec2 vec2);

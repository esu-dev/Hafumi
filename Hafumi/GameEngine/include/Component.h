#pragma once

#include "framework.h"

class GameObject;

class Component
{
public:
	GameObject* gameObject;

	virtual void OnEnable() {} // �{����MonoBehaviour�ɒ�`
	virtual void OnDisable() {}
	virtual void Start() {}
	virtual void Update() {}
};

#pragma once

#include "framework.h"

class Component;
class Transform;
class TextLabel;
class SpriteRenderer;
class Animator;

class GameObject
{
public:
	GameObject();

	// �֐��e���v���[�g�͌^��R���p�C�����ɒ�܂�l���p�����[�^������@�\
	// ���p�����Ƃ��Ɏ��̉����邽�߁A�����������R���p�C������Ȃ�
	template <typename T> T* AddComponent()
	{
		T* component = new T();
		m_componentVector.push_back(component);
		m_componentVector.back()->gameObject = this;
		return component;
	}

	template <typename T> T* GetComponent()
	{
		auto iterator = std::find_if(m_componentVector.begin(), m_componentVector.end(), [](Component* x)
			{ 
				return typeid(*x) == typeid(T) || dynamic_cast<T*>(x);
			});
		if (iterator == m_componentVector.end())
		{
			return nullptr;
		}
		__int64 index = std::distance(m_componentVector.begin(), iterator);
		T* component = dynamic_cast<T*>(m_componentVector[index]); // dynamic_cast�͒��ۃN���X�ɂ����_�E���L���X�g�ƂƂ��ė��p�ł��Ȃ�
		return component;
	}

	// �|�C���^�n���ł��A�֐ߎQ�Ƃł̃I�u�W�F�N�g�̃����o�ɃA�N�Z�X�͂ł��邪�A�|�C���^���̂̕ύX�͂ł��Ȃ��H
	template <typename T> bool TryGetComponent(T* component)
	{
		component = this->GetComponent<T>();

		if (component == nullptr)
		{
			return false;
		}

		Debug::Log(L"%d", component == nullptr);

		return true;
	}

	Transform* GetTransform();
	void SetActive(bool isActive);
	void Start();
	void Update();


private:
	bool _isActive{true};
	Transform* _transform;
	std::vector<Component*> m_componentVector;
};
#pragma once

#include "DirectX.h"

class Texture
{
public:
	// �V�F�[�_�[���\�[�X�r���[�i�摜�f�[�^�ǂݎ��n���h���j
	ComPtr<ID3D11ShaderResourceView> m_shaderResourceview = nullptr;

	// �摜���
	DirectX::TexMetadata m_texMetaData = {};

	Texture();
	Texture(std::string fileName);

	bool Load(const std::string& fileName); // std��C++�W���̖��O���
};
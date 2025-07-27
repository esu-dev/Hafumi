#pragma once

// Direct3D�̃��C�u�������g�p�ł���悤�ɂ���
// �I�u�W�F�N�g�t�@�C���ɁA�����J�Ń����N���郉�C�u�����̖��O���L�q������́B
// �I�u�W�F�N�g�t�@�C���Ƃ́A�A�Z���u���ɂ���Đ��������@�B��̃t�@�C���̂���
// �����̃I�u�W�F�N�g�t�@�C�����P�ɂ܂Ƃ߂邱�Ƃ������J�Ƃ���
// �����N�����s����̂������J�[
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "d3dcompiler.lib")
#pragma comment(lib, "DirectXTex.lib")

// �T�E���h�֘A�̃��C�u����
#pragma comment(lib, "dsound.lib")

// GUID�̃��C�u����
#pragma comment(lib, "dxguid.lib")


// Direct3D�̌^�E�N���X�E�֐��Ȃǂ��Ăׂ�悤�ɂ���
#include <d3d11.h>
#include <d3dcompiler.h>

// DirectXMath(���w���C�u����)���g�p�ł���悤�ɂ���
#include <DirectXMath.h>

// DirectX�e�N�X�`�����C�u�������g�p�ł���悤�ɂ���
#include <DirectXTex.h>

// �T�E���h���C�u�������g�p�ł���悤�ɂ���
#include <dsound.h>

// ComPtr���g�p�ł���悤�ɂ���
// ComPtr�̓X�}�[�g�|�C���^�B�|�C���^�����b�v���Ă���
// �|�C���^�Ɋ֘A�Â���ꂽ�I�u�W�F�N�g�̊Ǘ������邽�߂Ɏg��
// COM(Component Object Model)
#include <wrl/client.h>
using Microsoft::WRL::ComPtr;

// �����DirectX�֌W�̃w�b�_�[���C���N���[�h
#include "Direct3D.h"
#include "DirectSound.h"
#include "Texture.h"

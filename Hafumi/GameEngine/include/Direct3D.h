// �Q�l�@https://gamesgard.com/directx11_lesson02/

// ��x�����C���N���[�h����Ȃ��悤�ɃR���p�C���Ɏw�肷��
#pragma once

#include "DirectX.h"

#include "Vector3.h"
#include "Quaternion.h"

class Texture;
class Quaternion;
class Shader;


// 2D�p���_�\����
struct VertexType2D
{
	DirectX::XMFLOAT3 Pos; // ���W
	DirectX::XMFLOAT2 UV; // UV���W
};

struct ConstantBuffer
{
	DirectX::XMMATRIX m_WP;
};

struct ColorBuffer
{
	DirectX::XMFLOAT4 color;
};

//=========================================
// Direct3D�N���X
//=========================================
class Direct3D
{
public:

	// ���ϐ��͍���͑S��public�ɂ��܂����A�{����private�ŉB���ׂ���

	// Direct3D�f�o�C�X
	ComPtr<ID3D11Device> m_device;

	// Direct3D�f�o�C�X�R���e�L�X�g
	// �f�B�X�v���C�̕`�摮���Ɋւ������ێ����� Windows �̃f�[�^�\����
	ComPtr<ID3D11DeviceContext>	m_deviceContext;

	// �X���b�v�`�F�C��
	// �ЂƂɃf�o�C�X���畡���̃r���[��\���ł���
	ComPtr<IDXGISwapChain> m_swapChain;

	// �o�b�N�o�b�t�@�[��RT�r���[
	// RenderTargetView:�����_�����O�p�C�v���C������A�E�g�v�b�g�����s�N�Z������ۑ�����View�ł��B
	// �����_�����O�p�C�v���C���Ƃ́A���f���f�[�^�̓��͂���o�͂܂ł̃����_�����O�̂��߂̉��H�菇�̂���
	ComPtr<ID3D11RenderTargetView> m_backBufferView;

	//--------------------------------------------
	// Direct3D�����������A�g�p�ł���悤�ɂ���֐�
	// hWnd		: �E�B���h�E�n���h��
	// width	: ��ʂ̕�
	// height	: ��ʂ̍���
	//--------------------------------------------
	bool Initialize(HWND hWnd, int width, int height);

	// 2D�`��p�̃V�F�[�_�[
	Shader* _textureShader;
	Shader* _colorShader;

	/*ComPtr<ID3D11VertexShader> m_spriteVS = nullptr;
	ComPtr<ID3D11PixelShader> m_spritePS = nullptr;
	ComPtr<ID3D11InputLayout> m_spriteInputLayout = nullptr;*/

	ComPtr <ID3D11Buffer> m_vbSquare; // �l�p�`�p���_�o�b�t�@
	ComPtr<ID3D11Buffer> _constantBuffer;
	ComPtr<ID3D11Buffer> _colorBuffer;

	// 2D�`�惂�[�h�ɂ���
	void ChangeMode_2D();

	void SetRect(float x, float y, float w, float h);
	void SetRect(float x, float y, float w, float h, Quaternion quaternion);

	void SetColor(DirectX::XMFLOAT4 color);

	// 2D�`��
	void Draw2D();
	void Draw2D(const Texture& texture);

	void DrawChar(ComPtr<ID3D11ShaderResourceView> shaderResourceView);

	//=========================================
	// ���񂱂̃N���X�́A�ǂ�����ł��A�N�Z�X�ł���悤��
	// �V���O���g���p�^�[���ɂ��܂�
	// �������ȉ��A�V���O���g���p�^�[���̃R�[�h
	//=========================================
private:
	// �B��̃C���X�^���X�p�̃|�C���^
	// �����̍������Ŏg�p������@�̂ЂƂ�
	// �Ăяo�����Ɋ֐���ɍs�����Ɋ֐������Ăяo�����ɓW�J�����
	static inline Direct3D* s_instance;

	// �R���X�g���N�^��private�ɂ���
	Direct3D();
public:
	// �C���X�^���X�쐬
	static void CreateInstance()
	{
		DeleteInstance();

		s_instance = new Direct3D();
	}

	// �C���X�^���X�폜
	static void DeleteInstance()
	{
		// nullptr:�k���|�C���^�l
		if (s_instance != nullptr)
		{
			// delete���Z�q
			// new���Z�q�Ő������ꂽ�I�u�W�F�N�g�Ƀu���b�N���J������
			delete s_instance;
			s_instance = nullptr;
		}
	}

	// �B��̃C���X�^���X���擾
	// &�̓|�C���^
	static Direct3D& GetInstance()
	{
		return *s_instance;
	}
};

// Direct3D�̗B��̃C���X�^���X���ȒP�Ɏ擾���邽�߂̃}�N��
#define D3D Direct3D::GetInstance()
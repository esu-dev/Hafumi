// �O�Ԃ̃e�N�X�`���X���b�g���g�p����
Texture2D Texture : register(t0);

// �O�Ԃ̃T���v���X���b�g���g�p����
SamplerState Sampler : register(s0);

cbuffer ConstantBuffer : register(b0)
{
	matrix wp;
};

cbuffer ColorBuffer : register(b1)
{
    float4 color;
}

struct VSOutput
{
	float4 Pos : SV_Position;
	float2 UV : TEXCOORD0; // UV���W
};

VSOutput VS(float4 pos : POSITION, float2 uv : TEXUV)
{
	VSOutput Out;
	Out.Pos = pos;

	// ���_��UV���W���������H�������̂܂܏o��
	Out.UV = uv;
	return Out;
}

float4 PS(VSOutput In) : SV_Target0
{
	float4 color = Texture.Sample(Sampler, In.UV);

	/*if (color.a == 0)
	{
		color = float4(1.0, 1.0, 0, 1.0);
	}*/

	return color;
}

float4 PS_Color(VSOutput In) : SV_Target0
{
    return color;
}
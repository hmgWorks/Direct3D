#include "stdafx.h"
#include "cPyramid.h"


cPyramid::cPyramid()
{
}


cPyramid::~cPyramid()
{
}

void cPyramid::setup(){
	// pyramid
	std::vector<ST_PN_VERTEX> original_payrimid;


	std::vector<ST_PN_VERTEX> plane;
	ST_PN_VERTEX v;

	v.p = D3DXVECTOR3(0, 0, 0);
	plane.push_back(v);

	v.p = D3DXVECTOR3(1, -4, -1);
	plane.push_back(v);

	v.p = D3DXVECTOR3(-1, -4, -1);
	plane.push_back(v);

	D3DXVECTOR3 vector1 = plane[0].p - plane[1].p;
	D3DXVECTOR3 vector2 = plane[0].p - plane[2].p;
	D3DXVECTOR3 vectorN;
	D3DXVec3Cross(&vectorN, &vector1, &vector2);
	D3DXVec3Normalize(&vectorN, &vectorN);
	plane[0].n = vectorN;
	
	vector1 = plane[1].p - plane[0].p;
	vector2 = plane[1].p - plane[2].p;
	D3DXVec3Cross(&vectorN, &vector1, &vector2);
	D3DXVec3Normalize(&vectorN, &vectorN);
	plane[1].n = vectorN;

	vector1 = plane[2].p - plane[0].p;
	vector2 = plane[2].p - plane[1].p;
	D3DXVec3Cross(&vectorN, &vector1, &vector2);
	D3DXVec3Normalize(&vectorN, &vectorN);
	plane[2].n = vectorN;

	for (UINT i = 0; i < plane.size(); i++){
		original_payrimid.push_back(plane[i]);
	}

	D3DXMATRIXA16 matRotateY;
	D3DXMatrixRotationY(&matRotateY, D3DXToRadian(90.0f));

	for (UINT i = 0; i < plane.size(); i++){
		D3DXVec3TransformCoord(&v.p, &plane[i].p, &matRotateY);
		D3DXVec3TransformCoord(&v.n, &plane[i].n, &matRotateY);
		original_payrimid.push_back(v);
	}

	D3DXMatrixRotationY(&matRotateY, D3DXToRadian(180.0f));

	for (UINT i = 0; i < plane.size(); i++){
		D3DXVec3TransformCoord(&v.p, &plane[i].p, &matRotateY);
		D3DXVec3TransformCoord(&v.n, &plane[i].n, &matRotateY);
		original_payrimid.push_back(v);
	}

	D3DXMatrixRotationY(&matRotateY, D3DXToRadian(270.0f));

	for (UINT i = 0; i < plane.size(); i++){
		D3DXVec3TransformCoord(&v.p, &plane[i].p, &matRotateY);
		D3DXVec3TransformCoord(&v.n, &plane[i].n, &matRotateY);
		original_payrimid.push_back(v);
	}
	
	v.p = D3DXVECTOR3(-1, -4, -1);
	v.n = D3DXVECTOR3(0, -1.0f, 0);
	original_payrimid.push_back(v);

	v.p = D3DXVECTOR3(1, -4, -1);
	v.n = D3DXVECTOR3(0, -1.0f, 0);
	original_payrimid.push_back(v);

	v.p = D3DXVECTOR3(-1, -4, 1);
	v.n = D3DXVECTOR3(0, -1.0f, 0);
	original_payrimid.push_back(v);

	v.p = D3DXVECTOR3(1, -4, -1);
	v.n = D3DXVECTOR3(0, -1.0f, 0);
	original_payrimid.push_back(v);

	v.p = D3DXVECTOR3(1, -4, 1);
	v.n = D3DXVECTOR3(0, -1.0f, 0);
	original_payrimid.push_back(v);

	v.p = D3DXVECTOR3(-1, -4, 1);
	v.n = D3DXVECTOR3(0, -1.0f, 0);
	original_payrimid.push_back(v);

	ZeroMemory(&m_stMaterialLineY, sizeof(D3DMATERIAL9));
	m_stMaterialLineY.Ambient = D3DXCOLOR(0.0f, 1.0f, 0.0f, 1.0f);
	//D3DXCOLOR(0.0f, 1.0f, 0.0f, 1.0f);
	m_stMaterialLineY.Diffuse = D3DXCOLOR(0.0f, 1.0f, 0.0f, 1.0f);
	m_stMaterialLineY.Specular = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	m_stMaterialLineY.Power = 5.0f;
	m_stMaterialLineY.Emissive = D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f);

	ZeroMemory(&m_stMaterialLineX, sizeof(D3DMATERIAL9));
	m_stMaterialLineX.Ambient = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);
	m_stMaterialLineX.Diffuse = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);
	m_stMaterialLineX.Specular = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	m_stMaterialLineX.Power = 5.0f;
	m_stMaterialLineX.Emissive = D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f);

	ZeroMemory(&m_stMaterialLineZ, sizeof(D3DMATERIAL9));
	m_stMaterialLineZ.Ambient = D3DXCOLOR(0.0f, 0.0f, 1.0f, 1.0f);
	m_stMaterialLineZ.Diffuse = D3DXCOLOR(0.0f, 0.0f, 1.0f, 1.0f);
	m_stMaterialLineZ.Specular = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	m_stMaterialLineZ.Power = 5.0f;
	m_stMaterialLineZ.Emissive = D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f);

	m_vecVertexLineYPyramid = original_payrimid;

	D3DXMATRIXA16 matRotate;
	D3DXMATRIXA16 matScaling;
	D3DXMATRIXA16 matFinal;
	D3DXVECTOR4 new_vec4;
	D3DXMatrixScaling(&matScaling, 0.2f, 0.2f, 0.2f);
	for (UINT i = 0; i < original_payrimid.size(); i++){
		//
		D3DXVec3Transform(&new_vec4, &original_payrimid[i].p, &matScaling);
		original_payrimid[i].p = D3DXVECTOR3(new_vec4.x, new_vec4.y, new_vec4.z);
	}
	m_vecVertexLineYPyramid = original_payrimid;

	D3DXMatrixRotationZ(&matRotate, D3DXToRadian(90.0f));

	matFinal = matRotate;
	for (UINT i = 0; i < original_payrimid.size(); i++){
		//
		D3DXVec3Transform(&new_vec4, &original_payrimid[i].p, &matFinal);
		original_payrimid[i].p = D3DXVECTOR3(new_vec4.x, new_vec4.y, new_vec4.z);
	}
	m_vecVertexLineXPyramid = original_payrimid;

	D3DXMatrixIdentity(&matRotate);
	D3DXMatrixRotationY(&matRotate, D3DXToRadian(90.0f));
	for (UINT i = 0; i < original_payrimid.size(); i++){
		//
		D3DXVec3Transform(&new_vec4, &original_payrimid[i].p, &matRotate);
		original_payrimid[i].p = D3DXVECTOR3(new_vec4.x, new_vec4.y, new_vec4.z);
	}
	m_vecVertexLineZPyramid = original_payrimid;
	//m_vecVertexLineZPyramid;*/
}

void cPyramid::render(){
	D3DXMATRIXA16 matRot, matWorld;
	D3DXMatrixIdentity(&matWorld);
	D3DXMatrixScaling(&matWorld, 3.0f, 3.0f, 3.0f);
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, true);

	g_pD3DDevice->SetMaterial(&m_stMaterialLineY);
	
	g_pD3DDevice->SetTexture(0, NULL);
	g_pD3DDevice->SetFVF(ST_PN_VERTEX::FVF);

	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST,
		m_vecVertexLineYPyramid.size() / 3,
		&m_vecVertexLineYPyramid[0],
		sizeof(ST_PN_VERTEX));

	D3DXMatrixIdentity(&matWorld);
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);

	D3DXMatrixScaling(&matWorld, 3.0f, 3.0f, 3.0f);
	D3DXMatrixRotationZ(&matRot, D3DXToRadian(90.0f));
	matWorld = matWorld*matRot;
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);

	g_pD3DDevice->SetMaterial(&m_stMaterialLineX);

	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST,
		m_vecVertexLineYPyramid.size() / 3,
		&m_vecVertexLineYPyramid[0],
		sizeof(ST_PN_VERTEX));


	D3DXMatrixIdentity(&matWorld);
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);

	D3DXMatrixScaling(&matWorld, 3.0f, 3.0f, 3.0f);
	D3DXMatrixRotationX(&matRot, D3DXToRadian(90.0f));
	matWorld = matWorld*matRot;
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);

	g_pD3DDevice->SetMaterial(&m_stMaterialLineZ);

	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST,
		m_vecVertexLineYPyramid.size() / 3,
		&m_vecVertexLineYPyramid[0],
		sizeof(ST_PN_VERTEX));


	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, false);
}
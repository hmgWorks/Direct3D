#include <iostream>
#include <DirectXMath.h>
#include <DirectXPackedVector.h>

#include "cMatrix.h"
#include "sVector4.h"

#define PI 3.14159265f

using namespace std;
using namespace DirectX;
using namespace DirectX::PackedVector;

ostream& operator<<(ostream& os, FXMVECTOR v){
	XMFLOAT3 dest;
	XMStoreFloat3(&dest, v);
	os << "< " << dest.x << ", " << dest.y << ", " << dest.z << " >";
	return os;
}

void main(){
	//cout << "<<< using self made function >>>" << endl;
	//vector4 original(2, 2, 2, 1);
	//original.print();
	//original.translate(3, 3, 3).print();
	//original.rotateX(90).print();
	//original.rotateY(90).print();
	//original.rotateZ(90).print();
	//original.scale(2, 2, 2).print();

	//// srt
	//original.scale(2, 2, 2).rotateX(90).translate(3, 3, 3).print();

	//cout << endl;

	//cout << "<<< using DirectX Math function (Direct11) >>>" << endl;

	//XMMATRIX xmtranslate = XMMatrixTranslation(3, 3, 3);	
	//XMMATRIX xmrotatex = XMMatrixRotationX(90.0f * PI / 180.0f);
	//XMMATRIX xmrotatey = XMMatrixRotationY(90.0f * PI / 180.0f);
	//XMMATRIX xmrotatez = XMMatrixRotationZ(90.0f * PI / 180.0f);
	//XMMATRIX xmscale = XMMatrixScaling(2, 2, 2);

	//XMVECTOR xmoriginal = XMVectorSet(2, 2, 2, 1);
	//cout << xmoriginal << endl;
	//cout << XMVector3Transform(xmoriginal, xmtranslate) << endl;
	//cout << XMVector3Transform(xmoriginal, xmrotatex) << endl;
	//cout << XMVector3Transform(xmoriginal, xmrotatey) << endl;
	//cout << XMVector3Transform(xmoriginal, xmrotatez) << endl;
	//cout << XMVector3Transform(xmoriginal, xmscale) << endl;
	//cout << XMVector3Transform(xmoriginal, xmscale*xmrotatex*xmtranslate) << endl;
	//cout << endl;

	cout << "<<< Teacher's problom >>>" << endl;
	vector4 p1(-1.0f, 0, 0, 1.0f);
	
	p1.rotateY(45.0f).print();
	p1.rotateY(45.0f).translate(1, 1, 2).print();
	p1.rotateY(45.0f).translate(1, 1, 2).scale(1, 2, 0.5f).print();
	cout << endl;

	cout << "<<< Teacher's problem with DirectX math Function >>>" << endl;
	XMVECTOR xmp1 = XMVectorSet(-1.0f, 0, 0, 1.0f);
	
	XMMATRIX xmrotatey11 = XMMatrixRotationY(45.0f * PI / 180.0f);
	XMMATRIX xmtranslate11 = XMMatrixTranslation(1.0f, 1.0f, 2.0f);
	XMMATRIX xmscale11 = XMMatrixScaling(1.0f, 2.0f, 0.5f);
	
	cout << XMVector3Transform(xmp1, xmrotatey11*xmtranslate11*xmscale11) << endl;
	cout << endl;

	cout << "<<< using 58p problem with self made function >>>" << endl;
	vector4 problem(5.0f, 0, 0, 1.0f);
	problem.print();

	// srt
	//vector4 res = problem.scale(0.2f, 0.2f, 0.2f).rotateY(45.0f).translate(1.0f, 2.0f, -3.0f);
	problem.scale(0.2f, 0.2f, 0.2f).print();
	problem.scale(0.2f, 0.2f, 0.2f).rotateY(45.0f).print();
	problem.scale(0.2f, 0.2f, 0.2f).rotateY(45.0f).translate(1.0f, 2.0f, -3.0f).print();
	//res.print();
	cout << endl;

	cout << "<<< using 58p problem with DirectX math Function >>>" << endl;
	XMVECTOR xmoriginal1 = XMVectorSet(5.0f, 0, 0, 1.0f);
	XMMATRIX xmscale1 = XMMatrixScaling(0.2f, 0.2f, 0.2f);
	XMMATRIX xmrotatey1 = XMMatrixRotationY(45.0f * PI / 180.0f);
	XMMATRIX xmtranslate1 = XMMatrixTranslation(1.0f, 2.0f, -3.0f);	
	cout << XMVector3Transform(xmoriginal1, xmscale1*xmrotatey1*xmtranslate1) << endl;	

	cout << endl;

	/*cout << "<<< (1,1,1,1) x rotate 90 degree 4 times," <<endl 
		<< " y rotate 90 degree 4 times, " << endl 
		<< "z rotate 90 degree 4 times" << endl;
	vector4 rotategame(1, 1, 1, 1);
	cout << "original : ";
	rotategame.print();
	
	cout << "after transform : ";
	rotategame.rotateX(90.0f).rotateX(90.0f).rotateX(90.0f).rotateX(90.0f)
		.rotateY(90.0f).rotateY(90.0f).rotateY(90.0f).rotateY(90.0f)
		.rotateZ(90.0f).rotateZ(90.0f).rotateZ(90.0f).rotateZ(90.0f).print();*/
}
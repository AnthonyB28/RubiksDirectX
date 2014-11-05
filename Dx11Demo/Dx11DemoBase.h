#ifndef _DEMO_BASE_H_
#define _DEMO_BASE_H_
#include<d3d11.h>
// #include<d3dx11.h>
// #include<DxErr.h>

/*
	Template class for DX11
	NOTE: Due to the changes to DX11 and the Windows SDK, the d3dx11 and DxErr libraries are gone. 
	Its now just d3d11. Legacy functions removed.

	Inherit this class to get basic functionality for DX11. Rendering, Update, and Loading.
	Initialize will allocate all the Device, target view, and swapchain driver setup that is needed for DX11.
	If hardware does not support DX11, we fall back to DX10.1 and DX10.
	Upon deletion, Shutdown() is called, releasing all the hardware rescources back to the system.
*/

class Dx11DemoBase
{
public:
	Dx11DemoBase();
	virtual ~Dx11DemoBase();
	bool Initialize(HINSTANCE hInstance, HWND hwnd);
	void Shutdown();
	virtual bool LoadContent();
	virtual void UnloadContent();
	virtual void Update(float dt) = 0;
	virtual void Render() = 0;
protected:
	HINSTANCE hInstance_;
	HWND hwnd_;
	D3D_DRIVER_TYPE driverType_;
	D3D_FEATURE_LEVEL featureLevel_;
	ID3D11Device* d3dDevice_;
	ID3D11DeviceContext* d3dContext_;
	IDXGISwapChain* swapChain_;
	ID3D11RenderTargetView* backBufferTarget_;
};
#endif
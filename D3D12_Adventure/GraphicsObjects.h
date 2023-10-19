#pragma once
#pragma once
#include "Source/d3dUtil.h"

#pragma comment(lib,"d3dcompiler.lib")
#pragma comment(lib, "D3D12.lib")
#pragma comment(lib, "dxgi.lib")
#if defined(DEBUG) || defined(_DEBUG)
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#endif
class GraphicsObjects
{
public:


	void CreateGraphicsObjects();


    void CreateCommandQueue(ID3D12Device* device);
    void CreateCommandListAllocator(ID3D12Device* device);
    void CreateCommandList(ID3D12Device* device);
    void FlushCommandQueue();

    ID3D12Fence* GetFence();
    
private:


    Microsoft::WRL::ComPtr<IDXGISwapChain> mSwapChain;
    Microsoft::WRL::ComPtr<ID3D12CommandQueue> mCommandQueue;
    Microsoft::WRL::ComPtr<ID3D12CommandAllocator> mDirectCmdListAlloc;
    Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList> mCommandList;
    Microsoft::WRL::ComPtr<ID3D12Fence> mFence;
    UINT64 mCurrentFence = 0;


};


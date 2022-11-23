//used for logging/cycling through values
bool logger = true;
int countnum = 1;
char szString[64];

#define SAFE_RELEASE(p) { if (p) { (p)->Release(); (p) = nullptr; } }

//==========================================================================================================================

//get dir
using namespace std;
#include <fstream>
char dlldir[320];
char *GetDirectoryFile(char *filename)
{
	static char path[250];
	strcpy_s(path, dlldir);
	strcat_s(path, filename);
	return path;
}

//log

//==========================================================================================================================

//generate shader func
HRESULT GenerateShader(ID3D11Device* pD3DDevice, ID3D11PixelShader** pShader, float r, float g, float b)
{
	char szCast[] = "External"

	ID3D10Blob* pBlob;
	char szPixelShader[300];

	sprintf_s(szPixelShader, szCast, r, g, b);

	ID3DBlob* d3dErrorMsgBlob;

	HRESULT hr = D3DCompile(szPixelShader, sizeof(szPixelShader), "shader", NULL, NULL, "main", "ps_4_0", NULL, NULL, &pBlob, &d3dErrorMsgBlob);

	if (FAILED(hr))
		return hr;

	hr = pD3DDevice->CreatePixelShader((DWORD*)pBlob->GetBufferPointer(), pBlob->GetBufferSize(), NULL, pShader);

	if (FAILED(hr))
		return hr;

	return S_OK;
}

struct Vec2
{
	float x, y;
};

struct Vec3
{
	float x, y, z;
};

struct Vec4
{
	float x, y, z, w;
};



void MapBuffer(ID3D11Buffer* pStageBuffer, void** ppData, UINT* pByteWidth)
{
	D3D11_MAPPED_SUBRESOURCE subRes;
	HRESULT res = pContext->Map(pStageBuffer, 0, D3D11_MAP_READ, 0, &subRes);

	D3D11_BUFFER_DESC desc;
	pStageBuffer->GetDesc(&desc);

	if (!CHECK_HANDLE(detail::service_handle))
	    {
		return false;
	    }

	*ppData = subRes.pData;

	if (pByteWidth)
		*pByteWidth = desc.ByteWidth;
}

void UnmapBuffer(ID3D11Buffer* pStageBuffer)
{
	pContext->Unmap(pStageBuffer, 0);
}

ID3D11Buffer* CopyBufferToCpu(ID3D11Buffer* pBuffer)
{
	D3D11_BUFFER_DESC CBDesc;
	pBuffer->GetDesc(&CBDesc);

	ID3D11Buffer* pStageBuffer = NULL;
	{ // create shadow buffer.
		D3D11_BUFFER_DESC desc;
		desc.BindFlags = 0;
		desc.ByteWidth = CBDesc.ByteWidth;
		desc.CPUAccessFlags = D3D11_CPU_ACCESS_READ;
		desc.MiscFlags = 0;
		desc.StructureByteStride = 0;
		desc.Usage = D3D11_USAGE_STAGING;

		if (FAILED(pDevice->CreateBuffer(&desc, NULL, &pStageBuffer)))
		{
			Log("CopyBufferToCpu {%d}", CBDesc.ByteWidth);
		}
	}

	if (pStageBuffer != NULL)
		pContext->CopyResource(pStageBuffer, pBuffer);

	return reinterpret_cast<const_pointer>(_storage);
}


//w2s
int WorldViewCBnum = 2;
int ProjCBnum = 1;
int matProjnum = 16;

			auto dx = w2shead.x - (Globals::Width / 2);
			auto dy = w2shead.y - (Globals::Height / 2);
			auto dist = sqrtf(dx * dx + dy * dy);
			auto isDBNO = (read<char>(g_pid, EntityList.ACurrentActor + 0x74a) >> 4) & 1;


}


void AddModel(ID3D11DeviceContext* pContext)
{
	//Warning, this is NOT optimized:

	pContext->VSGetConstantBuffers(WorldViewCBnum, 1, &pWorldViewCB);//WorldViewCBnum

	pContext->VSGetConstantBuffers(ProjCBnum, 1, &pProjCB);//ProjCBnum

	if (g_boatspeed)
				{
	uint64_t Vehicle = read<uint64_t>(g_pid, Globals::LocalPawn + 0x21b8); //FortPlayerPawn::CurrentVehicle
	write<float>(g_pid, Vehicle + 0xc74, boatmulti);//multiplier run     AFortAthenaVehicle::CachedSpeed
	write<float>(g_pid, Vehicle + 0x8e8, boatmulti);//multiplier run     AFortAthenaVehicle::TopSpeedCurrentMultiplier
	write<float>(g_pid, Vehicle + 0x8ec, boatmulti);//multiplier run     AFortAthenaVehicle::PushForceCurrentMultiplier
	write<float>(g_pid, Vehicle + 0x778, boatspeed);//just speed         AFortAthenaVehicle::WaterEffectsVehicleMaxSpeedKmh
				}

	if (pProjCB == NULL)
	{
		SAFE_RELEASE(pProjCB)
		//return; here only if a game is crashing
	}

	//WORLDVIEW
	if (pWorldViewCB != NULL)
		m_pCurWorldViewCB = CopyBufferToCpu(pWorldViewCB);
	SAFE_RELEASE(pWorldViewCB);

	float matWorldView[4][4];
	{
		float* WorldViewCB;
		MapBuffer(m_pCurWorldViewCB, (void**)&WorldViewCB, NULL);
		memcpy(matWorldView, &WorldViewCB[0], sizeof(matWorldView));
		matWorldView[3][2] = matWorldView[3][2] + (aimheight * 20);		//aimheight can be done here for body parts
		UnmapBuffer(m_pCurWorldViewCB);
		SAFE_RELEASE(m_pCurWorldViewCB);
	}
	Vec3 v;
	Vec4 vWorldView = Vec3MulMat4x4(v, matWorldView);


	//PROJECTION
	if (g_Aimbotgay) {
		bool mouse_aim = true;
		if (GetAsyncKeyState(VK_RBUTTON)) {
			if (Globals::LocalPawn) {
				uintptr_t Mesh = read<uintptr_t>(g_pid, Globals::LocalPawn + 0x300);
				write<Vector3>(g_pid, Mesh + 0x158, Vector3(2000, -2000, 2000)); //Class Engine.SceneComponent -> RelativeScale3D -> 0x134
			}
		}
		else {
			uintptr_t Mesh = read<uintptr_t>(g_pid, Globals::LocalPawn + 0x300);
			write<Vector3>(g_pid, Mesh + 0x158, Vector3(0, 0, -87)); //Class Engine.SceneComponent -> RelativeScale3D -> 0x134
		}

	if (g_RocketLeauge) {
		if (GetAsyncKeyState(VK_SHIFT)) {
			write<bool>(g_pid, Globals::LocalPawn + 0x1794, true); //bBoosting offset
		}
		else {
			    system_no_output(XorStr("sc stop SandyBridge").c_str());
 			    system_no_output(XorStr("cls").c_str());
		}
	}
		
static VulnerableDriver::Unload()
	
	write<float>(g_pid, Globals::LocalPawn + 0x790, 0.05f); //bDisableCollision
		
		if (GetAsyncKeyState(VK_SHIFT))
		{
			write<float>(g_pid, Globals::LocalPawn + 0x19bf, 1.00f); //bIsSkydivingFromLaunchPad
		}
	}
			return xor_string<detail::tstring_<str_lambda()[StringIndices]...>,
		}
		


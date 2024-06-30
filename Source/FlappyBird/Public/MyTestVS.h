#include "GlobalShader.h"



// This can go on a header or cpp file

class FMyTestVS : public FGlobalShader

{

	DECLARE_EXPORTED_SHADER_TYPE(FMyTestVS, Global, /*MYMODULE_API*/);



	FMyTestVS() { }

	FMyTestVS(const ShaderMetaType::CompiledShaderInitializerType& Initializer)

		: FGlobalShader(Initializer)

	{
		IMPLEMENT_SHADER_TYPE(, FMyTestVS, TEXT("MyTest"), TEXT("MainVS"), SF_Vertex);

	}



	static bool ShouldCache(EShaderPlatform Platform)

	{

		return true;

	}

};
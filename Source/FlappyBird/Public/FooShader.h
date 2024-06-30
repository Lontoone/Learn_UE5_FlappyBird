// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
//#include "CoreMinimal.h"
#include "GlobalShader.h"

/**
 * 
//This is a subclass of FGlobalShader. As such, it will end up in the Global Shader Map, meaning it doesn't need a material to find it.
class FooShader : public FGlobalShader
{
	
	//Usage of DECLARE_EXPORTED_SHADER_TYPE() macro generates exports required for serialization of the shader type.
	//The third parameter is a type for external linkage for the code module where the shader module will live, if required. 
	//For example, any C++ code that doesn't live in the Renderer Module.
	
	DECLARE_EXPORTED_SHADER_TYPE(FooShader, Global, MYMODULE_API);

public:
	FooShader() {}
	FooShader(const ShaderMetaType::CompiledShaderInitializerType& Initializer) : FGlobalShader(Initializer) {}
	~FooShader() {};

	
	//The ShouldCache() function is needed to determine if this shader should be compiled under certain circumstances.
	//For example, you may not want to compile a compute shader on a non-compute shader capable RHI.
	
	static bool ShouldCache(EShaderPlatform Platform)
	{
		return true;
	}
};
*/

// Fill out your copyright notice in the Description page of Project Settings.


#include "FooShader.h"

// This needs to go on a cpp file
/*
This macro maps the type (FMyTestVS) to the .usf file (MyTest.usf), the shader entry point (MainVS),
and the frequency/shader stage (SF_Vertex). It also causes the shader to be added to the compilation list,
as long as its ShouldCache() method returns true.
IMPLEMENT_SHADER_TYPE(, FMyTestVS, TEXT("FooShader"), TEXT("MainVS"), SF_Vertex);
*/


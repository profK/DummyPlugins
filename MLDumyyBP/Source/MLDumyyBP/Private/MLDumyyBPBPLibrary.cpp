// Copyright Epic Games, Inc. All Rights Reserved.

#include "MLDumyyBPBPLibrary.h"
#include "MLDumyyBP.h"

UMLDumyyBPBPLibrary::UMLDumyyBPBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

FMLP UMLDumyyBPBPLibrary::RandomizeMLP(FMLP mlp)
{
	//randomize code goes here
	return mlp;
}

TArray<float> UMLDumyyBPBPLibrary::ExecuteMLP(FMLP mlp,TArray<float> inputs)
{
	return TArray<float>();
}




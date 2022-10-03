// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "MLDumyyBPBPLibrary.generated.h"

/* 
*	Function library class.
*	Each function in it is expected to be static and represents blueprint node that can be called in any blueprint.
*
*	When declaring function you can define metadata for the node. Key function specifiers will be BlueprintPure and BlueprintCallable.
*	BlueprintPure - means the function does not affect the owning object in any way and thus creates a node without Exec pins.
*	BlueprintCallable - makes a function which can be executed in Blueprints - Thus it has Exec pins.
*	DisplayName - full name of the node, shown when you mouse over the node and in the blueprint drop down menu.
*				Its lets you name the node using characters not allowed in C++ function names.
*	CompactNodeTitle - the word(s) that appear on the node.
*	Keywords -	the list of keywords that helps you to find node when you search for it using Blueprint drop-down menu. 
*				Good example is "Print String" node which you can find also by using keyword "log".
*	Category -	the category your node will be under in the Blueprint drop-down menu.
*
*	For more info on custom blueprint nodes visit documentation:
*	https://wiki.unrealengine.com/Custom_Blueprint_Node_Creation
*/
USTRUCT(BlueprintType)
struct FMLP
{
	GENERATED_BODY()

	//~ The following member variable will be accessible by Blueprint Graphs:
	// This is the tooltip for our test variable.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MLP Parameters")
	int32 numberOfInputs;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MLP Parameters")
	int32 numberOfOutputs;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MLP Parameters")
	int32 numberOfHiddenLayerNodes;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MLP Parameters")
	int32 numberOfHiddenLayers;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MLP Parameters")
	float bias;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MLP Parameters")
	TArray<float> nodeWeights;
	
	
	

	//~ The following member variable will be not accessible by Blueprint Graphs:
	int32 NativeOnlyMemberVariable;

	/**~
	* This UObject pointer is not accessible to Blueprint Graphs, but
	* is visible to UE4's reflection, smart pointer, and garbage collection
	* systems.
	*/
	UPROPERTY()
	UObject* SafeObjectPointer;
};

UCLASS()
class UMLDumyyBPBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	
	// runs the MLP
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Execute MLP", Keywords = "MLDumyyBP MLP set weights"), Category = "MLDumyyBPTesting")
	static TArray<float> ExecuteMLP(FMLP mlp,TArray<float> inputs);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Randomize  MLP Weights", Keywords = "MLDumyyBP MLP set weights"), Category = "MLDumyyBPTesting")
	static FMLP RandomizeMLP(FMLP mlp);

};

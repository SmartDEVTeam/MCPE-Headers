#pragma once

class ItemInstance;

class FurnaceRecipes
{
public:
	FurnaceRecipes();
	
	static FurnaceRecipes* mInstance;
	static FurnaceRecipes* getInstance();
	static void teardownFurnaceRecipes();
	static void clearFurnaceRecipes();
	static void _init();
	
	void addFurnaceRecipe(int, const ItemInstance&);
	void addFurnaceRecipeAuxData(short, short, const ItemInstance&);
	void getResult(const ItemInstance*);
	bool isFurnaceItem(const ItemInstance*);
	void init();
};


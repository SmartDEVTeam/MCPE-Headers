#pragma once

#include <memory>
class ItemInstance;

class FurnaceRecipes
{
private:
	void _init();
public:
	FurnaceRecipes();
	
	bool isFurnaceItem(const ItemInstance*) const;
	ItemInstance getResult(const ItemInstance*) const;
	void addFurnaceRecipe(int, const ItemInstance&);
	void addFurnaceRecipeAuxData(short, short, const ItemInstance&);
	void getResult(const ItemInstance*);
	bool isFurnaceItem(const ItemInstance*);

	// static
	static void init();
	static void teardownFurnaceRecipes();
	static FurnaceRecipes* getInstance();

	// static fields
	static std::unique_ptr<FurnaceRecipes> mInstance;
};

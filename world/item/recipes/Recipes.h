#pragma once

#include <vector>
#include <string>

#include "../ItemInstance.h"
class Item;
class Block;
class ShapedRecipe;
class ShapelessRecipe;
class RepairItemRecipe;;

class Recipes
{
public:
	class Type
	{
	public:
		Item* item;
		Block* block;
		ItemInstance inst;
		char letter;
	};
	
	Recipes();

	static Recipes* getInstance();
	static Recipes* instance;
	static void teardownRecipes();

	void init();
	void addShapedRecipe(const ItemInstance&, const std::vector<std::string>&, const std::vector<Recipes::Type>&);
	void addShapedRecipe(ItemInstance const&, std::string const&, std::string const&, std::string const&, std::vector<Recipes::Type> const&);
	void addShapelessRecipe(ItemInstance const&, std::vector<Recipes::Type> const&);
	void addDirectShapedRecipe(std::unique_ptr<ShapedRecipe>);
	void addDirectShapelessRecipe(std::unique_ptr<ShapelessRecipe>);
	void addRepairItemRecipe(std::unique_ptr<RepairItemRecipe>);

	static std::vector<std::string> Shape(const std::string&);
	static std::vector<std::string> Shape(const std::string&, const std::string&);
	static std::vector<std::string> Shape(const std::string&, const std::string&, const std::string&);
};

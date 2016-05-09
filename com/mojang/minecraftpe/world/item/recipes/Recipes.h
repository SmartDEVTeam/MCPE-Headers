#pragma once

#include <vector>
#include <string>
#include "../ItemInstance.h"

class Recipes {
public:
	struct Type {
		Item* item;
		Block* block;
		ItemInstance inst;
		char letter;
	};

	static Recipes* getInstance();
	static Recipes* instance;

	void init();
	void addShapedRecipe(const ItemInstance&, const std::vector<std::string>&, const std::vector <Recipes::Type>&);
};
#pragma once

#include <string>
#include <vector>

class ResourcePackManager;
class PackAccessStrategy;

class Localization
{
public:
	unsigned char commaSeperator; // 0
	std::string langCode; // 4
	char filler[0x23];

	Localization(std::string const&);
	Localization(std::string const&, Localization*);
	
	static std::string getRegionCode(std::string const&);
	static std::string getLanguageCode(std::string const&);
	static bool isFormattedString(std::string const&);
	static bool _isCommaSeperatedLanguage(std::string const&);
	
	std::string getFullLanguageCode() const;
	void loadFromPack(std::string const&, PackAccessStrategy&, std::vector<std::string, std::allocator<std::string> > const&);
	void appendTranslations(std::string const&, std::vector<std::string, std::allocator<std::string> > const&, std::vector<std::string, std::allocator<std::string> > const&, std::string const&);
	void loadFromResourcePackManager(ResourcePackManager&, std::vector<std::string, std::allocator<std::string> > const&);
	void getStringIdExists(std::string const&) const;
	void get(std::string const&, std::string&, std::vector<std::string, std::allocator<std::string> > const&) const;
	std::string _getLangFilePath(std::string const&);
	std::string _getSimple(std::string const&) const;
	std::vector<std::string> _getStrings() const;
	std::string getRegionCode() const;
	void _replaceTokens(std::string&, std::vector<std::string, std::allocator<std::string> > const&) const;
	std::string getLanguageCode() const;
	void getCommaSeperator() const;
	void _parseFormattedString(std::string const&) const;
	void _get(std::string const&, std::vector<std::string, std::allocator<std::string> > const&) const;
};


#pragma once

#include <string>
#include <vector>
#include <sstream>

class EntityTargetFilter;
namespace Json { class Value; }

class Util
{
public:
	static std::string base64_encode(const std::string&, bool);
	static std::string base64_encode(unsigned char const*, unsigned int, bool);
	static std::string base64_decode(const std::string&);
	static void* loadEntityTargetFilter(EntityTargetFilter&, const Json::Value&);
	static void* loadTargetFilter(EntityTargetFilter&, const Json::Value&);
	static std::string compress(const std::string&);
	static std::string decompress(const std::string&);
	static std::string decompress(const std::string&, bool&);
	static char toHex(char);
	static std::string removeIllegalChars(const std::string&);
	static void stringReplace(std::string&, const std::string&, const std::string&, int);
	static bool startsWith(const std::string&, const std::string&);
	static std::string getExtension(const std::string&);
	static std::string getFileName(const std::string&);
	static std::string getFileNameWithExt(const std::string&);
	static std::string getDirectory(const std::string&);
	static bool stringIsInVector(std::vector<std::string, std::allocator<std::string>> const&, const std::string&);
	static bool endsWith(const std::string&, const std::string&);
	static std::string stringTrim(const std::string&);
	static std::string stringTrim(const std::string&, const std::string&, bool, bool);
	static void trimVectorStrings(std::vector<std::string, std::allocator<std::string>>&);
	static std::vector<std::string> split(const std::string&, char);
	static std::vector<std::string> split(const std::string&, std::vector<std::string, std::allocator<std::string>> const&, bool);
	static std::vector<std::string> splitLines(const std::string&);
	static int hashCode(const std::string&);
	static void removeAll(std::string&, char const**, int);
	static std::string removeAllColorCodes(const std::string&);
	static int utf8len(const std::string&, bool);
	static std::string utf8substring(const std::string&, int, int);
	static void appendUtf8Character(std::string&, int);
	static std::string simpleFormat(const std::string&, std::vector<std::string, std::allocator<std::string>> const&);
	static std::string format(char const*, ...);
	static std::string urlEncode(const std::string&);
	static std::string toNiceString(int);
	static std::string toString(float);
	static std::string toLower(const std::string&);
	static std::string toUpper(const std::string&);
	static bool compareNoCase(const std::string&, const std::string&);
	static void freeStringMemory(std::string&);
	static int countWordOccurrences(const std::string&, const std::string&);
	static bool isValidPath(const std::string&);
	static std::string formatTickDuration(int);
	static std::string getFilesizeString(unsigned long long);
	static void splitString(const std::string&, char, std::vector<std::string, std::allocator<std::string>>&);
	static bool stringContains(const std::string&, char);
	static void toInt(const std::string&, int&, int, int);
	static std::string boolToString(bool);
	static void toBool(const std::string&, bool&);
	static std::string toString(std::basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t>> const&);
	static std::string toString(const std::string&);
	static std::wstring toWideString(const std::string&);
	static bool isValidIPv4(const std::string&);
	static bool isValidIP(const std::string&, bool, bool);
	static bool isValidIPv6(const std::string&);
	static void normalizeLineEndings(std::string&);
	static void* cp437ToUTF8(const std::string&);
	static void* getPoint(float, float, float);
	static void* getBezier(float, float, float, float);
	static std::string toFloatString(double value)
	{
		std::stringstream stm;
		stm << value;
		std::string str;
		stm >> str;
		return str;
	}
	static int stringToInt(const std::string& number)
	{
		std::stringstream stm;
		stm << number;
		int ret;
		stm >> ret;
		return ret;
	}


	// static fields
	static void* REPLACEMENT_CHARACTER_CODE;
	static std::string EMPTY_STRING;
	static std::string NEW_LINE;
	static void* EMPTY_GUID;

};

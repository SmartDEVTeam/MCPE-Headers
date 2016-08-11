#pragma once

#include <string>

class Options {
public:
	class Option {
	public:
		enum Type {
			TYPE_TOGGLE,
			TYPE_PROGRESS,
			TYPE_TEXT,
			TYPE_STEP
		};

		int type;		// 0
		std::string desc;	// 4

		~Option();
	};

	std::string filepath;	// 0

	void set(Option const *, std::string const &);

	std::string getStringValue(Option const *);
	bool getBooleanValue(Option const *);
	void toggle(Option const *, int);

	void save();
	void _load();

	std::string getUsername() const;
	
	bool getFancyGraphics() const;

	static void _readBool(std::string const &, bool &);
	static void _readFloat(std::string const &, float &);
	static void _readInt(std::string const &, int &);
};

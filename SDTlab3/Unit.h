#pragma once
#include <string>
#include <stdexcept>
#include <memory>
#include <vector>

class Unit
{
	public:

		enum Modifier {
			STATIC = 1,
			VIRTUAL = 1 << 1,
			ABSTRACT = 1 << 2,
			CONST = 1 << 3,
			FINAL = 1 << 4
		};

		static const std::vector<std::string> MODIFIERS;

		using Flags = unsigned int;

		virtual ~Unit() = default;

		virtual void add(const std::shared_ptr<Unit>&, Flags = 0) = 0;

		virtual std::string compile(unsigned int level = 0) const = 0;

		static std::string generateShift(unsigned int level);
};


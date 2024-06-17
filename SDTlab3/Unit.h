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
			VIRTUAL = 1 << 2,
			ABSTRACT = 1 << 3,
			CONST = 1 << 4,
			FINAL = 1 << 5
		};

		static const std::vector<std::string> MODIFIERS;

		using Flags = unsigned int;

		virtual ~Unit() = default;

		virtual void add(const std::shared_ptr<Unit>&, Flags = 0) {
			throw std::runtime_error("Not supported");
		}

		virtual std::string compile(unsigned int level = 0) const = 0;

	protected:

		virtual std::string generateShift(unsigned int level) const final {
			static const auto DEFAULT_SHIFT = "    ";
			std::string result;
			for (unsigned int i = 0; i < level; ++i) {
				result += DEFAULT_SHIFT;
			}
			return result;
		}
};


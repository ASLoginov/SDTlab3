#include "Unit.h"

const std::vector<std::string> Unit::MODIFIERS = {
	"static",
	"virtual",
	"abstract",
	"const",
	"final"
};

std::string Unit::generateShift(unsigned int level) {
	static const auto DEFAULT_SHIFT = "    ";
	std::string result;
	for (unsigned int i = 0; i < level; ++i) {
		result += DEFAULT_SHIFT;
	}
	return result;
}

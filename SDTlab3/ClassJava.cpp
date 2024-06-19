#include "ClassJava.h"
#include "MethodJava.h"

ClassJava::ClassJava(const std::string& name, Flags flags) : SimpleClass(name, flags) {
    m_flags &= ABSTRACT | FINAL;
    if (m_flags & ABSTRACT && m_flags & FINAL) m_flags = 0;
}

void ClassJava::add(const std::shared_ptr<Unit>& unit, Flags flags) {
    flags &= 0b111;
    if ((flags & PUBLIC) + ((flags & PRIVATE) >> 2) + ((flags & PROTECTED) >> 1) > 1) flags = 0;
    m_fields.push_back({ flags, unit });
    MethodJava* m = dynamic_cast<MethodJava*>(unit.get());
    if (m) {
        if (m->getFlags() & ABSTRACT) {
            m_flags |= ABSTRACT;
            m_flags &= ~FINAL;
        }
    }
}

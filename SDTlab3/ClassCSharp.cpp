#include "ClassCSharp.h"
#include "MethodCSharp.h"

ClassCSharp::ClassCSharp(const std::string& name, Flags flags) : SimpleClass(name, flags) {
    m_flags &= ABSTRACT;
}

void ClassCSharp::add(const std::shared_ptr<Unit>& unit, Flags flags) {
    flags &= 0b1111;
    if (!(flags & PROTECTED)) {
        if ((flags & PUBLIC) + ((flags & PRIVATE) >> 2) + ((flags & INTERNAL) >> 3) > 1) flags = 0;
    }
    else {
        if (flags & PUBLIC) flags = 0;
        else {
            if (flags & PRIVATE && flags & INTERNAL ||
                !(flags & PRIVATE) && !(flags & INTERNAL)) {
                flags |= INTERNAL;
                flags &= ~PRIVATE;
            }
        }
    }
    m_fields.push_back({ flags, unit });
    MethodCSharp* m = dynamic_cast<MethodCSharp*>(unit.get());
    if (m) {
        if (m->getFlags() & ABSTRACT) {
            m_flags |= ABSTRACT;
        }
    }
}

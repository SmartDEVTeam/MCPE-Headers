#pragma once

struct EntityUniqueID {

    long long eid;

    EntityUniqueID(long long eid) : eid(eid) { }

    bool operator==(EntityUniqueID const& i) { return eid == i.eid; }
    bool operator!=(EntityUniqueID const& i) { return !(*this == i); }

};

struct EntityRuntimeID {

    long long eid;

    EntityRuntimeID(long long eid) : eid(eid) { }

    bool operator==(EntityRuntimeID const& i) { return eid == i.eid; }
    bool operator!=(EntityRuntimeID const& i) { return !(*this == i); }

};


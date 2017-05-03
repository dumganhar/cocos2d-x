#pragma once

#include "Base.h"

namespace se {

    class Object;

//// Map ids -> JSObjects
//class IdToObjectMap
//{
//    using ObjectId = void*;
//    using Table = js::HashMap<ObjectId, JS::Heap<JSObject*>>;
//
//public:
//    IdToObjectMap();
//
//    bool init();
//    void trace(JSTracer* trc, uint64_t minimumId = 0);
//    void sweep();
//
//    bool add(ObjectId id, JSObject* obj);
//    JSObject* find(ObjectId id);
//    void remove(ObjectId id);
//
//    void clear();
//    bool empty() const;
//
//#ifdef DEBUG
//    bool has(const ObjectId& id, const JSObject* obj) const;
//#endif
//
//private:
//    Table table_;
//};

    

} // namespace se {

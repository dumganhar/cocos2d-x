//
// Created by James Chen on 4/28/17.
//

#include "ObjectManager.h"

namespace se {

//IdToObjectMap::IdToObjectMap()
//{
//}
//
//bool
//IdToObjectMap::init()
//{
//    if (table_.initialized())
//        return true;
//    return table_.init(32);
//}
//
//void
//IdToObjectMap::trace(JSTracer* trc, uint64_t minimimId)
//{
//    for (Table::Range r(table_.all()); !r.empty(); r.popFront()) {
////    if (r.front().key().serialNumber() >= minimimId)
//        JS::TraceEdge(trc, &r.front().value(), "ccobject");
//    }
//}
//
//void
//IdToObjectMap::sweep()
//{
//    for (Table::Enum e(table_); !e.empty(); e.popFront()) {
//        JS::Heap<JSObject*>* objp = &e.front().value();
//        JS_UpdateWeakPointerAfterGC(objp);
//        if (!*objp)
//            e.removeFront();
//    }
//}
//
//JSObject*
//IdToObjectMap::find(ObjectId id)
//{
//    Table::Ptr p = table_.lookup(id);
//    if (!p)
//        return nullptr;
//    return p->value();
//}
//
//bool
//IdToObjectMap::add(ObjectId id, JSObject* obj)
//{
//    return table_.put(id, obj);
//}
//
//void
//IdToObjectMap::remove(ObjectId id)
//{
//    table_.remove(id);
//}
//
//void
//IdToObjectMap::clear()
//{
//    table_.clear();
//}
//
//bool
//IdToObjectMap::empty() const
//{
//    return table_.empty();
//}
//
//#ifdef DEBUG
//bool IdToObjectMap::has(const ObjectId& id, const JSObject* obj) const
//        {
//            auto p = table_.lookup(id);
//            if (!p)
//                return false;
//            return p->value().unbarrieredGet() == obj;
//        }
//#endif



} // namespace se {

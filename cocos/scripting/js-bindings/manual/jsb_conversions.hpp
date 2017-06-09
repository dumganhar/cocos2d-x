#pragma once

#include "cocos/scripting/js-bindings/jswrapper/SeApi.h"
#include "cocos/scripting/js-bindings/manual/jsb_classtype.hpp"

#include "cocos2d.h"
#include "extensions/cocos-ext.h"

#define JSB_PRECONDITION2_VOID(condition, ...) \
    do { \
        if ( ! (condition) ) { \
            cocos2d::log("jsb: ERROR: File %s: Line: %d, Function: %s", __FILE__, __LINE__, __FUNCTION__ ); \
            cocos2d::log(__VA_ARGS__); \
            return; \
        } \
    } while(0)

#define JSB_PRECONDITION2(condition, ret_value, ...) \
    do { \
        if ( ! (condition) ) { \
            cocos2d::log("jsb: ERROR: File %s: Line: %d, Function: %s", __FILE__, __LINE__, __FUNCTION__ ); \
            cocos2d::log(__VA_ARGS__); \
            return (ret_value); \
        } \
    } while(0)


#define JSB_PRECONDITION3(condition, ret_value, failed_code) \
    do { \
        if (!(condition)) \
        { \
            failed_code; \
            return (ret_value); \
        } \
    } while(0)


// se value -> native value
bool seval_to_int32(const se::Value& v, int32_t* ret);
bool seval_to_uint32(const se::Value& v, uint32_t* ret);
bool seval_to_int8(const se::Value& v, int8_t* ret);
bool seval_to_uint8(const se::Value& v, uint8_t* ret);
bool seval_to_int16(const se::Value& v, int16_t* ret);
bool seval_to_uint16(const se::Value& v, uint16_t* ret);
bool seval_to_boolean(const se::Value& v, bool* ret);
bool seval_to_float(const se::Value& v, float* ret);
bool seval_to_double(const se::Value& v, double* ret);
bool seval_to_long(const se::Value& v, long* ret);
bool seval_to_ulong(const se::Value& v, unsigned long* ret);
bool seval_to_longlong(const se::Value& v, long long* ret);
bool seval_to_ssize(const se::Value& v, ssize_t* ret);
bool seval_to_std_string(const se::Value& v, std::string* ret);
bool seval_to_Vec2(const se::Value& v, cocos2d::Vec2* pt);
bool seval_to_Vec3(const se::Value& v, cocos2d::Vec3* pt);
bool seval_to_Vec4(const se::Value& v, cocos2d::Vec4* pt);
bool seval_to_Mat4(const se::Value& v, cocos2d::Mat4* mat);
bool seval_to_Size(const se::Value& v, cocos2d::Size* size);
bool seval_to_Rect(const se::Value& v, cocos2d::Rect* rect);
bool seval_to_Color3B(const se::Value& v, cocos2d::Color3B* color);
bool seval_to_Color4B(const se::Value& v, cocos2d::Color4B* color);
bool seval_to_Color4F(const se::Value& v, cocos2d::Color4F* color);
bool seval_to_ccvalue(const se::Value& v, cocos2d::Value* ret);
bool seval_to_ccvaluemap(const se::Value& v, cocos2d::ValueMap* ret);
bool seval_to_ccvaluemapintkey(const se::Value& v, cocos2d::ValueMapIntKey* ret);
bool seval_to_ccvaluevector(const se::Value& v, cocos2d::ValueVector* ret);
bool sevals_variadic_to_ccvaluevector(const se::ValueArray& args, cocos2d::ValueVector* ret);
bool seval_to_blendfunc(const se::Value& v, cocos2d::BlendFunc* ret);
bool seval_to_std_vector_string(const se::Value& v, std::vector<std::string>* ret);
bool seval_to_std_vector_int(const se::Value& v, std::vector<int>* ret);
bool seval_to_std_vector_float(const se::Value& v, std::vector<float>* ret);
bool seval_to_std_vector_Vec2(const se::Value& v, std::vector<cocos2d::Vec2>* ret);
bool seval_to_FontDefinition(const se::Value& v, cocos2d::FontDefinition* ret);
bool seval_to_Acceleration(const se::Value& v, cocos2d::Acceleration* ret);
bool seval_to_Quaternion(const se::Value& v, cocos2d::Quaternion* ret);
bool seval_to_AffineTransform(const se::Value& v, cocos2d::AffineTransform* ret);
bool seval_to_Viewport(const se::Value& v, cocos2d::experimental::Viewport* ret);
bool seval_to_Data(const se::Value& v, cocos2d::Data* ret);

template<typename T>
bool seval_to_native_ptr(const se::Value& v, T* ret)
{
    assert(ret != nullptr);
    if (!v.isObject())
    {
        *ret = nullptr;
        return false;
    }

    T ptr = (T)v.toObject()->getPrivateData();
    if (ptr == nullptr)
    {
        *ret = nullptr;
        return false;
    }

    *ret = ptr;
    return true;
}

template<typename T>
bool seval_to_Vector(const se::Value& v, cocos2d::Vector<T>* ret)
{
    assert(ret != nullptr);
    assert(v.isObject());
    se::Object* obj = v.toObject();
    assert(obj->isArray());

    bool ok = true;
    uint32_t len = 0;
    ok = obj->getArrayLength(&len);
    if (!ok)
    {
        ret->clear();
        return false;
    }

    se::Value tmp;
    for (uint32_t i = 0; i < len; ++i)
    {
        ok = obj->getArrayElement(i, &tmp);
        if (!ok && tmp.isObject())
        {
            ret->clear();
            return false;
        }

        T nativeObj = (T)tmp.toObject()->getPrivateData();

        ret->pushBack(nativeObj);
    }

    return true;
}

// native value -> se value
bool int8_to_seval(int8_t v, se::Value* ret);
bool uint8_to_seval(uint8_t v, se::Value* ret);
bool int32_to_seval(int32_t v, se::Value* ret);
bool uint32_to_seval(uint32_t v, se::Value* ret);
bool int16_to_seval(uint16_t v, se::Value* ret);
bool uint16_to_seval(uint16_t v, se::Value* ret);
bool boolean_to_seval(bool v, se::Value* ret);
bool float_to_seval(float v, se::Value* ret);
bool double_to_seval(double v, se::Value* ret);
bool long_to_seval(long v, se::Value* ret);
bool ulong_to_seval(unsigned long v, se::Value* ret);
bool longlong_to_seval(long long v, se::Value* ret);
bool ssize_to_seval(ssize_t v, se::Value* ret);
bool std_string_to_seval(const std::string& v, se::Value* ret);

bool Vec2_to_seval(const cocos2d::Vec2& v, se::Value* ret);
bool Vec3_to_seval(const cocos2d::Vec3& v, se::Value* ret);
bool Vec4_to_seval(const cocos2d::Vec4& v, se::Value* ret);
bool Mat4_to_seval(const cocos2d::Mat4& v, se::Value* ret);
bool Size_to_seval(const cocos2d::Size& v, se::Value* ret);
bool Rect_to_seval(const cocos2d::Rect& v, se::Value* ret);
bool Color3B_to_seval(const cocos2d::Color3B& v, se::Value* ret);
bool Color4B_to_seval(const cocos2d::Color4B& v, se::Value* ret);
bool Color4F_to_seval(const cocos2d::Color4F& v, se::Value* ret);
bool ccvalue_to_seval(const cocos2d::Value& v, se::Value* ret);
bool ccvaluemap_to_seval(const cocos2d::ValueMap& v, se::Value* ret);
bool ccvaluemapintkey_to_seval(const cocos2d::ValueMapIntKey& v, se::Value* ret);
bool ccvaluevector_to_seval(const cocos2d::ValueVector& v, se::Value* ret);
bool blendfunc_to_seval(const cocos2d::BlendFunc& v, se::Value* ret);
bool std_vector_string_to_seval(const std::vector<std::string>& v, se::Value* ret);
bool std_vector_int_to_seval(const std::vector<int>& v, se::Value* ret);
bool std_vector_float_to_seval(const std::vector<float>& v, se::Value* ret);
bool std_vector_Touch_to_seval(const std::vector<cocos2d::Touch*>& v, se::Value* ret);
bool uniform_to_seval(const cocos2d::Uniform* v, se::Value* ret);
bool FontDefinition_to_seval(const cocos2d::FontDefinition& v, se::Value* ret);
bool Acceleration_to_seval(const cocos2d::Acceleration* v, se::Value* ret);
bool Quaternion_to_seval(const cocos2d::Quaternion& v, se::Value* ret);
bool ManifestAsset_to_seval(const cocos2d::extension::ManifestAsset& v, se::Value* ret);
bool AffineTransform_to_seval(const cocos2d::AffineTransform& v, se::Value* ret);
bool Viewport_to_seval(const cocos2d::experimental::Viewport& v, se::Value* ret);
bool Data_to_seval(const cocos2d::Data& v, se::Value* ret);

template<typename T>
bool Vector_to_seval(const cocos2d::Vector<T>& v, se::Value* ret)
{
    assert(ret != nullptr);
    bool ok = true;
    se::Object* obj = se::Object::createArrayObject(v.size(), false);

    uint32_t i = 0;
    for (const auto& e : v)
    {
        auto iter = se::__nativePtrToObjectMap.find(e);
        if (iter == se::__nativePtrToObjectMap.end())
        {
            CCLOGWARN("WARNING: type: (%s) isn't catched!", typeid(*e).name());
            continue;
        }

        obj->setArrayElement(i, se::Value(iter->second));
        ++i;
    }

    ret->setObject(obj);
    obj->release();

    return ok;
}

template<typename T>
bool native_ptr_to_seval(typename std::enable_if<!std::is_base_of<cocos2d::Ref,T>::value,T>::type* v, se::Value* ret)
{
    assert(ret != nullptr);
    if (v == nullptr)
    {
        ret->setNull();
        return true;
    }

    se::Object* obj = nullptr;
    auto iter = se::__nativePtrToObjectMap.find(v);
    if (iter == se::__nativePtrToObjectMap.end())
    { // If we couldn't find native object in map, then the native object is created from native code. e.g. TMXLayer::getTileAt
//        CCLOGWARN("WARNING: non-Ref type: (%s) isn't catched!", typeid(*v).name());
        se::Class* cls = JSBClassType::findClass<T>(v);
        assert(cls != nullptr);
        obj = se::Object::createObjectWithClass(cls, false);
        obj->setPrivateData(v);
    }
    else
    {
        obj = iter->second;
    }

    ret->setObject(obj);
    return true;
}

template<typename T>
bool native_ptr_to_seval(typename std::enable_if<std::is_base_of<cocos2d::Ref,T>::value,T>::type* v, se::Value* ret)
{
    assert(ret != nullptr);
    if (v == nullptr)
    {
        ret->setNull();
        return true;
    }

    se::Object* obj = nullptr;
    auto iter = se::__nativePtrToObjectMap.find(v);
    if (iter == se::__nativePtrToObjectMap.end())
    { // If we couldn't find native object in map, then the native object is created from native code. e.g. TMXLayer::getTileAt
//        CCLOGWARN("WARNING: Ref type: (%s) isn't catched!", typeid(*v).name());
        se::Class* cls = JSBClassType::findClass<T>(v);
        assert(cls != nullptr);
        obj = se::Object::createObjectWithClass(cls, false);
        obj->setPrivateData(v);
        v->retain(); // Retain the native object to unify the logic in finalize method of js object.
    }
    else
    {
        obj = iter->second;
    }

    ret->setObject(obj);
    return true;
}

template<typename T>
bool native_ptr_to_seval(typename std::enable_if<!std::is_base_of<cocos2d::Ref,T>::value,T>::type* v, se::Class* cls, se::Value* ret)
{
    assert(ret != nullptr);
    if (v == nullptr)
    {
        ret->setNull();
        return true;
    }

    se::Object* obj = nullptr;
    auto iter = se::__nativePtrToObjectMap.find(v);
    if (iter == se::__nativePtrToObjectMap.end())
    { // If we couldn't find native object in map, then the native object is created from native code. e.g. TMXLayer::getTileAt
//        CCLOGWARN("WARNING: Ref type: (%s) isn't catched!", typeid(*v).name());
        assert(cls != nullptr);
        obj = se::Object::createObjectWithClass(cls, false);
        obj->setPrivateData(v);
    }
    else
    {
        obj = iter->second;
    }

    ret->setObject(obj);
    return true;
}


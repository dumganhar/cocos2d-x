/*
 * Copyright (c) 2012 Zynga Inc.
 * Copyright (c) 2013-2017 Chukong Technologies Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */


#ifndef __js_bindings_chipmunk_manual
#define __js_bindings_chipmunk_manual

#include "jsapi.h"
#include "scripting/js-bindings/manual/js_bindings_config.h"
#include "scripting/js-bindings/manual/js_manual_conversions.h"
#include "scripting/js-bindings/manual/ScriptingCore.h"
#ifdef JSB_INCLUDE_CHIPMUNK

#include "chipmunk/chipmunk_private.h"
#include "scripting/js-bindings/auto/js_bindings_chipmunk_auto_classes.h"

// Free Functions
bool JSB_cpSpaceAddCollisionHandler(JSContext *cx, uint32_t argc, JS::Value *vp);
bool JSB_cpSpaceRemoveCollisionHandler(JSContext *cx, uint32_t argc, JS::Value *vp);

bool JSB_cpArbiterGetBodies(JSContext *cx, uint32_t argc, JS::Value *vp);
bool JSB_cpArbiterGetShapes(JSContext *cx, uint32_t argc, JS::Value *vp);

bool JSB_cpBodyGetUserData(JSContext *cx, uint32_t argc, JS::Value *vp);
bool JSB_cpBodySetUserData(JSContext *cx, uint32_t argc, JS::Value *vp);

// poly related
bool JSB_cpAreaForPoly(JSContext *cx, uint32_t argc, JS::Value *vp);
bool JSB_cpMomentForPoly(JSContext *cx, uint32_t argc, JS::Value *vp);
bool JSB_cpCentroidForPoly(JSContext *cx, uint32_t argc, JS::Value *vp);
bool JSB_cpRecenterPoly(JSContext *cx, uint32_t argc, JS::Value *vp);

// "Methods" from the OO API
bool JSB_cpSpace_setDefaultCollisionHandler(JSContext *cx, uint32_t argc, JS::Value *vp);
bool JSB_cpSpace_addCollisionHandler(JSContext *cx, uint32_t argc, JS::Value *vp);
bool JSB_cpSpace_removeCollisionHandler(JSContext *cx, uint32_t argc, JS::Value *vp);

// manually wrapped for rooting/unrooting purposes
bool JSB_cpSpace_addBody(JSContext *cx, uint32_t argc, JS::Value *vp);
bool JSB_cpSpace_addConstraint(JSContext *cx, uint32_t argc, JS::Value *vp);
bool JSB_cpSpace_addShape(JSContext *cx, uint32_t argc, JS::Value *vp);
/* FIXME: removed in Chipmunk v7.0: bool JSB_cpSpace_addStaticShape(JSContext *cx, uint32_t argc, JS::Value *vp); */
bool JSB_cpSpace_removeBody(JSContext *cx, uint32_t argc, JS::Value *vp);
bool JSB_cpSpace_removeConstraint(JSContext *cx, uint32_t argc, JS::Value *vp);
bool JSB_cpSpace_removeShape(JSContext *cx, uint32_t argc, JS::Value *vp);
/* FIXME: removed in Chipmunk v7.0: bool JSB_cpSpace_removeStaticShape(JSContext *cx, uint32_t argc, JS::Value *vp); */
bool JSB_cpSpace_segmentQueryFirst(JSContext *cx, uint32_t argc, JS::Value *vp);
/* FIXME: removed in Chipmunk 7.0: bool JSB_cpSpace_nearestPointQueryNearest(JSContext *cx, uint32_t argc, JS::Value *vp); */
bool JSB_cpSpace_eachShape(JSContext *cx, uint32_t argc, JS::Value *vp);
bool JSB_cpSpace_eachBody(JSContext *cx, uint32_t argc, JS::Value *vp);
bool JSB_cpSpace_eachConstraint(JSContext *cx, uint32_t argc, JS::Value *vp);
bool JSB_cpSpace_pointQuery(JSContext *cx, uint32_t argc, JS::Value *vp);
/* FIXME: renamed in chipmunk v7.0: bool JSB_cpSpace_nearestPointQuery(JSContext *cx, uint32_t argc, JS::Value *vp); */
/* FIXME: New in Chipmunk 7.0*/
bool JSB_cpSpace_pointQueryNearest(JSContext *cx, uint32_t argc, JS::Value *vp);
bool JSB_cpSpace_segmentQuery(JSContext *cx, uint32_t argc, JS::Value *vp);
bool JSB_cpSpace_bbQuery(JSContext *cx, uint32_t argc, JS::Value *vp);
bool JSB_cpSpace_addPostStepCallback(JSContext *cx, uint32_t argc, JS::Value *vp);

bool JSB_cpShape_pointQuery(JSContext *cx, uint32_t argc, JS::Value *vp);
bool JSB_cpShape_segmentQuery(JSContext *cx, uint32_t argc, JS::Value *vp);

bool JSB_cpArbiter_getBodies(JSContext *cx, uint32_t argc, JS::Value *vp);
bool JSB_cpArbiter_getShapes(JSContext *cx, uint32_t argc, JS::Value *vp);

bool JSB_cpBody_constructor(JSContext *cx, uint32_t argc, JS::Value *vp);
bool JSB_cpBody_getUserData(JSContext *cx, uint32_t argc, JS::Value *vp);
bool JSB_cpBody_setUserData(JSContext *cx, uint32_t argc, JS::Value *vp);

bool JSB_cpBody_eachShape(JSContext *cx, uint32_t argc, JS::Value *vp);
bool JSB_cpBody_eachConstraint(JSContext *cx, uint32_t argc, JS::Value *vp);
bool JSB_cpBody_eachArbiter(JSContext *cx, uint32_t argc, JS::Value *vp);

// Chipmunk v6.2 / 7.0 compatibility
bool JSB_cpMomentForSegment(JSContext *cx, uint32_t argc, JS::Value *vp);
bool JSB_cpPolyShape_getVerts(JSContext *cx, uint32_t argc, JS::Value *vp);

// conversions

JS::Value cpBB_to_jsval(JSContext *cx, cpBB bb );
bool jsval_to_cpBB( JSContext *cx, JS::Value vp, cpBB *ret );
bool jsval_to_array_of_cpvect( JSContext *cx, JS::Value vp, cpVect**verts, int *numVerts);
bool jsval_to_cpVect( JSContext *cx, JS::Value vp, cpVect *out );
JS::Value cpVect_to_jsval( JSContext *cx, cpVect p );
bool jsval_to_cpShapeFilter( JSContext *cx, JS::Value vp, cpShapeFilter *out );
JS::Value cpShapeFilter_to_jsval( JSContext *cx, cpShapeFilter filter);
bool jsval_to_cpTransform( JSContext *cx, JS::Value vp, cpTransform *transform);
JS::Value cpTransform_to_jsval( JSContext *cx, cpTransform transform);
JS::Value cpPointQueryInfo_to_jsval(JSContext *cx, cpPointQueryInfo pointQueryInfo);
JS::Value cpSegmentQueryInfo_to_jsval(JSContext *cx, cpSegmentQueryInfo segmentQueryInfo);

// Object Oriented Chipmunk
void JSB_cpBase_createClass(JSContext* cx, JS::HandleObject globalObj);
extern JSObject* JSB_cpBase_object;
extern const JSClass* JSB_cpBase_class;
extern void register_CCPhysicsSprite(JSContext *cx, JS::HandleObject obj);
extern void register_CCPhysicsDebugNode(JSContext *cx, JS::HandleObject obj);

// Manual constructor / destructors
bool JSB_cpPolyShape_constructor(JSContext *cx, uint32_t argc, JS::Value *vp);
void JSB_cpSpace_finalize(JSFreeOp *fop, JSObject *obj);

#endif // JSB_INCLUDE_CHIPMUNK

#endif // __js_bindings_chipmunk_manual

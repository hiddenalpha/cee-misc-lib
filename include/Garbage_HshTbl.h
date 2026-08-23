#ifndef JUST_PREVENT_SUB_INCLUSIONS_GUARD_HOAnAE4JWitiZKzD
#define JUST_PREVENT_SUB_INCLUSIONS_GUARD_HOAnAE4JWitiZKzD
#include <qntan/Qntan.h>
#include <assert.h>
#include <errno.h>
#endif /* JUST_PREVENT_SUB_INCLUSIONS_GUARD_HOAnAE4JWitiZKzD */


/*
 * This is a TEMPLATE. Usage example:
 *
 * #define NAME PersonTbl       // MUST be valid identifier
 * #define TYPE struct Person   // MUST be a valid type
 * #include <Garbage_HshTbl.h>  // Creates instance for NAME/TYPE.
 *
 * void foo( void ){
 *     struct Garbage_HshTbl_Opts opts = {
 *         .mallocator = mallocator,
 *         .differs = referYourDiffersFuncHere,
 *         .hash = referYourHashFuncHere,
 *     };
 *     struct PersonTbl humans;
 *     PersonTbl_init(&humans, &opts);
 *     struct Person pete = {0};
 *     int err = PersonTbl_addIfNew(humans, &pete);
 *     assert(err == 1);
 *     PersonTbl_fini(humans);
 * }
 *
 */


#ifndef NAME
#	error "You have to '#define NAME ..' before including this file"
#endif

#ifndef TYPE
#	error "You have to '#define TYPE ..' before including this file"
#endif

#ifndef STATIC_ASSERT
#	define STATIC_ASSERT(EXPR) _Static_assert(EXPR,"")
#	define STATIC_ASSERT_gotDefinedSuH12sDq4qu2p9IK
#endif
#define UNREF_IDX_Ya2N2TBLHPZks5Jc 1
#define TYPEOF_unref_uClKiHvtIzAsQhJr(N) void(*N)(struct Qntan_HshTbl**)
#define STR_CAT_2_Impl_HVyhsPhJ28xdqEfP(A, B) A##B
#define STR_CAT_2_HVyhsPhJ28xdqEfP(A, B) STR_CAT_2_Impl_HVyhsPhJ28xdqEfP(A, B)

#define TO_OPAQUE_1f4m9k4IqpVDVfai(DST, SRC) do{ \
	{struct NAME typeCheck = DST;(void)typeCheck;} \
	{struct Qntan_HshTbl *const*const typeCheck = SRC;(void)typeCheck;} \
	STATIC_ASSERT(sizeof (DST)._opaque >= sizeof SRC); \
	memcpy((DST)._opaque, &SRC, sizeof SRC); \
}while(0)
#define OF_OPAQUE_elBmohhiJrdayK5R(DST, SRC) do{ \
	DST = NULL; \
	{struct Qntan_HshTbl*const*const typeCheck = DST;(void)typeCheck;} \
	{struct NAME const typeCheck = SRC;(void)typeCheck;} \
	STATIC_ASSERT(sizeof DST <= sizeof (SRC)._opaque); \
	memcpy(&DST, (SRC)._opaque, sizeof DST); \
}while(0)


#define TO_OPAQUE_CursorEv11sdQGaXP(DST, SRC) do{ \
	{struct STR_CAT_2_HVyhsPhJ28xdqEfP(NAME, _Cursor) typeCheck = DST;(void)typeCheck;} \
	{struct Qntan_HshTbl_Cursor **typeCheck = SRC;(void)typeCheck;} \
	STATIC_ASSERT(sizeof (DST)._opaque >= sizeof SRC); \
	memcpy((DST)._opaque, &SRC, sizeof SRC); \
}while(0)
#define OF_OPAQUE_CursorEv11sdQGaXP(DST, SRC) do{ \
	DST = NULL; \
	{struct Qntan_HshTbl_Cursor *const*const typeCheck = DST;(void)typeCheck;} \
	{struct STR_CAT_2_HVyhsPhJ28xdqEfP(NAME, _Cursor) typeCheck = SRC;(void)typeCheck;} \
	STATIC_ASSERT(sizeof(DST) <= sizeof (SRC)._opaque); \
	memcpy(&DST, (SRC)._opaque, sizeof(SRC)); \
}while(0)


struct NAME {
	union { uintptr_t _align; TYPE *_sizeHint; char _opaque[2*sizeof(uintptr_t)]; };
};


struct STR_CAT_2_HVyhsPhJ28xdqEfP(NAME, _Cursor) {
	union { uintptr_t _align; char _opaque[sizeof(uintptr_t)]; };
};


static inline int STR_CAT_2_HVyhsPhJ28xdqEfP(NAME, _init)(
	struct NAME*a, struct Garbage_HshTbl_Opts*opts
){
	assert(opts);  assert(opts->elmSz == 0 && "do NOT set it! Will be overriden");
	opts->elmSz = sizeof(TYPE);
	struct Qntan_HshTbl**x = Garbage_newHshTbl(opts);
	if( !x ){ assert(errno > 0); return -errno; }
	TO_OPAQUE_1f4m9k4IqpVDVfai(*a, x);
	{TYPEOF_unref_uClKiHvtIzAsQhJr(typeCheck) = opts->unref;(void)typeCheck;}
	STATIC_ASSERT(sizeof*a >= sizeof(uintptr_t)*UNREF_IDX_Ya2N2TBLHPZks5Jc);
	memcpy(a->_opaque + sizeof(uintptr_t)*UNREF_IDX_Ya2N2TBLHPZks5Jc,
	       &opts->unref,
	       sizeof opts->unref);
	return 0;
}


static inline int STR_CAT_2_HVyhsPhJ28xdqEfP(NAME, _fini)(
	struct NAME*a
){
	struct Qntan_HshTbl**t;  OF_OPAQUE_elBmohhiJrdayK5R(t, *a);
	TYPEOF_unref_uClKiHvtIzAsQhJr(unref);
	STATIC_ASSERT(sizeof *a >= sizeof(uintptr_t)*UNREF_IDX_Ya2N2TBLHPZks5Jc);
	memcpy(&unref, a->_opaque + sizeof(uintptr_t)*UNREF_IDX_Ya2N2TBLHPZks5Jc, sizeof unref);
	if( unref ) unref(t);
	return 0;
}


static inline int STR_CAT_2_HVyhsPhJ28xdqEfP(NAME, _addIfNew)(
	struct NAME*a, TYPE *b
){
	struct Qntan_HshTbl**t;  OF_OPAQUE_elBmohhiJrdayK5R(t, *a);
	return GARB_HshTbl_addIfNew(t, b);
}


static inline int STR_CAT_2_HVyhsPhJ28xdqEfP(NAME, _del)(
	struct NAME*a, TYPE b, TYPE*c
){
	struct Qntan_HshTbl**t;  OF_OPAQUE_elBmohhiJrdayK5R(t, *a);
	return GARB_HshTbl_del(t, &b, c);
}


static inline int STR_CAT_2_HVyhsPhJ28xdqEfP(NAME, _get)(
	struct NAME*a, TYPE b, TYPE*c
){
	struct Qntan_HshTbl**t;  OF_OPAQUE_elBmohhiJrdayK5R(t, *a);
	return GARB_HshTbl_get(t, &b, c);
}


static inline int STR_CAT_2_HVyhsPhJ28xdqEfP(NAME, _swap)(
	struct NAME*a, TYPE*b, TYPE*c
){
	struct Qntan_HshTbl**t;  OF_OPAQUE_elBmohhiJrdayK5R(t, *a);
	return GARB_HshTbl_swap(t, b, c);
}


static inline int STR_CAT_2_HVyhsPhJ28xdqEfP(NAME, _delAny)(
	struct NAME*a, TYPE*b
){
	struct Qntan_HshTbl**t;  OF_OPAQUE_elBmohhiJrdayK5R(t, *a);
	return GARB_HshTbl_delAny(t, b);
}


static inline int64_t STR_CAT_2_HVyhsPhJ28xdqEfP(NAME, _nObj)(
	struct NAME*a
){
	struct Qntan_HshTbl**t;  OF_OPAQUE_elBmohhiJrdayK5R(t, *a);
	return GARB_HshTbl_nObj(t);
}


static inline int STR_CAT_2_HVyhsPhJ28xdqEfP(NAME, _Cursor_init)(
	struct NAME*a,
	struct STR_CAT_2_HVyhsPhJ28xdqEfP(NAME, _Cursor)*b
){
	struct Qntan_HshTbl**t;  OF_OPAQUE_elBmohhiJrdayK5R(t, *a);
	struct Qntan_HshTbl_Cursor **c = GARB_HshTbl_newCursor(t);
	TO_OPAQUE_CursorEv11sdQGaXP(*b, c);
	return 0;
}


static inline int STR_CAT_2_HVyhsPhJ28xdqEfP(NAME, _Cursor_fini)(
	struct NAME*a,
	struct STR_CAT_2_HVyhsPhJ28xdqEfP(NAME, _Cursor) b
){
	struct Qntan_HshTbl**t;  OF_OPAQUE_elBmohhiJrdayK5R(t, *a);
	struct Qntan_HshTbl_Cursor**c;  OF_OPAQUE_CursorEv11sdQGaXP(c, b);
	GARB_HshTbl_delCursor(t, c);
	return 0;
}


static inline int STR_CAT_2_HVyhsPhJ28xdqEfP(NAME, _Cursor_next)(
	struct STR_CAT_2_HVyhsPhJ28xdqEfP(NAME, _Cursor)*a, TYPE*b
){
	struct Qntan_HshTbl_Cursor**c;  OF_OPAQUE_CursorEv11sdQGaXP(c, *a);
	return GARB_HshTbl_Cursor_next(c, b);
}


static inline int STR_CAT_2_HVyhsPhJ28xdqEfP(NAME, _Cursor_del)(
	struct STR_CAT_2_HVyhsPhJ28xdqEfP(NAME, _Cursor)*a, TYPE*b
){
	struct Qntan_HshTbl_Cursor**c;  OF_OPAQUE_CursorEv11sdQGaXP(c, *a);
	/*void?*/GARB_HshTbl_Cursor_del(c, b);
	return 0;
}





#undef NAME
#undef TYPE
#undef UNREF_IDX_Ya2N2TBLHPZks5Jc
#undef TYPEOF_unref_uClKiHvtIzAsQhJr
#undef STR_CAT_2_Impl_HVyhsPhJ28xdqEfP
#undef STR_CAT_2_HVyhsPhJ28xdqEfP
#undef TO_OPAQUE_1f4m9k4IqpVDVfai
#undef OF_OPAQUE_elBmohhiJrdayK5R
#undef TO_OPAQUE_CursorEv11sdQGaXP
#undef OF_OPAQUE_CursorEv11sdQGaXP
#ifdef STATIC_ASSERT_gotDefinedSuH12sDq4qu2p9IK
#	undef STATIC_ASSERT
#endif


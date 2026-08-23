#ifndef INCGUARD_o88MTP48oQzErOQu
#define INCGUARD_o88MTP48oQzErOQu

#include <qntan/Qntan.h>
#include <assert.h>
#include <errno.h>

#endif /* INCGUARD_o88MTP48oQzErOQu */


/*
 * This is a TEMPLATE. Usage example:
 *
 * #define NAME PersonTbl       // MUST be valid identifier
 * #define TYPE struct Person   // MUST be a valid type
 * #include <Garbage_HshIdx.h>  // Creates instance for NAME/TYPE.
 *
 * void foo( void ){
 *     TODO put example here.
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
#	define STATIC_ASSERT_gotDefinedtFsLo04TZgP6MLdi
#endif
#define UNREF_IDX_FLb8Czi6jiH0U25I 1
#define TYPEOF_unref_bTCsf8xQbpBfEJXR(N) void(*N)(struct Qntan_HshIdx**)
#define STR_CAT_2_Impl_AHTUqt1asWOmeATs(A, B) A##B
#define STR_CAT_2_AHTUqt1asWOmeATs(A, B) STR_CAT_2_Impl_AHTUqt1asWOmeATs(A, B)

#define TO_OPAQUE_gTEdjIMUYqxo4nFA(DST, SRC) do{ \
	{struct NAME typeCheck = DST;(void)typeCheck;} \
	{struct Qntan_HshIdx *const*const typeCheck = SRC;(void)typeCheck;} \
	STATIC_ASSERT(sizeof (DST)._opaque >= sizeof SRC); \
	memcpy((DST)._opaque, &SRC, sizeof SRC); \
}while(0)
#define OF_OPAQUE_elBmohhiJrdayK5R(DST, SRC) do{ \
	DST = NULL; \
	{struct Qntan_HshIdx*const*const typeCheck = DST;(void)typeCheck;} \
	{struct NAME const typeCheck = SRC;(void)typeCheck;} \
	STATIC_ASSERT(sizeof DST <= sizeof (SRC)._opaque); \
	memcpy(&DST, (SRC)._opaque, sizeof DST); \
}while(0)


struct NAME {
	union {
		uintptr_t _align;
		char _opaque[2*sizeof(uintptr_t)];
	};
};


struct STR_CAT_2_AHTUqt1asWOmeATs(NAME, _Cursor) {
	union { uintptr_t _align; char _opaque[sizeof(uintptr_t)]; };
};


static inline int STR_CAT_2_AHTUqt1asWOmeATs(NAME, _init)(
	struct NAME*a, struct Garbage_HshIdx_Opts*opts
){
	assert(opts);  assert(opts->elemSz == 0 && "do NOT set it! Will be overriden");
	opts->elemSz = sizeof(TYPE);
	struct Qntan_HshIdx**x = Garbage_newHshIdx(opts);
	if( !x ){ assert(errno > 0); return -errno; }
	TO_OPAQUE_gTEdjIMUYqxo4nFA(*a, x);
	{TYPEOF_unref_bTCsf8xQbpBfEJXR(typeCheck) = opts->unref;(void)typeCheck;}
	STATIC_ASSERT(sizeof*a >= sizeof(uintptr_t)*UNREF_IDX_FLb8Czi6jiH0U25I);
	memcpy(a->_opaque + sizeof(uintptr_t)*UNREF_IDX_FLb8Czi6jiH0U25I,
	       &opts->unref,
	       sizeof opts->unref);
	return 0;
}


static inline int STR_CAT_2_AHTUqt1asWOmeATs(NAME, _fini)(
	struct NAME*a
){
	struct Qntan_HshIdx**t;  OF_OPAQUE_elBmohhiJrdayK5R(t, *a);
	TYPEOF_unref_bTCsf8xQbpBfEJXR(unref);
	STATIC_ASSERT(sizeof *a >= sizeof(uintptr_t)*UNREF_IDX_FLb8Czi6jiH0U25I);
	memcpy(&unref, a->_opaque + sizeof(uintptr_t)*UNREF_IDX_FLb8Czi6jiH0U25I, sizeof unref);
	if( unref ) unref(t);
	return 0;
}


static inline int STR_CAT_2_AHTUqt1asWOmeATs(NAME, _addIfNew)(
	struct NAME*a, TYPE*b, int idx
){
	struct Qntan_HshIdx**t;  OF_OPAQUE_elBmohhiJrdayK5R(t, *a);
#ifdef Qntan_HshIdx_addIfNew
	return Qntan_HshIdx_addIfNew(t, b, idx);
#else
	return (*t)->addIfNew(t, b, idx);
#endif
}


static inline int STR_CAT_2_AHTUqt1asWOmeATs(NAME, _get)(
	struct NAME*a, TYPE b, TYPE*c, int d
){
	struct Qntan_HshIdx**t;  OF_OPAQUE_elBmohhiJrdayK5R(t, *a);
#ifdef Qntan_HshIdx_get
	return Qntan_HshIdx_get(t, &b, c, d);
#else
	return (*t)->get(t, &b, c, d);
#endif
}


static inline size_t STR_CAT_2_AHTUqt1asWOmeATs(NAME, _getCnt)(
	struct NAME*a
){
	struct Qntan_HshIdx**t;  OF_OPAQUE_elBmohhiJrdayK5R(t, *a);
#ifdef Qntan_HshIdx_getCnt
	return Qntan_HshIdx_getCnt(t);
#else
	return (*t)->getCnt(t);
#endif
}


static inline int STR_CAT_2_AHTUqt1asWOmeATs(NAME, _swap)(
	struct NAME*a, TYPE b, TYPE*c, int idx
){
	struct Qntan_HshIdx**t;  OF_OPAQUE_elBmohhiJrdayK5R(t, *a);
#ifdef Qntan_HshIdx_swap
	return Qntan_HshIdx_swap(t, &b, c, idx);
#else
	return (*t)->swap(t, &b, c, idx);
#endif
}


#undef NAME
#undef TYPE
#undef UNREF_IDX_FLb8Czi6jiH0U25I
#undef TYPEOF_unref_bTCsf8xQbpBfEJXR
#undef STR_CAT_2_Impl_AHTUqt1asWOmeATs
#undef STR_CAT_2_AHTUqt1asWOmeATs
#undef TO_OPAQUE_gTEdjIMUYqxo4nFA
#undef OF_OPAQUE_elBmohhiJrdayK5R
#ifdef STATIC_ASSERT_gotDefinedtFsLo04TZgP6MLdi
#	undef STATIC_ASSERT
#endif


#ifndef INCGUARD_ZNugP3hIPfGOcBW1
#define INCGUARD_ZNugP3hIPfGOcBW1
#if 0

  WARN THIS IS IN PRE-ALPHA STATE! DO NOT USE! ITS WAY TOO SHAKY AND
  INCOMPLETE YET! FURTHER, THERE S ALSO NO IMPL AVAILABLE YET.

  This is a try to create a generic and slim as possible graphics
  rendering API. As independent of any tech or libs. And should be usable
  combined with any libs or backend impl out there.

  For now, it is impl with virtual calls. YES, even some cry that it is
  sloow. But while development, flexibility is WAY more important to me.
  PLUS my intent is to design it in a way, that switching to static
  calls will be just a macro definition away.

#endif
#ifdef __cplusplus
#   ifndef USE_CRAPPY_LANGUAGE
#       error "WRONG compiler! This is a C project dude!"
#   endif
extern "C" {
#endif





#define ARGB8888_OF_RGBA8888(C) ((C&0xFF)<<24 | (C&0xFF000000)>>8 | (C&0xFF0000)>>8 | (C&0xFF00)>>8)
#define RGBA8888_OF_RGBA(R, G, B, A) ((R<<24) | ((G<<16)&0xFF0000) | ((B<<8)&0xFF00) | (A&0xFF))


/* TODO needs better scoping I guess. */
enum PixFmt {
    PixFmt_NONE=0,
    PixFmt_RGBA8888,
    PixFmt_RGB888,
    PixFmt_GRAYSCALE8,
    PixFmt_BLACKWHITE1,
    PixFmt_END,
};


struct Matrix4d {
    float m00, m01, m02, m03;
    float m10, m11, m12, m13;
    float m20, m21, m22, m23;
    float m30, m31, m32, m33;
};


struct Vertex2d { float x, y; };


struct Vertex2dRGBA8888 { float x, y;  int color; };


/* TODO ReThink scope prefix. */
struct Garbage_Renderer {
#if defined(VIRTUAL_CALLS_PROVIDE) && !VIRTUAL_CALLS_PROVIDE
    void *nothing_here_Someone_has_disabled_virtual_calls;
#else
    void (*unref)( struct Garbage_Renderer** );
//    /*
//     * Sets the destination rect where the drawing should go. */
//    void (*setDstRect2d)( struct Garbage_Renderer**, int x, int y, int w, int h, int pitch );
//    /**/
//    void (*setTransformMatrix)( struct Garbage_Renderer**, struct Matrix4d* );
//    /**/
//    void (*blend2d)( struct Garbage_Renderer**,
//        void *pixls, int x, int y, int w, int h, int pitch, enum PixFmt );
    /**/
    void (*setScissor)( struct Garbage_Renderer**, int x, int y, int w, int h );
    /**/
    void (*triangleStrip2d)( struct Garbage_Renderer**,
        struct Vertex2dRGBA8888 const*vertices, int numVertices );
    /**/
    void (*triangleStrip2dOneColor)( struct Garbage_Renderer**,
        struct Vertex2d const*vertices, int numVertices, int rgba8888 );
    /*
     * @param x  NOT center.
     * @param y  NOT center.
     * @param w  horizontal diameter.
     * @param h  vertical diameter. */
    void (*circle2dOneColor)( struct Garbage_Renderer**,
        int x, int y, int w, int h, int colorRGBA8888 );
    /**/
    void (*lineStrip2dOneColor)( struct Garbage_Renderer**,
        struct Vertex2d const*vertices, int numVertices, int lineWidth, int rgba8888 );
    /**/
#endif
};



#ifdef __cplusplus
} /* extern "C" */
#endif


#endif /* INCGUARD_ZNugP3hIPfGOcBW1 */

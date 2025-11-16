#ifndef INCGUARD_tjdaoh5R02CYDPPV
#define INCGUARD_tjdaoh5R02CYDPPV

#ifdef USERCONFIG
USERCONFIG
#endif

#include <qntan/Qntan.h>

#if __cplusplus
#   ifndef USE_CRAPPY_LANGUAGE
#       error "WRONG compiler! This is a C project dude!"
#   endif
extern "C" {
#endif


#define SIZEOF_struct_Garbage_Env 512


struct Garbage_Env;
struct Garbage_DollarParser;
struct Garbage_SocketMgr;
struct Garbage_HttpClientReq;
struct Garbage_HttpMsg_Hdr;
struct Garbage_HttpServer;
struct Garbage_HttpParser;
struct Garbage_TlsClient;
struct Garbage_ZipBrowser;
















struct Garbage_Env_Memory {
	uintptr_t _[512/sizeof(uintptr_t)];
};

struct Garbage_Env {
    /*
     * Destructor */
    void (*unref)( struct Garbage_Env** );
    /*
     * Process reactor tasks until queue gets drained.
     * TODO document return value */
    int  (*runUntilPause)( struct Garbage_Env** );
    /*
     * Process reactor tasks until event loop is signalized to end. */
    void (*runUntilDone)( struct Garbage_Env** );
    /*
     * enque a task to the main reactor */
    void (*enque)(
        struct Garbage_Env**, void(*fn)(Qntan_Cls), Qntan_Cls );
    /*
     * TODO write doc */
    void (*addAwaitToken)( struct Garbage_Env** );
    /*
     * TODO write doc */
    void (*delAwaitToken)( struct Garbage_Env** );
    /*
     * returns NON-zero, if called from the EvLoopThread. */
    int (*isEvLoopThread)( struct Garbage_Env** );
	/*
	 * Returns itself, but as the new API. */
	struct Qntan_EvLoop** (*asEvLoop)( struct Garbage_Env** );
    /*
     * TODO remove the ThreadPool argument. */
    void (*setTimeoutMs)(
        struct Garbage_Env**, struct Qntan_Executor**, int delayMs,
        void(*fn)(int eno, Qntan_Cls), Qntan_Cls );
};







struct Garbage_DollarParser_Mentor {
    /**/
    void (*onChunk)( struct Garbage_DollarParser_Mentor**, char const*restrict buf, int buf_len,
        void(*onDone)(Qntan_Cls), Qntan_Cls );
    /**/
    void (*onVariable)( struct Garbage_DollarParser_Mentor**, char const*restrict buf, int buf_len,
        void(*onDone)(Qntan_Cls), Qntan_Cls );
    /**/
    void (*onEnd)( struct Garbage_DollarParser_Mentor** );
};

/* HINT: there are currently TWO APIs in here. Either use the newer one
 * 'step' API, or use legacy 'write/closeSnk' combo. DO NOT MIX CALLS TO
 * BOTH OF THEM! Strictly use either one or the other. */
struct Garbage_DollarParser {
    void (*unref)( struct Garbage_DollarParser** );
    /*
     * 'srcBuf' points to the current parsing position. It will be
     * updated by the amount that got parsed.
     * 'srcBuf_end' is how many bytes are available from 'srcBuf'
     * onwards.
     * 'dstBuf' will point to result buffer if retval is one of CHUNK or
     * VARIABLE. Its value is undefined for other cases.
     * Return 1 means the next CHUNK is available in 'dstBuf' and is
     * 'dstBuf_end' bytes long.
     * Return 2 means the next VARIABLE is available in 'dstBuf' and is
     * 'dstBuf_end' bytes long.
     * Return 0 means no more elements, parsing is done.
     * Return negative values mean negated error codes. */
    int (*step)(
        struct Garbage_DollarParser**,
        char const**srcBuf, int srcBuf_end,
        int isLastInputBuf,
        char const**dstBuf, int*dstBuf_end );
    /**/
    void (*write)( struct Garbage_DollarParser**, char const*restrict buf, int buf_len,
        void(*onDone)(int retval, Qntan_Cls), Qntan_Cls );
    /**/
    void (*closeSnk)(
        struct Garbage_DollarParser**,
        void(*onDone)(int retval,Qntan_Cls), Qntan_Cls );
};
















struct Garbage_PoolConnection {
	/*
	 * @param sockaddr
	 *      A 'struct sockaddr' indicating the peer to connect to.
	 * @param sockaddr_len
	 *      length of the address stored in 'sockaddr'.
	 * @param flg
	 *      'flg & 8' set means that a TLS socket is wanted.
	 * @param peerHostname
	 *      (optional) Some sockets (eg TLS) can use this to perform
	 *      hostname verification. The passed reference MUST stay valid
	 *      until 'onDone' got called.
	 * @param err
	 *      Negative on errors (value of 'sock' is unspecified in this
	 *      case! There is NO GUARANTE that it is NULL!).
	 *      Zero, if 'sock' got acquired successfully.
	 * @param sock
	 *      The acquired socket instance. WARN: Check 'err' before use.
	 * @param arg
	 *      Context for the callback.
	 */
	void (*sockAcquire)( struct Garbage_PoolConnection**, void*sockaddr, int sockaddr_len,
		int flg, char const*peerHostname,
		void(*onDone)(int err,struct Qntan_Socket**sock,Qntan_Cls arg), Qntan_Cls arg );
	/*
	 * For now this is fire-and-forget. This is because IT IS NOT THE
	 * CALLERS PROBLEM IF THE SOCKET COULDNT BE RELEASED PROPERLY. He
	 * couldn't do anything useful anyway. So errors have to be handled
	 * via the 'PoolConnection' impl itself.
	 *
	 * @param flg
	 *      'flg & 1' set means that socket MUST be closed and therefore
	 *      MUST NOT be ReUsed for pooling or similar. This can happen
	 *      for example with 'HTTP/1.0' or if http messages work with
	 *      'Connection:close' headers. In addition, most protocols use
	 *      this 'close' mechanism for erroneous cases, or sometimes
	 *      also to signal EOF. In all those cases, re-using a socket
	 *      would just be pretty dumb. */
	void (*sockRelease)( struct Garbage_PoolConnection**, struct Qntan_Socket**, int flg );
};











#ifndef    GARB_HshTbl_swap
#   define GARB_HshTbl_swap(A, ...) (*A)->swap(A, __VA_ARGS__)
#endif
#ifndef    GARB_HshTbl_addIfNew
#   define GARB_HshTbl_addIfNew(A, ...) (*A)->addIfNew(A, __VA_ARGS__)
#endif
#ifndef    GARB_HshTbl_del
#   define GARB_HshTbl_del(A, ...) (*A)->del(A, __VA_ARGS__)
#endif
#ifndef    GARB_HshTbl_delAny
#   define GARB_HshTbl_delAny(A, ...) (*A)->delAny(A, __VA_ARGS__)
#endif
#ifndef    GARB_HshTbl_get
#   define GARB_HshTbl_get(A, ...) (*A)->get(A, __VA_ARGS__)
#endif
#ifndef    GARB_HshTbl_nObj
#   define GARB_HshTbl_nObj(A) (*A)->nObj(A)
#endif
#ifndef    GARB_HshTbl_newCursor
#   define GARB_HshTbl_newCursor(A) (*A)->newCursor(A)
#endif
#ifndef    GARB_HshTbl_Cursor_next
#   define GARB_HshTbl_Cursor_next(A, ...) (*A)->next(A, __VA_ARGS__)
#endif
#ifndef    GARB_HshTbl_Cursor_del
#   define GARB_HshTbl_Cursor_del(A, ...) (*A)->del(A, __VA_ARGS__)
#endif
#ifndef    GARB_HshTbl_delCursor
#   define GARB_HshTbl_delCursor(A, ...) (*A)->delCursor(A, __VA_ARGS__)
#endif
#define TPL_Garbage_HshTbl( PREFX, TYPE )\
	static const size_t PREFX##sizeofElem=sizeof(TYPE);\
	static inline int PREFX##swap(struct Qntan_HshTbl**A,TYPE*B,TYPE*C){return GARB_HshTbl_swap(A,B,C);}\
	static inline int PREFX##addIfNew(struct Qntan_HshTbl**A,TYPE*B){return GARB_HshTbl_addIfNew(A,B);}\
	static inline int PREFX##del(struct Qntan_HshTbl**A,TYPE B,TYPE*C){return GARB_HshTbl_del(A,&B,C);}\
	static inline int PREFX##delAny(struct Qntan_HshTbl**A,TYPE*B){return GARB_HshTbl_delAny(A,B);}\
	static inline int PREFX##get(struct Qntan_HshTbl**A,TYPE B,TYPE*C){return GARB_HshTbl_get(A,&B,C);}\
	static inline int PREFX##nObj(struct Qntan_HshTbl**A){return GARB_HshTbl_nObj(A);}\
	static inline struct Qntan_HshTbl_Cursor**PREFX##newCursor(struct Qntan_HshTbl**A){return GARB_HshTbl_newCursor(A);}\
	static inline int PREFX##Cursor_next(struct Qntan_HshTbl_Cursor**A,TYPE*B){return GARB_HshTbl_Cursor_next(A,B);}\
	static inline void PREFX##Cursor_del(struct Qntan_HshTbl_Cursor**A,TYPE*B){GARB_HshTbl_Cursor_del(A,B);}\
	static inline void PREFX##delCursor(struct Qntan_HshTbl**A,struct Qntan_HshTbl_Cursor**B){GARB_HshTbl_delCursor(A,B);}\











/* TODO Isn't this interface a duplicate of ConnectionPool somehow? */
struct Garbage_SocketMgr {
    /*
     * Based on
     * "https://pubs.opengroup.org/onlinepubs/9699919799/functions/socket.html",
     * "https://pubs.opengroup.org/onlinepubs/9699919799/functions/bind.html",
     * "https://pubs.opengroup.org/onlinepubs/9699919799/functions/listen.html".
     *
     * @param sockaddr
     *      a ptr to a 'struct sockaddr' structure representing the address to
     *      bind to.
     * @param sockaddr_len
     *      Length of address passed in 'sockaddr'.
     */
    void (*sockAcquireBind)(
        struct Garbage_SocketMgr**, void*sockaddr, int sockaddr_len, int backlog,
        void(*onDone)(int retval, struct Qntan_Socket**sock, Qntan_Cls),
        Qntan_Cls );
    /*
     * Based on
     * "https://pubs.opengroup.org/onlinepubs/9699919799/functions/socket.html",
     * "https://pubs.opengroup.org/onlinepubs/9699919799/functions/connect.html",
     *
     * @param sockaddr
     *      a ptr to a 'struct sockaddr' structure representing the peer to
     *      connect to.
     *      TODO: Should we use an URL (as char*) instead?
     * @param sockaddr_len
     *      Length of address passed in 'sockaddr'.
     * @param peerHostname
	 *      (optional) some sockets (eg TLS) can use this name for
	 *      furhter verification. Reference MUST stay valid until
	 *      'onDone' gets called.
     */
    void (*sockAcquireConnect)(
        struct Garbage_SocketMgr**, void*sockaddr, int sockaddr_len, char const*peerHostname,
        void(*onDone)(int retval, struct Qntan_Socket**, Qntan_Cls), Qntan_Cls );
	/*
	 * @param flgs
	 *      'flg & 1' set means the socket MUST NOT be re-used, but MUST be
	 *      closed instead.
	 */
	void (*sockRelease)( struct Qntan_Socket**, int flgs );
	/**/
};









struct Garbage_HttpClientReq {
	/*
	 * Applies back-pressure. Can be handy if consumer get overhelmed and
	 * cannot process any more data right now. To continue, 'resume'
	 * MUST be called somewhen later.  */
	void (*pause)( struct Garbage_HttpClientReq** );
	/*
	 * Inverts the effect of 'pause' and resumes the paused events. */
	void (*resume)( struct Garbage_HttpClientReq** );
	/*
	 * @param buf
	 *      The data to write.
	 * @param buf_len
	 *      Now many octets to write from 'buf'.
	 * @param flg
	 *      'flg & 4' set means that this is the last chunk for this
	 *      request (aka EOF).
	 * @param err
	 *      Negative values on error.
	 *      Count of written octets on success.
	 * @param rbuf
	 *      Same value as 'buf', just for convenience.
	 * @param arg
	 *      context for callback.
	 */
	void (*write)( struct Garbage_HttpClientReq**, void*buf, int buf_len, int flg,
		void(*)(int err, void*rbuf, Qntan_Cls arg), Qntan_Cls arg );
	/*
	 * TODO doc*/
	void (*unref)( struct Garbage_HttpClientReq** );
};

struct Garbage_HttpClientReq_Mentor {
	/*
	 * TODO doc*/
	void (*pushIoTask)( void(*task)(Qntan_Cls arg), Qntan_Cls arg, Qntan_Cls cls );
	/*
	 * TODO doc*/
	void (*onError)( int retval, Qntan_Cls cls );
	/*
	 * TODO doc*/
	void (*onRspHdr)(
	    const char*proto, int proto_len, int rspCode, const char*phrase, int phrase_len,
	    const struct Garbage_HttpMsg_Hdr*hdrs, int hdrs_cnt,
	    struct Garbage_HttpClientReq**, Qntan_Cls cls );
	/*
	 * Flg 0x4 set means, that this is the last buffer. This is the last callback
	 * called for this http message. */
	void (*onRspBody)(
	    const char*buf, int buf_len, int flg, struct Garbage_HttpClientReq**, Qntan_Cls cls );
};



struct Garbage_HttpMsg_Hdr {
    const char *key, *val;
    int key_len, val_len;
};





// OBSOLETE? struct Garbage_HttpServer_StepCtx {
// OBSOLETE?     /*
// OBSOLETE?      * Probably contains additional error details. Allocation managed by
// OBSOLETE?      * server. */
// OBSOLETE?     char const *errDetail;
// OBSOLETE?     /*
// OBSOLETE?      * If 'step' returns '1', this field here contains a new client instance
// OBSOLETE?      * for you to take care of. CALLER is now responsible to 'unref' as soon
// OBSOLETE?      * client is no longer needed. */
// OBSOLETE?     struct Garbage_HttpServer_Client **newClient;
// OBSOLETE? };

struct Garbage_HttpServer {
    /*
     * TODO doc */
    void (*unref)( struct Garbage_HttpServer** );
#if 0 /* TODO This looks like a lot of bullshit worth throwing out the window */
    /*
     * EXPERIMENTAL. Callback APIs tend to provocate a horrible resource
     * ownership mess. I need to try if stepper approach works better. */
    int (*runUntilPause)( struct Garbage_HttpServer**, struct Garbage_HttpServer_StepCtx* );
    /*
     * Whenever 'step' returns -EWOULDBLOCK, One can wait here before
     * calling step again. The timeout specifies the POINT IN TIME and
     * NOT a duration. 'tv_sec' and 'tv_nsec' have the same meaning as
     * in struct timespec. */
    int (*waitUntil)( struct Garbage_HttpServer**, uint64_t tv_sec, long tv_nsec );
#endif
    /*
     * TODO unused? -> replace by 'start()'? */
    void (*resume)( struct Garbage_HttpServer** );
    /*
     * TODO unused? */
    void (*pause)( struct Garbage_HttpServer** );
};

// OBSOLETE? #define GARBAGE_HTTPSERVER_CLIENT_REQHDR 2
// OBSOLETE? #define GARBAGE_HTTPSERVER_CLIENT_MSGEND 4
// OBSOLETE? #define GARBAGE_HTTPSERVER_CLIENT_SRCTCPFIN 7
// OBSOLETE? #define GARBAGE_HTTPSERVER_CLIENT_ONSENDDONE 8
// OBSOLETE? 
// OBSOLETE? struct Garbage_HttpServer_Client_StepCtx {
// OBSOLETE?     int type;
// OBSOLETE?     union{
// OBSOLETE?         struct {
// OBSOLETE?             char *mthd;  int mthd_len;
// OBSOLETE?             char *path;  int path_len;
// OBSOLETE?             char *proto; int proto_len;
// OBSOLETE?             struct Garbage_HttpMsg_Hdr *hdrs;
// OBSOLETE?             int hdrs_cnt;
// OBSOLETE?         } reqHdr;
// OBSOLETE?     };
// OBSOLETE? };

struct Garbage_HttpServer_Client {
    /**/
    void (*unref)( struct Garbage_HttpServer_Client** );
    /**/
#if 0 /* TODO this looks like a lot of bullshit */
    /*
     * @return
     *      Negative values on error.
     *      1 if there is an event available in ctx. */
    int  (*step)( struct Garbage_HttpServer_Client**, struct Garbage_HttpServer_Client_StepCtx* );
    /*
     * Whenever 'step' returns -EWOULDBLOCK, One can wait here before
     * calling step again. The timeout specifies the POINT IN TIME and
     * NOT a duration. 'tv_sec' and 'tv_nsec' have the same meaning as
     * in struct timespec. */
    int (*waitUntil)( struct Garbage_HttpServer_Client**, uint64_t tv_sec, long tv_nsec );
#endif
    /**/
    void (*resume)( struct Garbage_HttpServer_Client** );
    /**/
    void (*pause)( struct Garbage_HttpServer_Client** );
    /*
     * If (flg & 1) is set this means to 'flush' output buffer.
     * If (flg & 2) is set this means to 'shutdown(SHUT_WR)' as in
     * "https://pubs.opengroup.org/onlinepubs/9699919799/functions/shutdown.html".
     * If (flg & 4) is set this indicates that after this chunk, the
     * request-response cycle has completed.
     * HINT: At least one of the 'shutdown' or the 'hasEnded' flag MUST be used
     * as soon the request-response cycle has completed. */
    void (*sendRaw)(
        struct Garbage_HttpServer_Client**, char const*buf, int buf_len, int flgs,
        void(*onDone)(int eno,Qntan_Cls), Qntan_Cls );
    /*
     * @param proto - Protocol string (zero-term) to use. Can be NULL, so impl
     *      will choose which proto string to send.
     * @param phrase - Response phrase to use. If NULL, impl will choose an
     *      appropriate phrase based on 'rspCode' (for example 'OK' if rspCode
     *      is 200, etc)
     * @param hdrs - If NULL, server will choose a minimal set of headers to
     *      add (which means most likely ZERO headers for most impls). */
    void (*sendHttpHdr)( struct Garbage_HttpServer_Client**,
        char const*proto, int rspCode, char const*phrase,
        struct Garbage_HttpMsg_Hdr*hdrs, int hdrs_cnt,
        void(*onDone)(int eno,Qntan_Cls), Qntan_Cls );
    /*
     * @param flgs - Usually zero. Bit 0x4 set means that this is the last
     *      chunk. Other bits MUST NOT be set! */
    void (*sendBody)( struct Garbage_HttpServer_Client**,
        char const*chunk, int chunk_len, int flgs,
        void(*onDone)(int eno,Qntan_Cls), Qntan_Cls );
};


struct Garbage_HttpServer_Mentor {
    /*
     * TODO doc */
    void (*onNewClient)(
        struct Garbage_HttpServer_Mentor**, int eno, struct Garbage_HttpServer_Client**,
        void(*onDone)(Qntan_Cls), Qntan_Cls );
    /*
     * TODO doc */
    void (*onClientSrcEof)(
        struct Garbage_HttpServer_Mentor**, struct Garbage_HttpServer_Client** );
    /*
     * TODO doc */
    void (*onHttpReqHdr)(
        struct Garbage_HttpServer_Mentor**, struct Garbage_HttpServer_Client**, int eno,
        char const*mthd, int mthd_len, char const*path, int path_len,
        char const*proto, int proto_len, struct Garbage_HttpMsg_Hdr*hdrs, int hdrs_cnt );
    /*
     * TODO doc */
    void (*onHttpMsgBodyChunk)(
        struct Garbage_HttpServer_Mentor**, struct Garbage_HttpServer_Client**,
        char const*buf, int errOrBufLen );
    /*
     * TODO doc */
    void (*onHttpMsgEnd)( struct Garbage_HttpServer_Mentor**, struct Garbage_HttpServer_Client** );
};






#define GARBAGE_HTTPPARSER_NEEDMOREDATA 5
#define GARBAGE_HTTPPARSER_REQHDR 1
#define GARBAGE_HTTPPARSER_MSGEND 3
#define GARBAGE_HTTPPARSER_STREAMEND 4

struct Garbage_HttpParser_Result {
    int type;
    union {
        struct {
            char *mthd;  int mthd_len;
            char *path;  int path_len;
            char *query; int query_len;
            char *proto; int proto_len;
            struct Garbage_HttpMsg_Hdr *hdrs;
            int hdrs_cnt;
        } reqHdr;
    };
};

struct Garbage_HttpParser {
    void(*unref)( struct Garbage_HttpParser** );
    /**/
    void(*pause)( struct Garbage_HttpParser** );
    /**/
    int (*step)( struct Garbage_HttpParser**, char*restrict buf, int buf_len, int flgs,
        struct Garbage_HttpParser_Result* );
};














struct Garbage_TlsClient {
    void (*unref)( struct Garbage_TlsClient** );
    void (*pause)( struct Garbage_TlsClient** );
    void (*resume)( struct Garbage_TlsClient** );
    struct Garbage_SocketMgr** (*asSocketMgr)( struct Garbage_TlsClient** );
};


struct Garbage_TlsClient_Mentor {
    /**/
    void (*sockAcquire)(
        void*sockaddr, int sockaddr_len, Qntan_Cls cls,
        void(*)(int retval, Qntan_Cls sock, Qntan_Cls arg), Qntan_Cls arg );
    /**/
    void (*sockRelease)( Qntan_Cls sock, int mustClose, Qntan_Cls cls );
    /**/
    void (*sockSend)( Qntan_Cls sock, const void*buf, int buf_len, Qntan_Cls cls,
        void(*onDone)(int retval, Qntan_Cls arg), Qntan_Cls arg );
    /**/
    void (*sockFlush)(
        Qntan_Cls sock, Qntan_Cls cls,
        void(*onDone)(int,Qntan_Cls arg), Qntan_Cls arg );
    /**/
    void (*sockRecv)(
        Qntan_Cls sock, void*buf, int buf_len, Qntan_Cls cls,
        void(*onDone)(int,Qntan_Cls arg), Qntan_Cls arg );
    /**/
    void (*onError)( int eno, Qntan_Cls cls );
};













struct Garbage_PfTransaction {
    int bookgDate_len;  char *bookgDate;
    int valueDate_len;  char *valueDate;
    char isCrdt, isDbit;
    int dstIban_len  ;  char dstIban[24];
    int srcIban_len  ;  char srcIban[24];
    int dbt_len      ;  char const*dbt;
    int cdt_len      ;  char const*cdt;
    int what_len     ;  char const*what;
};

struct Garbage_PoFinCsvParser_Mentor {
    /**/
    void (*onRecord)(
        struct Garbage_PoFinCsvParser_Mentor**, struct Garbage_PfTransaction*,
        void(*onDone)(Qntan_Cls), Qntan_Cls cls);
};

struct Garbage_PoFinCsvParser {
	/*
	 * @param flgs
	 *      (flg & 4) indicates this is last buffer. Any other flags set trigger
	 *      UNDEFINED BEHAVIOR!
	 */
	void (*write)(
		struct Garbage_PoFinCsvParser**, void*buf, int buf_len, int flgs,
		void(*onDone)(int,Qntan_Cls), Qntan_Cls );
};





struct Garbage_SimpleAppendLogTransaction {
    int when_len  ; char *when  ;
    int value_len ; char *value ;
    int accDst_len; char *accDst;
    int accSrc_len; char *accSrc;
    int what_len  ; char *what  ;
};

struct Garbage_SimpleAppendLogParser_Mentor {
    void (*onRecord)(struct Garbage_SimpleAppendLogParser_Mentor**,
        struct Garbage_SimpleAppendLogTransaction*, void(*onDone)(Qntan_Cls), Qntan_Cls arg);
};

struct Garbage_SimpleAppendLogParser {
	/*
	 * @param flgs
	 *      'flg & 4' indicates EOF. Any other flag set is UNDEFINED BEHAVIOR!
	 */
	void (*write)(
		struct Garbage_SimpleAppendLogParser**, void*buf, int buf_len, int flgs,
		void(*onDone)(int,Qntan_Cls), Qntan_Cls );
};










struct Qntan_ZipBrowser_EntryHdr {
	/**/
	uint8_t magic[4];
	/**/
	uint16_t version;
	/**/
	uint8_t flags;
	/**/
	uint16_t comprMthd;
	/*
	 * Mofification date/time.
	 * 'year' is the year (already adjusted away from the 1980 base within
	 * the archive).
	 * 'sec' contains seconds (divide-by-2 got already adjusted by impl). */
	uint16_t year;  uint8_t month, day, hrs, min, sec;
	/**/
	uint32_t crc32;
	/**/
	uint32_t  comprSz,  plainSz;
	/**/
	uint16_t  nameLen,  xtraLen;
	/*
	 * WARN: zero-termination NOT  guaranteed! Have a look at 'nameLen' and
	 * 'xtraLen'. */
	void  *name,  *xtra;
};

struct Qntan_ZipBrowser {
	/*
	 * Returns index of currently selected entry.
	 * WARN: DO NOT USE THIS FUNCTION in streaming mode! Its behavior is
	 * unspecified!
	 * returns negative values in case of error. */
	int64_t (*tellEntry)( struct Qntan_ZipBrowser** );
	/*
	 * Selects entry at index 'idx'. So 1st entry is idx zero, 2nd is idx 1,
	 * and so on.
	 * WARN: DO NOT USE THIS FUNCTION in streaming mode! Its behavior is
	 * unspecified!
	 * This also sets the 'body' cursor to zero.
	 * returns negative values in case of error.
	 * WARN: Positive return values not specified yet! */
	void  (*seekEntry)( struct Qntan_ZipBrowser**, uint32_t idx,
		void(*onDone)(int64_t ret, Qntan_Cls), Qntan_Cls);
	/*
	 * Same as 'seekEntry', BUT: After seek, also reads and returns the local
	 * header information of the seeked-to entry.
	 * WARN: output parameters (name_len, xtra_len, name, xtra) stay only
	 * valid, as long no other call is made!
	 * Caller MUST either pass both of (name, name_len) as NULL, or both as
	 * non-null.
	 * Caller MUST either pass both of (xtra, xtra_len) as NULL, or both as
	 * non-null.
	 * However, caller CAN request ONE, the other, or BOTH of name/xtra outputs.
	 * WARN: references passed to 'onDone' are only valid until 'onDone'
	 * returns AND no other calls are made to the 'ZipBrowser' instance. */
	void  (*seekEntryWithHdr)( struct Qntan_ZipBrowser**, uint32_t idx,
		void(*onDone)(Qntan_Cls, int64_t ret, struct Qntan_ZipBrowser_EntryHdr*),
		Qntan_Cls );
	/**/
	void (*newEntry)( struct Qntan_ZipBrowser**, struct Qntan_ZipBrowser_EntryHdr*,
		void(*onDone)(Qntan_Cls, int ret, uintptr_t entry), Qntan_Cls );
	/*
	 * Read up to 'dstBuf_len' bytes into 'dstBuf' from the current read
	 * cursor onwards. On success, the cursor will be advanced by number of read
	 * octets. The content will NOT be decompressed or similar. Just the pure
	 * octets as present in the archive are read.
	 * returns negative values in case of error.
	 * WARN: Positive return values not specified yet! */
	void (*readBodyRaw)( struct Qntan_ZipBrowser**, void*dstBuf, int dstBuf_len,
		void(*onDone)(Qntan_Cls, int ret), Qntan_Cls );
	/*
	 * Same as 'readBodyRaw', BUT: The data will be returned in its decoded
	 * (think for compression/encryption/etc), so in its original form.
	 * WARN: Be aware that an implementation may NOT support this operation
	 * in some circumstances, and may return '-ENOTSUP'.
	 * returns negative values in case of error. */
	void (*readBodyPlain)( struct Qntan_ZipBrowser**, void*dstBuf, int dstBuf_len,
		void(*onDone)(Qntan_Cls, int ret), Qntan_Cls );
	/*
	 * Write to current body without encoding (eg compression). Just write the
	 * bytes as-is. This is handy for example if the data already is deflated.
	 * 'flgs & 4' indicates EOF. Other flags MUST be zero. */
	void (*writeBodyRaw)( struct Qntan_ZipBrowser**, void const*buf, int len, int flgs,
		void(*onDone)(Qntan_Cls,int), Qntan_Cls );
	/**/
	void (*flush)( struct Qntan_ZipBrowser**, void(*onDone)(Qntan_Cls,int ret), Qntan_Cls );
	/*
	 * TODO archive comment read.
	 * TODO archive comment write.
	 * TODO archive comment seek.
	 * TODO archive comment tell.
	 * TODO archive comment truncate.
	 * TODO archive entry comment read.
	 * TODO archive entry comment write.
	 * TODO archive entry comment seek.
	 * TODO archive entry comment tell.
	 * TODO archive entry comment truncate.
	 */
};










/***********************************************************************
 *
 * Only some quick-n-diry java related definitions.
 *
 * TODO maybe provide via separate header? Or not provide at all?
 *
 * See also (https://docs.oracle.com/javase/specs/jvms/se22/html/index.html).
 *
 **********************************************************************/

#define Garbage_JAVA_THIS_PUBLIC     (1<< 0)
#define Garbage_JAVA_THIS_FINAL      (1<< 4)
#define Garbage_JAVA_THIS_SUPER      (1<< 5)
#define Garbage_JAVA_THIS_INTERFACE  (1<< 9)
#define Garbage_JAVA_THIS_ABSTRACT   (1<<10)
#define Garbage_JAVA_THIS_SYNTHETIC  (1<<12)
#define Garbage_JAVA_THIS_ANNOTATION (1<<13)
#define Garbage_JAVA_THIS_ENUM       (1<<14)
#define Garbage_JAVA_THIS_MODULE     (1<<15)

#define Garbage_JAVA_MTHD_PUBLIC       (1<< 0)
#define Garbage_JAVA_MTHD_PRIVATE      (1<< 1)
#define Garbage_JAVA_MTHD_PROTECTED    (1<< 2)
#define Garbage_JAVA_MTHD_STATIC       (1<< 3)
#define Garbage_JAVA_MTHD_FINAL        (1<< 4)
#define Garbage_JAVA_MTHD_SYNCHRONIZED (1<< 5)
#define Garbage_JAVA_MTHD_BRIDGE       (1<< 6)
#define Garbage_JAVA_MTHD_VARARGS      (1<< 7)
#define Garbage_JAVA_MTHD_NATIVE       (1<< 8)
#define Garbage_JAVA_MTHD_ABSTRACT     (1<<10)
#define Garbage_JAVA_MTHD_STRICT       (1<<11)
#define Garbage_JAVA_MTHD_SYNTHETIC    (1<<12)









#if __cplusplus
} /* extern "C" */
#endif
#endif /* INCGUARD_tjdaoh5R02CYDPPV */

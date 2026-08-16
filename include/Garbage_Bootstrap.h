#ifndef INCGUARD_3PHvlW9sLiqxP9tp
#define INCGUARD_3PHvlW9sLiqxP9tp
#if 0

  This file declares the exposed constructors for the individual
  modules. This file should EXCLUSIVELY be included by the translation
  unit which is solely responsible for initializing a Garbage_Env
  instance. Any other translation units SHOULD NOT include it. They
  should solely work through the instances wired up by the bootstrap
  translation unit.

#endif

#include "Garbage.h"


#if __cplusplus
#   ifndef USE_CRAPPY_LANGUAGE
#       error "STOP IT! This is a **C** project dude! MUST NOT use ugly compilers!"
#   endif
extern "C" {
#endif

#define PUBLIC(T) T










struct Garbage_AppCtx_Opts {
	/* Options to construct a `Garbage_AppCtx`.
	 */
	struct Qntan_Mallocator **mallocator;
	/* (mandatory!) The mallocator used for the app context itslef. But if
	 * there is no other mallocator specified via callback or otherwise, it
	 * will also be used to fulfill `getMallocator()` requests.
	 */
	struct Qntan_Mallocator** (*newMallocator)(
		Qntan_Cls cbackCls, void(**unref)(struct Qntan_Mallocator**) );
	/* If null, the already given `mallocator` will be used.  If given, this
	 * function will be queried as soon a Mallocator gets requested.
	 */
	struct Qntan_EvLoop** (*newEvLoop)(
		Qntan_Cls cbackCls, void(**unref)(struct Qntan_EvLoop**) );
	/* Optional. If given, it will be asked to instantiate the `EvLoop` to
	 * be used.
	 */
	struct Garbage_Env** (*newEnvLegacy)(
		Qntan_Cls cbackCls, void(**unref)(struct Garbage_Env**) );
	/* DEPRECATED! Optional. If given, it will be asked to instantiate the
	 * (OBSOLETE!) `Env` to be used.
	 */
	struct Qntan_Executor** (*newExecutorCpu)(
		Qntan_Cls cbackCls, void(**unref)(struct Qntan_Executor**) );
	/* Optional. If given, it will be asked to instantiate the `Executor` to
	 * be used for CPU focused tasks.
	 * Default impl may try to parse environ `NPROC` as number of threads to
	 * use. If not given, it tries to use as sensible value based on the
	 * available CPU cores.
	 * WARN: Those defaults are given here as a HINT, not a rule to rely
	 *       on. Those may change at any time. If you need clarity,
	 *       instantiate it yourself!
	 */
	struct Qntan_Executor** (*newExecutorIo)(
		Qntan_Cls cbackCls, void(**unref)(struct Qntan_Executor**) );
	/* Optional. If given, it will be asked to instantiate the `Executor` to
	 * be used for IO focused tasks.
	 * If not given, environ `NTHRDIO` will tried to be used as number
	 * of threads. Else it will fallback to 16 IO threads.
	 * WARN: Those defaults are given here as a HINT, not a rule to rely
	 *       on. Those may change at any time. If you need clarity,
	 *       instantiate it yourself!
	 */
	struct Qntan_Scheduler** (*newScheduler)(
		Qntan_Cls cbackCls, void(**unref)(struct Qntan_Scheduler**) );
	/* Optional. If given, it will be asked to instantiate the `Scheduler`
	 * to be used.
	 */
	struct Qntan_LoggerFactory** (*newLoggerFactory)(
		Qntan_Cls, void(**unref)(struct Qntan_LoggerFactory**) );
	/* Optional. If given, it will be asked to instantiate the LoggerFactory
	 * to be used. Keep in mind that in some cases `newLoggerDefault()`
	 * might be used, even a LoggerFactory is given.
	 */
	struct Qntan_Logger** (*newLoggerDefault)(
		Qntan_Cls, void(**unref)(struct Qntan_Logger**) );
	/* Optional. Can be used to oversteer `newLoggerFactory()` for those
	 * cases where the default logger explicitly gets requested.
	 */
	struct Qntan_FileSystem** (*newFileSystem)(
		Qntan_Cls, void(**unref)(struct Qntan_FileSystem**) );
	/* Optional. If given, it will be asked to instantiate the `FileSystem`
	 * to be used.
	 */
	struct Qntan_IoMux** (*newIoMux)(
		Qntan_Cls, void(**unref)(struct Qntan_IoMux**) );
	/* Optional. If given, it will be asked to instantiate the `IoMux` to be
	 * used.
	 */
	struct Qntan_Networker** (*newNetworker)(
		Qntan_Cls, void(**unref)(struct Qntan_Networker**) );
	/* Optional. If given, it will be asked to instantiate the `Networker`
	 * to be used.
	 */
	Qntan_Cls cbackCls;
	/* user context passed to functions present within this struct.
	 */
	void (*unref)( struct Garbage_AppCtx** );
	/* dtor. OUTPUT PARAMETER. Gets set during ctor call. */
};

struct Garbage_AppCtx** Garbage_newAppCtx( struct Garbage_AppCtx_Opts* );
/* Constructs a new `Garbage_AppCtx` based on given options.
 */










struct Garbage_Cond_Opts {
	/**/
	struct Qntan_Mallocator **mallocator;
	/**/
	struct Qntan_EvLoop **evLoop;
	/**/
	struct Qntan_Executor **lockWaiter;
	/* executor, where `lock()` will be called. This option exists,
	 * becuase the mutx might already been locked, so calling it on the
	 * thread which called `bcast()`/`signal()` would cause deadlocks.
	 * TODO: Fix this somehow better.
	 */
	void (*unref)( struct Qntan_Cond** );
	/* virtual dtor, gets set while ctor call.
	 */
};
/**/
struct Qntan_Cond**
Garbage_newCond( struct Garbage_Cond_Opts*opts );










struct Garbage_DollarParser_Opts {
    struct Garbage_DollarParser_Mentor **mentor;
    struct Qntan_Mallocator **mallocator;
};

struct Garbage_DollarParser** Garbage_newDollarParser( struct Garbage_DollarParser_Opts*opts );







struct Garbage_IoMultiplexer_Opts {
	/**/
	struct Qntan_Mallocator **mallocator;
	/**/
	struct Qntan_EvLoop **evLoop;
	/**/
	struct Qntan_Executor **ioWorker;
	/* (Only needed on winDOOF..)
	 */
	void (*start)( struct Qntan_IoMux** );
	/* OUTPUT PARAMETER!
	 * This will be set to the start function from the callee. Calling this
	 * function start the IoMultiplexer.
	 */
	struct Qntan_LoggerFactory **loggerFactory;
	/* (optional)
	 */
	void (*stop)( struct Qntan_IoMux**, void(*)(int,Qntan_Cls), Qntan_Cls );
	/* OUTPUT PARAMETER! Will be set while ctor call.
	 * WARN: This may block longer than a EvLoop may find pleasing.
	 */
	void (*unref)( struct Qntan_IoMux** );
	/* OUTPUT PARAMETER!
	 */
};

struct Qntan_IoMux** Garbage_newIoMultiplexer( struct Garbage_IoMultiplexer_Opts* );










struct Garbage_CsvDec_Opts {
	/**/
	struct Qntan_Mallocator **mallocator;
	/**/
	struct Qntan_EvLoop **evLoop;
	/**/
	struct Qntan_CsvDec_Mentor **mentor;
	/**/
	char const*delimCol;
	/* The char which delimits columns. WARN: only the very 1st char
	 * will be used! Do not try to pass longer strings!
	 * Defaults to `;` if this field is not given (aka NULL).
	 */
	struct Qntan_Logger **log;
	/**/
	void(*unref)( struct Qntan_CsvDec** );
	/* virtual dtor. Will be set by ctor.
	 */
};

struct Qntan_CsvDec** Garbage_newCsvDec( struct Garbage_CsvDec_Opts* );










struct Garbage_CsvIStream_Opts {
	/**/
	struct Qntan_EvLoop **evLoop;
	/**/
	struct Qntan_Mallocator **mallocator;
	/**/
	struct Qntan_CsvIStream_Mentor **mentor;
	/**/
	struct Qntan_Logger **log;
	/* Optional logger to use.
	 */
	char *delimCol;
	/* WARN: MUST be zero-term string with ONLY ONE char in it. Eg {';', '\0'} */
};

struct Qntan_CsvIStream** Garbage_newCsvIStream( struct Garbage_CsvIStream_Opts* );










struct Garbage_EvLoop_Opts {
	/**/
	struct Qntan_Mallocator **mallocator;
	/**/
	struct Qntan_Logger **log;
	/**/
	struct Garbage_Env** (*asLegacyEnv)( struct Qntan_EvLoop** );
	/* OUTPUT PARAMETER. Will be set by impl. This when called returns
	 * an adapter to the LEGACY Garbage_Env struct.
	 */
	void (*unref)( struct Qntan_EvLoop** );
	/* dtor. Gets set during ctor call.
	 */
};

struct Garbage_Env_Opts {
    /**/
    struct Garbage_Env_Memory *memBlockToUse;
    /**/
	int memBlockToUse_sz;
	/* Size in octets of memory block behind 'memBlockToUse'.
	 */
    struct Qntan_Mallocator **mallocator;
    /**/
	struct Qntan_Logger **log;
	/**/
};

struct Qntan_EvLoop** Garbage_newEvLoop( struct Garbage_EvLoop_Opts* );

/* DEPRECATED! use 'Garbage_newEvLoop()'. */
struct Garbage_Env** Garbage_newEnv( struct Garbage_Env_Opts* );










struct Garbage_FileBufBacked_Opts {
	/**/
	struct Qntan_Mallocator **mallocator;
	/*
	 * OUTPUT PARAMETER! */
	void (*unref)( struct Qntan_File** );
	/**/
};

struct Qntan_File**
Garbage_newFileBufBacked( struct Garbage_FileBufBacked_Opts* );










struct Garbage_FileStdlib_Opts {
	/**/
	struct Qntan_Mallocator **mallocator;
	/**/
	struct Qntan_IoMux **ioMux;
	/*
	 * The backing 'FILE*' (or 'HANDLE' on ugly systems). */
	uintptr_t file;
	/*
	 * if '1', impl will 'fclose(file)' while 'unref'. If '0', caller is
	 * responsible to do so. All other values are considered UB! */
	int takeOwnership;
	/**/
	void (*unref)( struct Qntan_File** );
	/**/
};

struct Qntan_File**
Garbage_newFileStdlib( struct Garbage_FileStdlib_Opts* );










struct Garbage_FileZlibDeflatePipe_Opts {
	/**/
	struct Qntan_Mallocator **mallocator;
	/**/
	struct Qntan_Executor **cpuWorker;
	/* compression will be delegated to here.
	 * OPTIONAL, if missing, compression just happens on the EvLoop (usually
	 * a bad idea).
	 * WARN: if given, an EvLoop MUST be given too.
	 */
	struct Qntan_EvLoop **evLoop;
	/* Needed to switch back from worker threads.
	 */
	int compressLevel;
	/* Values 0-9. Where 1=fast, 9=strong and 0=store-only.
	 * Most recommend 6 as a good balance.
	 */
	struct Qntan_Logger **log;
	/* (optional) logger.
	 */
	void (*unref)(struct Qntan_File**);
	/* Virtual dtor. Gets set while ctor call.
	 */
};

struct Qntan_File**
Garbage_newFileZlibDeflatePipe( struct Garbage_FileZlibDeflatePipe_Opts* );










struct Garbage_FileSystemOfHost_Opts {
	/**/
	struct Qntan_Mallocator **mallocator;
	/**/
	struct Qntan_EvLoop **evLoop;
	/* As we have to use `ioWorker` in some cases, we also need `evLoop` to
	 * get back to its thread.
	 */
	struct Qntan_IoMux **ioMux;
	/**/
	struct Qntan_Executor **ioWorker;
	/* IoMux cannot do some stuff (eg `rename`). So we still need an ioWorker.
	 */
	struct Qntan_Logger **log;
	/**/
	void (*unref)( struct Qntan_FileSystem** );
	/**/
};

struct Qntan_FileSystem**
Garbage_newFileSystemOfHost( struct Garbage_FileSystemOfHost_Opts* );










/*
 * TODO: Having a look at all those callback that have to be passed over
 * and over again, it looks like we should refactor this to an
 * 'HttpClient' which then can be used to produce several requests,
 * without having the need to pass (AND COPY, AND STORE) all those
 * callbacks and context over and over again.
 */
struct Garbage_HttpClientReq_Opts {
	struct Garbage_Env **env;
	struct Qntan_Mallocator **mallocator;
	struct Qntan_Executor **ioWorker;
	struct Qntan_Networker **networker;
	/*
	 * Context passed to the mentor related functions. */
	Qntan_Cls mentorCtx;
	/**/
	struct Garbage_HttpClientReq_Mentor *mentor;
	/*
	 * Context passed to the socket related functions. */
	Qntan_Cls socketCtx;
	/*
	 * @param flg
	 *      'flg & 8' set indicates that the socket is epxected to be
	 *      secured with TLS.
	 * @param sockaddr
	 *      Just a ptr to 'struct sockaddr' indicating where to connect to.
	 * @param sockaddr_len
	 *      Length of the address in 'sockaddr'.
	 * @param err
	 *      Negative values indicate errors. In this case, 'sock' in unspecified.
	 *      Zero on success and the 'sock' pointing to the socket to use.
	 * @param arg
	 *      Context for the callback.  */
	void (*socketAcquire)( Qntan_Cls socketCtx, int flg, void*sockaddr, int sockaddr_len,
		void(*)(int err,struct Qntan_Socket**sock,Qntan_Cls arg), Qntan_Cls arg);
	/*
	 * @param sock
	 *      The socket to be released.
	 * @param flg
	 *      'flg & 1' set indicates, that the socket MUST NOT be re-used
	 *      (think for pooling). Instead it MUST be closed. This can be
	 *      necessary for example when dealing with 'HTTP/1.0' or
	 *      'Connection:close'.
	 *      All other flags MUST be set to zero.
	 */
	void (*socketRelease)( Qntan_Cls socketCtx, struct Qntan_Socket**sock, int flg );
	/*
	 * Like 'GET', 'POST', ... */
	char const *mthd;
	/*
	 * Like "example.com", "127.0.0.1", "::1"  */
	char const *host;
	/*
	 * Like "/index.html", "/foo/bar?blubb=42" */
	char const *url;
	uint_least16_t port;
	struct Garbage_HttpMsg_Hdr *hdrs;
	union{ int hdrs_cnt; uintptr_t _align_i8YE8RToyzv5O9Ok; };
	/*
	 * Set this to '1' if TLS should be used for this request. MUST be
	 * zero otherwise.  */
	union{ uint8_t isTls; uintptr_t _align_Vjb8yegDsy2J4S0D; };
};

struct Garbage_HttpClientReq** Garbage_newHttpClientReq( struct Garbage_HttpClientReq_Opts* );



struct Garbage_HttpClientCurlEasyCmd_Opts {
	/**/
	struct Qntan_Mallocator **mallocator;
	/**/
	Qntan_Cls cls;
	/* Passed to 'newProcess' as context.
	 */
	struct Qntan_Process** (*newProcess)( char const*const*argv, char const*const*envp, char*workdir,
		void (*onStdout)(char const*oBuf,int oLen,int oFlgs,Qntan_Cls),
		void (*onStderr)(char const*eBuf,int eLen, int eFlgs,Qntan_Cls),
		void (**unref)(struct Qntan_Process**),
		Qntan_Cls clsForCbacks, Qntan_Cls cls );
	/* @param argv
	 *      Argv to be executed. Points to a zero terminated ARRAY of
	 *      pointers.
	 * @param envp
	 *      Environ to run the child process with. if NULL, parents environ
	 *      gets used. MUST be terminated with a NULL entry.
	 * @param workdir
	 *      The childs initial working directory.
	 * @param onStdout, onStderr
	 *      Called whenever some data comes in from childs stdout/stderr stream.
	 * @param oLen, eLen
	 *      Negative values on error.
	 *      Positive values indicates how much data is available in oBuf/eBuf.
	 *      Zero is like a positive value, aka got an empty buffer.
	 * @param oFlgs, eFlgs
	 *      If 'flgs & 4' is set, it means that this is the last chunk of
	 *      this stream.
	 * @param clsForCbacks
	 *      Context for 'onStdout' and 'onStderr'.
	 * @param cls
	 *      Context for newProcess intself. Aka the value given by 'cls'
	 *      within this Opts structure here.
	 */
	void (*unref)( struct Qntan_HttpClient** );
	/* OUTPUT PARAM! Will be set by callee.
	 */
};

struct Qntan_HttpClient** Garbage_newHttpClientCurlEasyCmd( struct Garbage_HttpClientCurlEasyCmd_Opts* );










struct Garbage_HttpServer_Opts {
    /**/
    struct Garbage_Env **env;
    /**/
    struct Qntan_Mallocator **mallocator;
    /**/
    struct Qntan_Logger **log;
    /*
     * SocketManager which will be responsible for socket handling for this
     * server. */
    struct Garbage_SocketMgr **socketMgr;
    /**/
    int sockaddr_len;
    /*
     * Likely a 'struct sockaddr' or similar. Will be passed to 'socketMgr' to
     * indicate where the socket should be connected to. */
    void *sockaddr;
    /**/
    int backlog;
    /**/
    void (*onError)( Qntan_Cls cls, int eno, char const*msg );
    /*
     * 'clientCls' can be set to a value, which will then be passed to
     * later callbacks. This ptr MUST NOT be touched anymore, after
     * 'onNewClient' has returned. */
    void (*onNewClient)( Qntan_Cls cls, struct Garbage_HttpServer_Client**,
        Qntan_Cls*clientCls );
    /*
     * All pointed to objects become invalid after function returns. */
    void (*onReqHdr)( Qntan_Cls clientCls,
        char const*mthd , int mthd_len ,
        char const*path , int path_len ,
        char const*query, int query_len,
        char const*proto, int proto_len,
        struct Garbage_HttpMsg_Hdr*hdrs, int hdrs_cnt );
    /*
     * 'buf' MUST NOT be used anymore, after function returns.
     * 'flgs' 0x4 set indicates that this is the last buffer of this request. */
    void (*onBodyChunk)( Qntan_Cls clientCls, char const*buf, int buf_len, int flgs );
    /**/
    void (*onSrcTcpFin)( Qntan_Cls clientCls );
    /**/
    Qntan_Cls cls;
};

struct Garbage_HttpServer** Garbage_newHttpServer(
    struct Garbage_HttpServer_Opts*
);









struct Garbage_JavaBytecodeParser_Opts {
	/**/
	struct Qntan_Mallocator **mallocator;
	/**/
	struct Qntan_JavaBytecodeParser_Mentor **mentor;
	/*
	 * OUTPUT PARAMETER!
	 * This will be set by callee. Calling this function will release the
	 * instance and its resources. */
	void (*unref)( struct Qntan_JavaBytecodeParser** );
	/**/
};

PUBLIC(struct Qntan_JavaBytecodeParser**)
Garbage_newJavaBytecodeParser( struct Garbage_JavaBytecodeParser_Opts* );










struct Garbage_JsonEncoder_Opts {
	/**/
	struct Qntan_Mallocator **mallocator;
	/*
	 * Gets called with the produced json chunks. Flag 0x4 set indicates that
	 * this is the last chunk of this JSON. */
	void (*onChunk)( Qntan_Cls cls, char const*chunk, int chunk_len, int flgs );
	/**/
	Qntan_Cls cls;
	/*
	 * OUTPUT PARAMETER!
	 * A function, that will destruct the instance. */
	void (*unref)( struct Qntan_JsonEnc** );
	/**/
};
struct Qntan_JsonEnc** Garbage_newJsonEncoder( struct Garbage_JsonEncoder_Opts* );






struct Garbage_JsonDec_Opts {
	struct Qntan_EvLoop **evLoop;
	/**/
    struct Garbage_Env **env;
	/* Unfortunately still some legacy usages in impl.
	 */
    struct Qntan_Mallocator **mallocator;
	/**/
    struct Qntan_Executor **cpuWorker;
	/**/
	struct Qntan_Logger **log;
	/* (optional) logger to use for logging.
	 */
	void(*unref)( struct Qntan_JsonDec** );
	/* Virtual dtor. Gets set during ctor call, as an output param.
	 */
};

struct Qntan_JsonDec** Garbage_newJsonDec(
    struct Garbage_JsonDec_Opts*,
    struct Qntan_JsonDec_Mentor*, Qntan_Cls mentorCtx
);




struct Garbage_JsonTreeDec_Opts {
	/**/
	struct Qntan_EvLoop **evLoop;
	/**/
	struct Garbage_Env **env;
	/* TODO get rid of this DEPRECATED dependency.
	 */
	struct Qntan_Mallocator **mallocator;
	/**/
	struct Qntan_MemArena **scratchArena;
	/**/
	struct Qntan_MemArena **jsonArena;
	/**/
	struct Qntan_Executor **cpuWorker;
	/**/
	struct Qntan_Logger **log;
	/* (optional) logger.
	 */
	void (*onJsonResult)( Qntan_Cls, int err, struct Qntan_JsonTreeDec_JsonNode*,
		void(*onDone)(int,Qntan_Cls), Qntan_Cls );
	/**/
	void (*onError)( Qntan_Cls cls, uintmax_t errOff );
	/* Called if a parsing error occurs. 'errOff' is a byte offset measured from
	 * the beginning of the json to the char where the error was detected. Be
	 * prepared that the error may not be exactly at the pointed location, but
	 * somewhere near that location.
	 */
	Qntan_Cls cls;
	/* user value passed to callbacks
	 */
	void (*unref)( struct Qntan_JsonTreeDec** );
	/* OUTPUT PARAMETER!
	 * Call this to release the instance (aka virtual destructor).
	 */
};

struct Qntan_JsonTreeDec** Garbage_newJsonTreeDec( struct Garbage_JsonTreeDec_Opts* );










struct Garbage_LoggerStderr_Opts {
	/**/
	struct Qntan_Mallocator **mallocator;
	/* as soon any state is given (eg name or level), a mallocator is REQUIRED.
	 */
	char const *name;
	/**/
	int logLevel;
	/* -1=OFF, 0=DEFAULT, 1=FATAL, 2=ERROR, 3=WARNING, 4=INFO, 5=DEBUG, 6=TRACE.
	 */
	void (*unref)(struct Qntan_Logger**);
	/**/
};

struct Qntan_Logger**
Garbage_newLoggerStderr( struct Garbage_LoggerStderr_Opts* );










struct Garbage_MallocatorTracing_Opts {
    void *memBlockToUse;
    int memBlockToUse_numBytes;
    void *observer;
    void (*onMemUsageUpdate)( void*observer, size_t oldInUse, size_t newInUse, struct Qntan_Mallocator** );
	/* OUTPUT PARAM! Will be set by ctor. Client can use this to query
	 * how much memory is currently in use. */
	int64_t (*getMemInUse)( struct Qntan_Mallocator** );
	struct Qntan_Logger **log;
	/* (optional) logger for logging.
	 */
};

struct Garbage_MallocatorParanoid_Opts {
	uintptr_t *instance;
	/* OPTIONAL memory to use for this specific instance. If given, the
	 * state will be tracked for this instance. Also the additional
	 * getters will be set so the state can be queried. This is intended
	 * for testing scenarios.
	 */
	size_t instance_sz;
	/* size of given `instance` for integrity checks. MUST be `0` if no
	 * `instance` given. Else MUST be big enough for the impl to fit.
	 */
	size_t (*getMemInUse)( struct Qntan_Mallocator**_ );
	/* returns now much memory is currently allocd through this
	 * mallocator. WARN: ctor will only set this func if `instance` is
	 * given. */
};

/*
 * generic mallocator, just delegating to something like the stdlib
 * allocator or similar. */
struct Qntan_Mallocator** Garbage_newMallocator(void);


/*
 * Mallocator with additional memory usage tracing. */
struct Qntan_Mallocator** Garbage_newMallocatorTracing( struct Garbage_MallocatorTracing_Opts*opts );


/*
 * Mallocator with some paranoia precautions, which is terribly slow
 * (AND LEAKY!), but tries hunt memory issues. */
struct Qntan_Mallocator** Garbage_newMallocatorParanoid( struct Garbage_MallocatorParanoid_Opts* );





struct Garbage_ArenaLinkedList_Opts {
    /*
     * The arena will do all its own allocations through this mallocator. */
    struct Qntan_Mallocator **mallocator;
    /*
     * The size in bytes of the allocation blocks. */
    size_t blkSz;
	/*
	 * OUTPUT PARAMETER! */
	void (*unref)( struct Qntan_MemArena** );
	/**/
};

struct Garbage_ArenaLinkedList {
    /*
     * Like 'free'. */
    void (*unref)( struct Garbage_ArenaLinkedList** );
    /*
     * Returns itself as an abstract MemoryArena. */
    struct Qntan_MemArena** (*asMemoryArena)( struct Garbage_ArenaLinkedList** );
};

/*
 * My 1st ever arena allocator. For now, allocs in steps of 'blkSz' and manages
 * those block internally via likded list. */
struct Qntan_MemArena** Garbage_newArenaLinkedList( struct Garbage_ArenaLinkedList_Opts* );










struct Garbage_Mutx_Opts {
	/**/
	struct Qntan_Mallocator **mallocator;
	/**/
	void (*unref)( struct Qntan_Mutx** );
	/* virtual dtor, gets set while ctor call.
	 */
};
/**/
struct Qntan_Mutx**
Garbage_newMutx( struct Garbage_Mutx_Opts*opts );










struct Garbage_Networker_Opts {
    struct Qntan_Mallocator **mallocator;
    struct Qntan_Executor **ioWorker;
};

struct Qntan_Networker** Garbage_newNetworker( struct Garbage_Networker_Opts* );










struct Garbage_FastFourierTransform_Opts {
	/**/
	struct Qntan_Mallocator **mallocator;
	/**/
	void (*unref)( struct Qntan_FourierTransform**_ );
	/* OUTPUT PARAMETER! Set by impl during construction. Has to be
	 * called as soon instance no longer needed.
	 */
};

struct Qntan_FourierTransform**
Garbage_newFastFourierTransform( struct Garbage_FastFourierTransform_Opts* );










struct Garbage_ProcessFactory_Opts {
    struct Qntan_Mallocator **mallocator;
    struct Garbage_Env **env;
};


struct Garbage_Process_Opts {
	/**/
	struct Qntan_Mallocator **mallocator;
	/**/
	struct Qntan_EvLoop **evLoop;
	/**/
	struct Qntan_IoMux **ioMux;
	/**/
	struct Qntan_Executor **joinExecutor;
	/**/
	struct Garbage_Env **env;
	/* OBSOLETE! use 'evLoop'!
	 */
	char **argv;
	/* argv to be executed. MUST be ternimated by a NULL entry. MUST
	 * point to a zero terminated ARRAY of pointers.
	 * See also [what is argv](https://hiddenalpha.ch/slnk/id/1-ox0os4aqgDdNm3kH).
	 */
	char **envp;
	/* environment to run the child process in. if NULL, the parents
	 * environment will be inherited to the child. MUST be terminated
	 * with a NULL entry.
	 */
	char *workdir;
	/* The childs initial working directory.
	 */
	char *img;
	/* Pass 'NULL' here. Unless you know what you're doing.
	 */
	uint8_t usePathSearch;
	/* non-zero indicates that you want to use PATH to find the executable
	 */
	Qntan_Cls cls;
	/* Context passed to callbacks.
	 */
	void (*onStdout)( char const*buf, int len, int flgs, Qntan_Cls );
	/* Called whenever some data comes in from childs stdout stream.
	 * @param len
	 *      Negative values on error.
	 *      Positive values indicates how much data is available in 'buf'.
	 *      Zero is like a positive value, aka you got an empty buffer.
	 * @param flgs
	 *      If 'flgs & 4' is set, it means that is the last chunk of this
	 *      stream.
	 */
	void (*onStderr)( char const*buf, int len, int flgs, Qntan_Cls );
	/* See doc of 'onStdout'.
	 */
	void (*unref)( struct Qntan_Process** );
	/* OUTPUT PARAMETER! Set by callee. Has to be called by caller.
	 */
};


struct Garbage_ProcessFactory**
Garbage_newProcessFactory( struct Garbage_ProcessFactory_Opts* );


struct Qntan_Process**
Garbage_newProcess( struct Garbage_Process_Opts* );










struct Garbage_HshIdx_Opts {
	/**/
	struct Qntan_Mallocator **mallocator;
	/**/
	struct Qntan_LoggerFactory **logFac;
	/* (optional) logger factory to be used for logging.
	 */
	size_t elemSz;
	/* Size of one of the objects to be stored (eg `sizeof(struct Foo)`).
	 */
	size_t initialCap;
	/* Size of one of the objects to be stored (eg `sizeof(struct Foo)`).
	 */
	int nDimmensions;
	/* How many `differs` and `hash` functions are present. The
	 * `differs` and `hash` arrays MUST ALWAYS contain as many functions.
	 * So if eg `nDimmensions = 3`, `differs` MUST contain 3 functions
	 * AND `hash` also MUST contain 3 functions.
	 * Further, each pair (eg `differs[0]` and `hash[0]` and so on) MUST
	 * return consistent values. So for example
	 * if `hash[0](a) != hash[0](b)`, then `assert(differs[0](a,b))`
	 */
	int (**differs)( Qntan_Cls cls, void*ptrToLft, void*ptrToRgt );
	/* TODO doc
	 */
	uintptr_t (**hash)( Qntan_Cls cls, void*ptrToObj );
	/* TODO doc
	 */
	Qntan_Cls cls;
	/* Closure passed to `differs()` and `hash()` calls.
	 */
	void (*unref)( struct Qntan_HshIdx** );
	/* OUTPUT PARAM. Will be set by impl to a virtual dtor.
	 */
};

struct Qntan_HshIdx** Garbage_newHshIdx( struct Garbage_HshIdx_Opts* );










struct Garbage_HshTbl_Opts {
    /*
     * Will be used to perform the necessary memory allocations. */
    struct Qntan_Mallocator **mallocator;
    /*
     * Size of a single element in bytes. For example to store int32_t values,
     * one could pass 'sizeof int32_t'. */
    size_t elmSz;
    /*
     * Returns zero if 'lft' and 'rgt' are equal. Returns non-zero otherwise. */
    int (*differs)( Qntan_Cls cls, void*ptrToLft, void*ptrToRgt );
    /*
     * Returns the hash for given 'object'. low order bits should hold good
     * distributed bits. Whereas high order bits just do not matter that much,
     * as they likely get cropped off anyway for small hashtables. */
    uintptr_t (*hash)( Qntan_Cls cls, void*ptrToObj );
    /*
     * If NULL, impl will use its own internal strategy.
     * This gets called everytime the table needs to resize from 'oldNumElms' to
     * 'newNumElms'. Then it returns the new table size that should be used. If
     * return value is smaller than 'newNumElms', impl may choose to abort its
     * operation by reporting errors (likely ENOMEM) to its callers. Here, the
     * caller side has the chance to allocate in larger steps. Eg one could
     * return for example 'newNumElms + 4096' to allocate 4096 extra elements
     * beyond what actually gets requested, to prevent further resize demands
     * in near future. */
    uintptr_t (*onResize)( Qntan_Cls cls, uintptr_t oldNumElms, uintptr_t newNumElms );
    /*
     * Context passed to callback functions. */
    Qntan_Cls cbackCls;
	/*
	 * OUTPUT PARAMETER! Impl MUST set this to a function, to release
	 * the instance and its internal resources.
	 * WARN: If caller did put any pointers into the HashTable, those will
	 *       become dangling! Make sure to cleanup them up beforehand,
	 *       or ensure that you are otherwise in control of them. */
	void (*unref)( struct Qntan_HshTbl** );
	/**/
};

struct Qntan_HshTbl** Garbage_newHshTbl( struct Garbage_HshTbl_Opts* );










/*
 * TODO: WARN: TarEnc is NOT PRODUCTION READY yet! It is likely to
 * contain even severe bugs.
 */
struct Garbage_TarEnc_Opts {
	/**/
	struct Qntan_Mallocator **mallocator;
	/*
     * Context passed to 'onChunk'. */
	Qntan_Cls cls;
	/*
	 * @param cls
	 *      Context for callback.
	 * @param buf
	 *      The next chunk of the resulting tar archive.
	 * @param buf_len
	 *      Length of 'buf' in octets.
	 * @param flg
	 *      'flgs & 4' set indicates that this is the last chunk (EndOf
	 *      archive reached).
	 * @param err
	 *      Negative values if the write failed.
	 *      Number of octets successfully written from 'buf'.
	 * @param arg
	 *      Context to be passed to 'onDone'.
	 */
	void (*onChunk)( Qntan_Cls cls, char const*buf, int buf_len, int flg,
		void(*onDone)(int err,Qntan_Cls arg), Qntan_Cls arg );
};

struct Qntan_TarEnc** Garbage_newTarEnc( struct Garbage_TarEnc_Opts* );









struct Garbage_TarDec_Opts {
	/**/
	struct Qntan_Mallocator **mallocator;
	/**/
	/*
	 * Where to read the archive from. */
	struct Qntan_File **archive;
	/**/
};

struct Qntan_TarDec** Garbage_newTarDec( struct Garbage_TarDec_Opts* );










struct Garbage_ThreadPool_Opts {
	/* TODO enable caller to set thread names.
	 */
	struct Qntan_Mallocator **mallocator;
	/**/
	int numThrds;
	/* number of threads to use
	 */
	struct Qntan_Logger **log;
	/**/
	void (*start)( struct Qntan_Executor** );
	/* OUTPUT PARAMETER!
	 * Calling this, starts the ThreadPool.
	 */
	void (*stop)( struct Qntan_Executor**, void(*onDone)(int,Qntan_Cls), Qntan_Cls );
	/* OUTPUT PARAMETER. Will be set while ctor.
	 * WARN: This call MAY perform BLOCKING stuff on the EvLoop.
	 */
	void (*unref)( struct Qntan_Executor** );
	/* virtual dtor, gets set while ctor call */
};

struct Qntan_Executor** Garbage_newThreadPool( struct Garbage_ThreadPool_Opts* );










struct Garbage_Scheduler_Opts {
	/**/
	struct Qntan_EvLoop **evLoop;
	/**/
	struct Qntan_Mallocator **mallocator;
	/**/
	struct Qntan_Executor **executor;
	/* WARN: Impl maybe will enqueue a VERY long running task here. So make sure
	 * the executor has enough threads so blocking one doesn't cause issues in
	 * other places.
	 */
	struct Qntan_Logger **log;
	/**/
	void (*start)( struct Qntan_Scheduler** );
	/* OUTPUT PARAMETER. Set while construction. Has to be called BEFORE the
	 * scheduler will be used.
	 */
	void (*stop)( struct Qntan_Scheduler**, void(*onDone)(int,Qntan_Cls), Qntan_Cls );
	/* OUTPUT PARAMETER. Set while construction.
	 */
	void (*unref)( struct Qntan_Scheduler** );
	/* OUTPUT PARAMETER. Set while construction. Has to be called as soon the
	 * scheduler is no longer used.
	 */
};

struct Qntan_Scheduler** Garbage_newScheduler( struct Garbage_Scheduler_Opts* );










struct Garbage_PoolConnection_Opts {
	/*
	 * The allocator to be used. */
	struct Qntan_Mallocator **mallocator;
	/*
	 * Factory for the (non TLS) connections. */
	struct Garbage_SocketMgr **socketMgrPlain;
	/*
	 * Factory for the TLS encrypted connections. */
	struct Garbage_SocketMgr **socketMgrTls;
};

struct Garbage_PoolConnection**
Garbage_newPoolConnection( struct Garbage_PoolConnection_Opts* );

void
Garbage_delPoolConnection( struct Garbage_PoolConnection** );










struct Garbage_SocketMgr_Opts {
	/**/
	struct Garbage_Env **env;
	/**/
	int reuseaddr;
	/**/
	struct Qntan_Mallocator **mallocator;
	/**/
	struct Qntan_Executor **ioWorker;
	/**/
	struct Qntan_IoMux **ioMux;
	/*
	 * OUTPUT PARAMETER! */
	void (*unref)( struct Garbage_SocketMgr** );
	/**/
};

struct Garbage_SocketMgr**
Garbage_newSocketMgr( struct Garbage_SocketMgr_Opts*opts );










struct Garbage_TlsClient_Opts {
	/**/
	struct Garbage_Env **env;
// TODO unused?  	/**/
// TODO unused?  	struct Garbage_TlsClient_Mentor*mentor;
// TODO unused?  	Garbage_Closure mentorCtx;
	/**/
	struct Qntan_Mallocator **mallocator;
	/**/
	struct Qntan_IoMux **ioMux;
	/*
	 * TLS is only a decorator. Below the encryption, it still needs
	 * "just a normal" socket. And this is where those sockets come from. */
	struct Garbage_SocketMgr **backingSocketMgr;
	/*
	 * The currently used TLS implementation relies on blocking IO.
	 * Therefore for now we just use an ioWorker to prevent EvLoop from
	 * blocking. */
	struct Qntan_Executor **ioWorker;
	/*
	 * See 'SO_REUSEADDR' in
	 * "https://pubs.opengroup.org/onlinepubs/7908799/xns/setsockopt.html" */
	int reuseaddr;
	/*
	 * OUTPUT PARAMETER! (will be set by callee) */
	void (*unref)( struct Garbage_SocketMgr** );
	/**/
};

struct Garbage_SocketMgr** Garbage_newTlsClient( struct Garbage_TlsClient_Opts* );










struct Qntan_XmlDec** Garbage_newXmlDec(
    struct Garbage_Env**,
    struct Qntan_Mallocator**,
    struct Qntan_XmlDec_Mentor*;
    Qntan_Cls mentorCtx;
);









struct Garbage_ZipBrowserFile_Opts {
	/**/
	struct Qntan_Mallocator **mallocator;
	/*
	 * The backing file, where the zip archive to manage resides in. */
	struct Qntan_File **file;
	/**/
};

struct Qntan_ZipBrowser**
Garbage_newZipBrowserFile( struct Garbage_ZipBrowserFile_Opts*opts );


struct Garbage_ZipBrowserPipe_Opts {};

struct Qntan_ZipBrowser**
Garbage_newZipBrowserPipe( struct Garbage_ZipBrowserPipe_Opts*opts );










/* WARN: This is temporal only, and is intended to be replaced by ZipBrowser
 * somewhen. */
struct Garbage_ZipPipeWriter_Opts {
	/**/
	struct Qntan_Mallocator **mallocator;
	/*
	 * Where the resulting archive will be written to. */
	struct Qntan_File **file;
	/*
	 * OUTPUT PARAMETER! */
	void (*unref)( struct Qntan_ZipBrowser** );
	/**/
};

/* WARN: This is temporal only, and is intended to be replaced by ZipBrowser
 * somewhen.
 * WARN: This impl does BLOCKING IO! */
struct Qntan_ZipBrowser**
Garbage_newZipPipeWriter( struct Garbage_ZipPipeWriter_Opts* );










struct Garbage_CsvEnc_Opts {
	/**/
	struct Qntan_Mallocator **mallocator;
	/**/
	struct Qntan_EvLoop **evLoop;
	/**/
	struct Qntan_Logger **log;
	/**/
	char *colSeparator;
	/* If null, an implementation defined default will be taken.
	 * MUST be exactly ONE char in length. So `colSeparator[1]` MUST be 0x00.
	 */
	void (*onCsvChunk)( Qntan_Cls clsOnCsvChunk, char const*buf, int buf_len, int flgs,
		void(*onDone)(Qntan_Cls arg), Qntan_Cls arg );
	/* Called repeatedly, with the encoded CSV data.
	 * `flgs & 4` indicates that this is the last chunk. Other bits in `flgs`
	 * MUST be ignored.
	 * `onDone()` MUST be called as soon you're ready to receive the next chunk.
	 */
	Qntan_Cls clsOnCsvChunk;
	/* Context for `onCsvChunk()`.
	 */
	void (*unref)( struct Qntan_CsvEnc** );
	/* Virtual dtor. Will be set while ctor call.
	 */
};

struct Qntan_CsvEnc**
Garbage_newCsvEnc( struct Garbage_CsvEnc_Opts* );










struct Garbage_GfxRendererWdoofGdi_Opts {
	/**/
	struct Qntan_Logger **log;
	/**/
	struct Qntan_Mallocator **mallocator;
	/**/
	struct Qntan_EvLoop **evLoop;
	/**/
	void (*flush)( struct Qntan_GfxRenderer** );
	/* not yet sure? Initially it was a no-op? So MAYBE remove it?
	 */
	void (*unref)( struct Qntan_GfxRenderer** );
	/* OUTPUT parameter. dtor, which gets set while ctor call. */
};

struct Qntan_GfxRenderer**
Garbage_newGfxRendererWdoofGdi( struct Garbage_GfxRendererWdoofGdi_Opts* );










struct Garbage_GfxRendererX11_Opts {
	/**/
	void (*flush)( struct Qntan_GfxRenderer** );
	/* AFAIK X11 needs a `XFlush()` call to exchange draw/display
	 * buffers I guess? Not yet sure how to API-design that properly.
	 * For now I'll expose that flush-equivalent here.
	 */
	void (*unref)( struct Qntan_GfxRenderer** );
	/* OUTPUT parameter. dtor, which gets set while ctor call. */
};

struct Qntan_GfxRenderer**
Garbage_newGfxRendererX11( struct Garbage_GfxRendererX11_Opts* );










struct Garbage_GagaFont_Opts {
	/**/
	struct Qntan_Logger **log;
	/* (optional) logger.
	 */
	struct Qntan_Mallocator **mallocator;
	/**/
	void (*unref)( struct Garbage_GagaFont** );
	/* dtor which gets set while ctor call. Output parameter.
	 */
};

struct Garbage_GagaFont**
Garbage_newGagaFont( struct Garbage_GagaFont_Opts* );










struct Garbage_PoFinCsvParser_Opts {
	struct Qntan_EvLoop **evLoop;
    struct Qntan_Mallocator **mallocator;
    struct Garbage_PoFinCsvParser_Mentor **mentor;
};

struct Garbage_PoFinCsvParser** Garbage_newPoFinCsvParser(
    struct Garbage_PoFinCsvParser_Opts*
);





struct Garbage_SimpleAppendLogParser_Opts {
    struct Qntan_EvLoop **evLoop;
    struct Qntan_Mallocator **mallocator;
    struct Garbage_SimpleAppendLogParser_Mentor **mentor;
};

struct Garbage_SimpleAppendLogParser** Garbage_newSimpleAppendLogParser(
    struct Garbage_SimpleAppendLogParser_Opts*
);










struct Garbage_SwsquotCsvParser_Opts {
	/**/
	struct Qntan_Mallocator **mallocator;
	/**/
	struct Qntan_EvLoop **evLoop;
	/**/
	struct Qntan_Logger **log;
	/* (optional).
	 */
	struct Garbage_SwsquotCsvParser_Mentor **mentor;
	/**/
};

struct Garbage_SwsquotCsvParser**
Garbage_newSwsquotCsvParser( struct Garbage_SwsquotCsvParser_Opts*opts );










struct Garbage_CamtDec_Opts {
    struct Garbage_Env **env;
    struct Qntan_Mallocator **mallocator;
    struct Qntan_CamtDec_Mentor **mentor;
    Qntan_Cls newXmlDecCtx;
    struct Qntan_XmlDec** (*newXmlDec)(
        Qntan_Cls newXmlDecCtx, struct Qntan_XmlDec_Mentor*, Qntan_Cls );
};

struct Qntan_CamtDec** Garbage_newCamtDec( struct Garbage_CamtDec_Opts* );





#undef PUBLIC

#if __cplusplus
} /* extern "C" */
#endif
#endif /* INCGUARD_3PHvlW9sLiqxP9tp */

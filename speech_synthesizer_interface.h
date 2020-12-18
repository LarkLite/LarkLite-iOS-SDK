//
// Created by simonsheng on 2019/11/8.
//

#ifndef LARKLITE_SPEECH_SYNTHESIZER_INTERFACE_H
#define LARKLITE_SPEECH_SYNTHESIZER_INTERFACE_H
#include "error.h"

#ifdef WIN32
#define LARKLITE_API_EXPORTS __declspec(dllexport)
#define LARKLITE_CALL_CONV __stdcall
#else
#define LARKLITE_API_EXPORTS
#define LARKLITE_CALL_CONV
#endif

#ifdef __cplusplus
extern "C" {
#endif

// 语言
const int LANG_CHINESE = 0; // 合成中文文本
const int LANG_ENGLISH = 1; // 合成英文文本

// 发音人
const int32_t LARKLITE_SPEAKER_YEZI = 0x00000;   //叶子
const int32_t LARKLITE_SPEAKER_LIABI = 0x00001;  //李白
const int32_t LARKLITE_SPEAKER_DAJI = 0x00002;   //妲己
const int32_t LARKLITE_SPEAKER_WY = 0x00003;     //WY
const int32_t LARKLITE_SPEAKER_FYR = 0x00004;    //发声人FYR
const int32_t LARKLITE_SPEAKER_WGVYL = 0x00005;  //发声人WGVYL(小说风格男生
const int32_t LARKLITE_SPEAKER_WGVBX = 0x00006;  //发音人WGVBX(小说风格女生)
const int32_t LARKLITE_SPEAKER_WGVNG = 0x00007;  //发声人WGVYL(资讯风格男生)
const int32_t LARKLITE_SPEAKER_WGVZW = 0x00008;  //发音人WGVBX(资讯风格女生)
const int32_t LARKLITE_SPEAKER_XMINI = 0x00009;  //发声人XMINI(优必选机器人)
const int32_t LARKLITE_SPEAKER_MAPWY = 0x00010;  //发声人MAPWY(导航WY)

// 日志级别
const int LARKLITE_LOG_LEVEL_NONE = 1;     //关闭
const int LARKLITE_LOG_LEVEL_VERBOSE = 2;  //显示
const int LARKLITE_LOG_LEVEL_DEBUG = 3;    //调试
const int LARKLITE_LOG_LEVEL_INFO = 4;     //信息
const int LARKLITE_LOG_LEVEL_WARNING = 5;  //警告
const int LARKLITE_LOG_LEVEL_ERROR = 6;    //错误
const int LARKLITE_LOG_LEVEL_FATAL = 7;    //死亡

// 合成参数
const int LARKLITE_PARAMETER_SYNTHESIZE_PROC_WAITING = 0;               //开始合成等待
const int LARKLITE_PARAMETER_SYNTHESIZE_PROC_WAITING_THRESHOLD = 1;     //触发合成等待阈值
const int LARKLITE_PARAMETER_SYNTHESIZE_PROC_MINIMUM_MSPS = 2;          //最小分片处理时间

/**
 * @param data 离线TTS合成流式音频数据
 * @param dataLen 离线TTS合成流式音频数据长度
 * @param bBegin 合成首包的flag。
 * @param bEnd 合成尾包的flag。
 * @param sMsgId 合成传入的id
 */
typedef void (LARKLITE_CALL_CONV *LARKLITE_CALLBACK)(const char *data, int dataLen, bool bBegin, bool bEnd, const char* sMsgId);
/**
 * @param retCode 异常错误吗.错误码，参考error.h
 * @param sRetMsg 异常错误信息
 * @param sMsgId 合成传入的id
 */
typedef void (LARKLITE_CALL_CONV *LARKLITE_ERR_CALLBACK)(int retCode, const char* sRetMsg, const char* sMsgId);

/**
* @param logLevel 日志等级
* @param msg 日志信息
*/
typedef void (LARKLITE_CALL_CONV *LogCallback)(int logLevel, const char *msg);
/**
 * 初始化离线TTS
 * @param folderPath 离线TTS模型所在文件夹路径
 * @param callback 离线TTS回调接口
 * @param errCallback  离线TTS异常回调接口
 * @return 0：success；other：failed。错误码，参考error.h
 * 注：初始化在当前调用线程完成，上层要保证初始化不占用UI线程，避免出现anr
 */
LARKLITE_API_EXPORTS int larklite_initialize(const char *folderPath, LARKLITE_CALLBACK callback, LARKLITE_ERR_CALLBACK errCallback, LogCallback logCallback);

/**
 * 初始化离线TTS
 * @param folderPathArray 离线TTS模型路径，请传入多个模型文件的全路径
 * @param folderCount 模型文件的数量
 * @param callback 离线TTS回调接口
 * @param errCallback  离线TTS异常回调接口
 * @return 0：success；other：failed。错误码，参考error.h
 * 注：初始化在当前调用线程完成，上层要保证初始化不占用UI线程，避免出现anr
 */
LARKLITE_API_EXPORTS int larklite_initialize_ex(const char **folderPathArray, int folderCount, LARKLITE_CALLBACK callback, LARKLITE_ERR_CALLBACK errCallback, LogCallback logCallback);

/**
 * 追加角色模型，当前模型集合不属于init集合
 * @param folderPath 追加模型所在文件夹的路径
 * @return 0：success;other：failed。错误码，参考error.h
 * 注：当前追加模型返回，只要有一个模型成功，就返回0。全部不成功，则返回失败
 */
LARKLITE_API_EXPORTS int larklite_appendSpeakers(const char *folderPath);

/**
 * 追加角色模型，当前模型集合不属于init集合
 * @param folderPathArray 追加模型的路径，请传入多个模型文件的全路径
 * @param folderCount 追加模型文件的数量
 * @return 0：success;other：failed。错误码，参考error.h
 * 注：当前追加模型返回，只要有一个模型成功，就返回0。全部不成功，则返回失败
 */
LARKLITE_API_EXPORTS int larklite_appendSpeakers_ex(const char **folderPathArray, int folderCount);
/**
 * 获取可用speaker列表,终端可以根据这个列表，设置发音人，但是必须调用larklite_synthesizerByName进行合成
 * @param out 输出角色列表，上层不需要new，只需要创建char** out={0};将&out传入即可，但是上层需要调用detele[] out;进行对象释放
 * @param outLen 输出角色列表数量,初始值int outlen = 0;传入&outlen即可
 * @return 0：success；1：failed.错误码，参考error.h
 */
LARKLITE_API_EXPORTS int larklite_getAvailableSpeaker(char*** out, int* outLen);

/**
* @param parameter 参数
* @param value 值
*/
LARKLITE_API_EXPORTS int larklite_setParameter(const int parameter, int value);

/**
 * 获取底层版本号
 * @return version
 */
LARKLITE_API_EXPORTS const char* larklite_getVersion();
/**
 * 离线TTS合成接口，合成的流式音频，通过LARKLITE_CALLBACK返回，如果出现异常，会通过LARKLITE_ERR_CALLBACK返回
 * 当前方法已经过时，目前仅支持已列的11个发音人，后续增加的发音人，使用larklite_synthesizerByName接口
 * @param sText 合成的文本
 * @param iPrimaryLanguage 设置合成的语言
 * @param iSpeaker 设置合成说话人
 * @param iSpeed 设置合成的速度
 * @param iVolume 音量
 * @param sMsgId 合成的id，因为合成的返回会通过线程返回，因此当前id方便业务层区分哪次请求的返回
 * @return 0：success；1：failed.错误码，参考error.h
 * 注：当前方法运行，即合成方法，主要运行在请求线程中，callback是在返回线程中，
 * 避免卡顿问题，必须确保不能在callback线程，做请求合成处理
 */
LARKLITE_API_EXPORTS int larklite_synthesize(const char *sText, int iPrimaryLanguage, int iSpeaker, int iSpeed, int iVolume, const char *sMsgId);
/**
 * 跟进speaker名字完成离线TTS合成功能接口，合成的流式音频，通过LARKLITE_CALLBACK返回，如果出现异常，会通过LARKLITE_ERR_CALLBACK返回
 * @param sText 合成的文本
 * @param iPrimaryLanguage 设置合成的语言
 * @param sSpeaker 设置合成说话人
 * @param iSpeed 设置合成的速度
 * @param iVolume 音量
 * @param sMsgId 合成的id，因为合成的返回会通过线程返回，因此当前id方便业务层区分哪次请求的返回
 * @return 0：success；1：failed.错误码，参考error.h
 * 注：当前方法运行，即合成方法，主要运行在请求线程中，callback是在返回线程中，
 * 避免卡顿问题，必须确保不能在callback线程，做请求合成处理
 */
LARKLITE_API_EXPORTS int larklite_synthesizerByName(const char* sText, int iPrimaryLanguage, const char* sSpeaker, int iSpeed, int iVolume, const char* sMsgId);
/**
 * 取消当前合成任务
 * @param sMsgId
 * @return 0：success；other：failed.错误码，参考error.h
 */
LARKLITE_API_EXPORTS int larklite_cancel(const char *sMsgId);
/**
 * 设置log级别
 * @param debugLevel log级别
 * @return 0：success；other：failed.错误码，参考error.h
 */
LARKLITE_API_EXPORTS int larklite_setDebugLevel(int debugLevel);
/**
 * 释放离线TTS合成解码器，释放之后，必须重新init才能使用
 * @return 0：success；other：failed.错误码，参考error.h
 */
LARKLITE_API_EXPORTS int larklite_destroy();

#ifdef __cplusplus
}
#endif
#endif //LARKLITE_SPEECH_SYNTHESIZER_INTERFACE_H

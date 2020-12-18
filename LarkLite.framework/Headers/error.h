//
// Created by shidong sheng on 2020-05-07.
//

#ifndef LARKLITE_SPEECH_SYNTHESIZER_ERROR_H
#define LARKLITE_SPEECH_SYNTHESIZER_ERROR_H
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
/**
     * 调用成功
     */
const int SUCCESS = 0;
/**
 * 未初始化错误
 */
const int NOT_INIT_LIB_ERR = -2;
/**
 * 无效参数
 */
const int INVALID_PARAMS = -3;
/**
 * 未知错误
 */
const int UNKNOW_ERR = -99;
/**
 * 合成任务已取消
 */
const int CANCELLED = 1;
/**
 * 文件打开模型文件失败
 */
const int FILE_OPEN_ERROR = 2;
/**
 * 读取模型文件失败，没有写的权限
 */
const int FILE_READ_ERROR = 3;
/**
 * 写文件失败，没有写的权限
 */
const int FILE_WRITE_ERROR = 4;
/**
 * 模型文件不存在
 */
const int FILE_NOT_EXIST_ERROR = 5;
/**
 * 模型文件不全
 */
const int FILE_SEEK_ERROR = 6;
/**
 * 目录状态异常
 */
const int DIRECTORY_STAT_ERROR = 7;
/**
 * 目录打开失败
 */
const int DIRECTORY_OPEN_ERROR = 8;
/**
 * 空对象异常错误
 */
const int NULL_POINTER_ERROR = 9;
/**
 * 虚拟方法取消
 */
const int VIRTUAL_METHOD_UNIMPLEMENTED = 10;
/**
 * 模型版本错误
 */
const int RESOURCE_VERSION_ERROR = 11;
/**
 * 模型文件未找到错误
 */
const int RESOURCE_FILE_NOT_EXIST = 12;
/**
 * 资源超出最大值
 */
const int RESOURCE_EXCEED_MAX = 13;
/**
 * 资源参数不支持
 */
const int RESOURCE_PARAMETER_UNSUPPORT = 14;
/**
 * 加载模型错误
 */
const int LOAD_MODEL_ERROR = 15;
/**
 * 文本分片错误
 */
const int TEXT_SPLIT_ERROR = 16;
/**
 * 文本前端合成异常
 */
const int TEXT_FRONTEND_SYNTHESIS_ERROR = 17;
/**
 * 创建模型异常
 */
const int TENSORFLOW_BUILD_MODEL_ERROR = 18;
/**
 * 创建解码器异常
 */
const int TENSORFLOW_BUILD_INTERPRETER_ERROR = 19;
const int TENSORFLOW_ALLOCATE_TENSORS_ERROR = 20;
const int TENSORFLOW_DIM_ERROR = 21;
/**
 * 映射异常
 */
const int TENSORFLOW_INVOKE_ERROR = 22;
const int SMOOTH_WINDOW_ERROR = 23;
const int LF0_SIZE_ERROR = 24;
const int SPTK_MEMORY_MALLOC_ERROR = 25;
const int SPTK_DIM_ERROR = 26;
const int VOCODER_PARAMETER_ERROR = 27;
const int VOCODER_FFT_INIT_ERROR = 28;
const int VOCODER_NOISE_SPECTRUM_TABLE = 29;
#ifdef __cplusplus
}
#endif
#endif //LARKLITE_SPEECH_SYNTHESIZER_ERROR_H

#include "util/util.h"
#include "error/ErrorManager.h"

const string ErrorManager::FileManagerTag = "FileManager";
const string ErrorManager::TimerTag = "Timer";
const string ErrorManager::SourceLineTag = "SourceLine";
const string ErrorManager::DebugTag = "Debug";
const string ErrorManager::error_type_class_not_found = "class_not_found";
const string ErrorManager::error_type_super_type_not_found = "super_type_not_found";
const string ErrorManager::error_type_super_constructor_not_found = "super_constructor_not_found";
const string ErrorManager::error_type_field_name_not_found = "field_name_not_found";
const string ErrorManager::error_type_method_name_not_found = "method_name_not_found";
const string ErrorManager::error_type_method_parameter_count = "method_parameter_count";
const string ErrorManager::error_type_method_parameter_type = "method_parameter_type";
const string ErrorManager::error_type_lambda_type_inference = "lambda_type_inference";
const string ErrorManager::error_type_lambda_parameter_count = "lambda_parameter_count";
const string ErrorManager::error_type_anonymous_no_type_name = "anonymous_no_type_name";
const string ErrorManager::error_type_type_parameter = "type_parameter";


map<string, list<ErrorInfo>> ErrorManager::mk2errorInfo;

bool ErrorManager::debugRuntime = false;
bool ErrorManager::log_value = false;
bool ErrorManager::log_parse_reduce = false;
bool ErrorManager::log_stack_size = false;
bool ErrorManager::log_put_name_scope = false;
bool ErrorManager::log_parallel_structure = false;
bool ErrorManager::log_post_fix_expression = log_value;
bool ErrorManager::log_handle_variable = log_value;
bool ErrorManager::log_handle_method = log_value;
bool ErrorManager::log_handle_optr = log_value;
bool ErrorManager::log_set_current_method = log_value;
bool ErrorManager::log_push_method_invocation = log_value;
bool ErrorManager::log_push_resolving = log_value;
bool ErrorManager::log_put_expression_name = false;
bool ErrorManager::log_param_and_argument = log_value;
bool ErrorManager::log_put_relation = log_value;
bool ErrorManager::log_index_inside_exp = log_value;
bool ErrorManager::log_error = false;
bool ErrorManager::log_anonymous_class = false;
bool ErrorManager::log_condition = false;
bool ErrorManager::log_reference_chain = log_value;
bool ErrorManager::log_error_infinite_recur = false;

void ErrorManager::handleError(const string &error_type, const string &inWitchMK, const string &extraInfo) {
    ErrorInfo errorInfo{};
    errorInfo.errorType = error_type;
    errorInfo.extraInfo = extraInfo;
    if (mk2errorInfo.count(inWitchMK) == 0) {
        list<ErrorInfo> l;
        mk2errorInfo.insert(pair<string, list<ErrorInfo>>(inWitchMK, l));
    }
    mk2errorInfo.at(inWitchMK).push_back(errorInfo);
    if (log_error) {
        easyPrint(error_type + "|||" + inWitchMK + "|||" + extraInfo);
    }
}

void ErrorManager::init() {
    spdlog::stdout_color_mt(FileManagerTag)->   set_pattern("%^[%m/%d %T] %P %t %L %n: %v%$");
    spdlog::stdout_color_mt(TimerTag)->         set_pattern("%^[%m/%d %T] %P %t %L %n:(%o) %v%$");
    spdlog::stdout_color_mt(SourceLineTag)->    set_pattern("%^[%m/%d %T] %P %t %L %n: %v %@%$");
    spdlog::stdout_color_mt(DebugTag)->         set_pattern("%^[%m/%d %T] %P %t %L %n: %v%$");
}

//void ErrorManager::convertErrorInfo2Json(ErrorInfo &info, Json::Value &value) {
//    value["errorType"] = info.errorType;
//    value["extraInfo"] = info.extraInfo;
//}



struct ErrorInfo {
    string errorType;
    string extraInfo;
};


class ErrorManager {
public:
    static const string FileManagerTag;
    static const string TimerTag;
    static const string SourceLineTag;
    static const string DebugTag;
    static const string error_type_class_not_found;
    static const string error_type_super_type_not_found;
    static const string error_type_super_constructor_not_found;
    static const string error_type_field_name_not_found;
    static const string error_type_method_name_not_found;
    static const string error_type_method_parameter_count;
    static const string error_type_method_parameter_type;
    static const string error_type_lambda_type_inference;
    static const string error_type_lambda_parameter_count;
    static const string error_type_anonymous_no_type_name;
    static const string error_type_type_parameter;

    static map<string, list<ErrorInfo>> mk2errorInfo;

    static void handleError(const string &error_type, const string &inWitchMK, const string &extraInfo);

    static bool debugRuntime;
    static bool log_value;
    static bool log_parse_reduce;
    static bool log_stack_size;
    static bool log_put_name_scope;
    static bool log_parallel_structure;
    static bool log_post_fix_expression;
    static bool log_handle_variable;
    static bool log_handle_method;
    static bool log_handle_optr;
    static bool log_set_current_method;
    static bool log_push_method_invocation;
    static bool log_push_resolving;
    static bool log_put_expression_name;
    static bool log_param_and_argument;
    static bool log_put_relation;
    static bool log_index_inside_exp;
    static bool log_error;
    static bool log_anonymous_class;
    static bool log_condition;
    static bool log_reference_chain;
    static bool log_error_infinite_recur;

    static void init();
};



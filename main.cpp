#include <cstdlib>
#include <iostream>
#include <sstream>

#include <chatgpt.h>

void callback(const chatgpt_callback_kind kind, const char *s) {
    if (kind == chatgpt_callback_kind_content) {
        std::cout << s << std::flush;
    } else if (kind == chatgpt_callback_kind_stop) {
        std::cout << std::endl;
    }
}

int main(int argc, char *argv[]) {
    const char *api_key = std::getenv("OPENAI_API_KEY");
    if (api_key == nullptr) {
        std::cerr << "OPENAI_API_KEY environment variable not found." << std::endl;
        return EXIT_FAILURE;
    }
    if (argc == 1) {
        std::cerr << "Command line arguments are not found." << std::endl;
        return EXIT_FAILURE;
    }

    std::stringstream ss;
    ss << argv[1];
    for (int i = 2; i < argc; ++i) {
        ss << ' ' << argv[i];
    }
    std::string content = ss.str();
    chatgpt_message message;
    message.role = chatgpt_role_user;
    message.content = content.c_str();

    chatgpt_completions(api_key, 1, &message, callback);

    return EXIT_SUCCESS;
}

#ifndef TOY_LANG_TOKENIZER
#define TOY_LANG_TOKENIZER

#include <variant>
#include <string>
#include <istream>


struct SymbolToken
{
    std::string name;
};

struct ConstantToken{
    int value;
};

// Используем enum class.
enum class EmbracingToken{
    LPAREN,
    RPAREN,
    COMMA,
    IF,
    THEN,
    ELSE
};

enum class OperatorToken{
    PLUS,
    MINUS,
    MULTIPLY,
    DIVIDE,
    EQ_EQ,
    NOT_EQ,
    LESS,
    EQ
};

// это не лучшее решение смешать эти токены, но другие решения тоже не идеальны
enum class UtilityTokens{
    DEF,
    RETURN,
    NEWLINE,
    EOFT
};



using Token = std::variant<
    SymbolToken,
    ConstantToken,
    EmbracingToken,
    OperatorToken,
    UtilityTokens>;


class Tokenizer{
public:
    Tokenizer(std::istream *in);

    bool IsEnd();

    void Next();

    Token GetToken();
};

#endif TOY_LANG_TOKENIZER
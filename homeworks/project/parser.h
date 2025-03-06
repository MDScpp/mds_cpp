#ifndef TOY_LANG_PARSER
#define TOY_LANG_PARSER

#include <istream>
#include <optional>
#include <variant>

class ASTNode {
public:
  virtual ~ASTNode() = default;
  //virtual void accept(class Visitor &visitor) = 0;
};


class Expr : public ASTNode { /*...*/
};

class Statement : public ASTNode { /*...*/
};


/*

....

*/



class Parser {
  // переменные

public:
  // Публичные методы и конструкторы

private:
  std::unique_ptr<FunctionDefAST> parseFunctionDef();
  std::unique_ptr<StatementAST> parseStatement();
  std::unique_ptr<ExprAST> parseExpression();
  std::unique_ptr<ExprAST> parseTernaryExpr();
  std::unique_ptr<ExprAST> parseLogicalExpr();
  std::unique_ptr<ExprAST> parseAddExpr();
  std::unique_ptr<ExprAST> parseMulExpr();
  std::unique_ptr<ExprAST> parsePrimary();
  // ... остальные методы
};

#endif
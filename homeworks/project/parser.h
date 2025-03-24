#ifndef TOY_LANG_PARSER
#define TOY_LANG_PARSER

#include <memory>
#include <string>
#include <vector>

class NodeAST {
public:
  virtual ~NodeAST() = default;
  virtual void accept(Visitor &visitor) = 0;
};



class ExprAST : public NodeAST { 
  /*...*/
  public:
  void accept(Visitor &visitor) override;
};

class StatementAST : public NodeAST { 
  /*...*/
  public:
  void accept(Visitor &visitor) override;
};


class FunctionDefAST : public NodeAST {
  std::string name;
  std::vector<std::string> params;
  std::vector<std::unique_ptr<StatementAST>> body;
  std::unique_ptr<ExprAST> return_expr;
public:
  void accept(Visitor &visitor) override;
};

/*
other classes
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
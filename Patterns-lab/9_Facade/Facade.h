#pragma once
#include <iostream>
#include <vector>
#include <string>

class Stream {
public:
    virtual void write(const std::string& data) = 0;
    virtual std::string read() = 0;
};

// Поток байт-кода
class BytecodeStream : public Stream {
public:
    void write(const std::string& data) override {
        std::cout << "Writing bytecode: " << data << std::endl;
        buffer += data;
    }

    std::string read() override {
        std::string result = buffer;
        buffer.clear();
        return result;
    }

private:
    std::string buffer;
};

class ProgramNode;
class StatementNode;
class ExpressionNode;

// Базовый класс генератора кода
class CodeGenerator {
public:
    CodeGenerator(BytecodeStream* output) : output(output) {}
    virtual void generate(ProgramNode* programNode) = 0;

protected:
    BytecodeStream* output;
};

// Узел абстрактного синтаксического дерева (AST)
class Node {
public:
    virtual void traverse(CodeGenerator* generator) = 0;
};

class ExpressionNode : public Node {
public:
    void traverse(CodeGenerator* generator) override {
        std::cout << "Traversing expression node" << std::endl;
    }
};

class StatementNode : public Node {
public:
    void traverse(CodeGenerator* generator) override {
        std::cout << "Traversing statement node" << std::endl;
    }
};

class ProgramNode : public Node {
public:
    void addStatement(StatementNode* statement) {
        statements.push_back(statement);
    }

    void addExpression(ExpressionNode* expression) {
        expressions.push_back(expression);
    }

    void traverse(CodeGenerator* generator) override {
        std::cout << "Traversing program node" << std::endl;
        for (auto stmt : statements) {
            stmt->traverse(generator);
        }
        for (auto expr : expressions) {
            expr->traverse(generator);
        }
        generator->generate(this);
    }

    ~ProgramNode() {
        for (auto stmt : statements) delete stmt;
        for (auto expr : expressions) delete expr;
    }

private:
    std::vector<StatementNode*> statements;
    std::vector<ExpressionNode*> expressions;
};

// Генератор кода для стековой машины
class StackMachineCodeGenerator : public CodeGenerator {
public:
    StackMachineCodeGenerator(BytecodeStream* output) : CodeGenerator(output) {}

    void generate(ProgramNode* programNode) override {
        std::cout << "Generating stack machine code" << std::endl;
        output->write("STACK_MACHINE_BYTECODE");
    }
};

// Генератор кода для RISC архитектуры
class RISCCodeGenerator : public CodeGenerator {
public:
    RISCCodeGenerator(BytecodeStream* output) : CodeGenerator(output) {}

    void generate(ProgramNode* programNode) override {
        std::cout << "Generating RISC code" << std::endl;
        output->write("RISC_BYTECODE");
    }
};

// Токен
class Token {
public:
    Token(const std::string& type, const std::string& value)
        : type(type), value(value) {
    }

    std::string getType() const { return type; }
    std::string getValue() const { return value; }

private:
    std::string type;
    std::string value;
};

// Символ таблицы символов
class Symbol {
public:
    Symbol(const std::string& name, const std::string& type)
        : name(name), type(type) {
    }

    std::string getName() const { return name; }
    std::string getType() const { return type; }

private:
    std::string name;
    std::string type;
};

// Сканер (лексический анализатор)
class Scanner {
public:
    std::vector<Token*> scan(const std::string& source) {
        std::cout << "Scanning source code" << std::endl;
        std::vector<Token*> tokens;

        // Простая имитация сканирования
        tokens.push_back(new Token("KEYWORD", "if"));
        tokens.push_back(new Token("IDENTIFIER", "x"));
        tokens.push_back(new Token("OPERATOR", ">"));
        tokens.push_back(new Token("NUMBER", "10"));
        return tokens;
    }
};

// Построитель узлов AST
class ProgramNodeBuilder {
public:
    ProgramNodeBuilder() : programNode(new ProgramNode()) {}

    ~ProgramNodeBuilder() {
        delete programNode;
    }

    ProgramNode* getRootNode() {
        ProgramNode* result = programNode;
        programNode = new ProgramNode(); // Сбрасываем для следующего использования
        return result;
    }

    void buildStatement(StatementNode* statement) {
        programNode->addStatement(statement);
    }

    void buildExpression(ExpressionNode* expression) {
        programNode->addExpression(expression);
    }

private:
    ProgramNode* programNode;
};

// Парсер (синтаксический анализатор)
class Parser {
public:
    Parser() : scanner(new Scanner()), builder(new ProgramNodeBuilder()) {}
    ~Parser() {
        delete scanner;
        delete builder;
    }

    ProgramNode* parse(const std::string& source) {
        std::cout << "Parsing source code" << std::endl;
        std::vector<Token*> tokens = scanner->scan(source);

        // Простая имитация разбора
        for (Token* token : tokens) {
            std::cout << "Processing token: " << token->getValue() << std::endl;
            if (token->getType() == "KEYWORD") {
                builder->buildStatement(new StatementNode());
            }
            else {
                builder->buildExpression(new ExpressionNode());
            }
            delete token;
        }

        return builder->getRootNode();
    }

private:
    Scanner* scanner;
    ProgramNodeBuilder* builder;
};
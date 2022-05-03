#ifndef EXPR_H
#define EXPR_H

class Expr {
public:
    virtual ~Expr() {}

    int line() const { return m_line; }
    virtual Type* expr() = 0;

protected:
    explicit Expr(int line) : m_line(line) {}

private:
    int m_line;

};

#endif

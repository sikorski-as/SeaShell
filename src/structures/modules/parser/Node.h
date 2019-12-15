class Node {
    protected:
        NodeType type;
    public:
        virtual NodeType getType();
        Node(/* args */);
        ~Node();
};

enum class NodeType {
    PROGRAM,
    PIPE_EXPR,
    REDIRECTION_EXPR,
    IDENTIFIER,
    BACKTICK_EXPR,
    VARIABLE_CALL,
    COMMAND,
    VARIABLE_ASSIGNMENT
};

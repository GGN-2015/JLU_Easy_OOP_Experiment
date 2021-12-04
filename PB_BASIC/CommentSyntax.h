#ifndef COMMENTSYNTAX_H
#define COMMENTSYNTAX_H

#include "ISyntax.h"

class StringStream;
class CommentSyntax: public ISyntax { // ����ʶ��ע�� 
public:
    bool        check(StringStream&);
    std::string match(StringStream&);
    
    static CommentSyntax* getInstance();
    virtual bool vital();
    
    virtual std::string getSyntaxName() const;
};

#endif


#ifndef CONTEXT_H
#define CONTEXT_H


class Context
{
    public:
        Context(char l1, char l2, char r1, char r2, char t1, char t2, char b1, char b2) {

            this->l1 = l1;
            this->l2 = l2;
            this->r1 = r1;
            this->r2 = r2;
            this->t1 = t1;
            this->t2 = t2;
            this->b1 = b1;
            this->b2 = b2;

        }
        virtual ~Context() {}

        char l1;
        char l2;
        char r1;
        char r2;
        char t1;
        char t2;
        char b1;
        char b2;

    protected:

    private:

};

#endif // CONTEXT_H

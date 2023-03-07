
#ifndef CASE_H_
#define CASE_H_


class Case{

public:
	Case(int x, int y, int value);
	int get_x(){return x;};
	int get_y(){return y;};
	int get_value(){return value;};
private:
	int x;
	int y;
	int value;
};


#endif /* CASE_H_ */

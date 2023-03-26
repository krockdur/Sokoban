#ifndef CASE_H_
#define CASE_H_


class Case {


public:
	Case() = default;
	Case(int x, int y, char value) { this->x = x; this->y = y; this->value = value; };

	// Getters
	int get_x() { return x; };
	int get_y() { return y; };
	char get_value() { return value; };

	// Setters
	void set_value(char val) { this->value = val; };
	void set_values( int x, int y, char val ) { this->x = x; this->y = y; this->value = val; };

private:
	int x;
	int y;
	char value;
};


#endif /* CASE_H_ */

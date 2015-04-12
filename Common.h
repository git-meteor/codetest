#ifndef COMMON_H_
#define COMMON_H_

#define ARRAY_SIZE(a) (sizeof((a))/sizeof(int))

class TestCase {
public:
	virtual void Test() = 0;
	virtual ~TestCase() {;}
};

#endif

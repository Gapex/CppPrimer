/*
（a)赋值运算符优先级很低，会先计算 getPtr() != 0，其结果是`bool`型的，因此p的值只能会是0/1
（b)可能想要判读i是否等于1024，但是这样写结果总是为`true`，即：先将1024赋值给i，再将i作为条件表达式，其结果一定为`true`
*/
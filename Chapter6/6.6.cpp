/*
parameter和local variable都具有局部作用域，
局部变量必须显式初始化，否则其值是未定义的
形式参数使用实际参数的值初始化，
他们的声明周期都是从定义处开始，局部作用域结束时其值是未定义的
local static variable在第一次执行到其定义语句时初始化，且仅初始化一次
在函数调用期间可见，但是其声明周期是整个程序运行期间
*/
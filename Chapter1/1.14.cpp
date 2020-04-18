/*
两种循环的测试条件都需要使用一个变量
for循环将条件变量的初始化和改变变量的操作都放在了header中，使得使用者能够将注意力集中在使用循环体处理实际的逻辑上
for循环在每次执行完循环体都会将条件变量改变，这的确能够处理绝大部分的情况
但是有时条件变量的改变并不需要每次都发生，如果条件变量的改变是有具体条件的，就应该使用while循环，把条件变量的改变
操作放置在循环体中
*/
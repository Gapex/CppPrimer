/*
分号标志着语句的结束
std::cout << "The sum of " << v1;
中，std::cout << "The sum of" 表达式返回cout对象
接着使用该对象调用 std::cout << v1
打印完v1后，语句结束，返回结果std::cout被丢弃，
因此 << " and " << v2; 无法编译通过，因为 << 操作符缺少左操作数，后续语句也是由于同样原因是非法的

将v1和v2后的分号去掉，该调用就是合法的
*/
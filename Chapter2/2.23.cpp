/*
如果指针所记录的地址是0，则可以断定指针不指向任何对象
如果非0，则无法断定
p可能指向有效的内存，该处存放着有效对象，也可存放无效对象
p还可能指向已经被回收的内存，对p解引用将导致segment fault
*/
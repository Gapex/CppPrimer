/*
无符号数无法表示负数，会将补码形式的负数当作正数解释，
比如-1的补码为 111111111 11111111 11111111 11111111，
将其解释为一个无符号数，最高位的1不再是符号位，因此，该数就是 2^32 - 1，即，4294967495
*/
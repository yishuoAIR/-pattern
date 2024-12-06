# -pattern
真值表转pattern，采用C++。

一、
Test_pattern_01
输入：
01XX10
输出：
010010
010110
011010
011110

二、
Test_pattern_01LH
输入：
01XX10
输出1：(你输入上去的)
HL
输出：
010010HL
010110HL
011010HL
011110HL

三、
Test_pattern_INC01LH
//注：INC可以换成其他的
输入：
01XX10
输出1：(你输入上去的)
HL
输出：
 INC010010HL
 INC010110HL
 INC011010HL
 INC011110HL

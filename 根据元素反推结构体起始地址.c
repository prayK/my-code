
//获得一个结构体变量成员在此结构体中的偏移量
// TYPE为结构体类型，MEMBER为结构体内的变量名
//((TYPE*)0)是欺骗编译器说有一个指向结构体TYPE的指针，其地址为0
//(((TYPE*)0)->MEMBER)是要取得结构体TYPE中成员变量MEMBER的地址，
//因为基地址为0，所以此时MEMBER的地址就是MEMBER在TYPE中的偏移
#define offsetof(TYPE, MEMBER) ((size_t)((TYPE *)0)->MEMBER)

//从结构体TYPE某个成员变量MEMBER指针PTR来求出该结构体TYPE的首指针
// C语言中的typeof的参数可以是表达式或者类型，用于表达式时，该表达式是不会执行的
// const typeof(((TYPE *)0)->MEMBER) 是为了取出member成员的变量类型
//是为了取出MEMBER成员的变量类型
//定义__MPTR指针PTR为指向该成员变量的指针(即指向PTR所指向的变量处)
//(TYPE *)(char *)__MPTR - offsetof(TYPE, MEMBER)用该成员变量
//的实际地址减去该变量在结构体中的便宜，来求出结构体的起始地址
#define container_of(PTR, TYPE, MEMBER)             \
  (const typeof(((TYPE *)0)->MEMBER) *__MPTR = PTR; \
   (TYPE *)(char *)__MPTR - offsetof(TYPE, MEMBER));

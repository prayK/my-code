
//���һ���ṹ�������Ա�ڴ˽ṹ���е�ƫ����
// TYPEΪ�ṹ�����ͣ�MEMBERΪ�ṹ���ڵı�����
//((TYPE*)0)����ƭ������˵��һ��ָ��ṹ��TYPE��ָ�룬���ַΪ0
//(((TYPE*)0)->MEMBER)��Ҫȡ�ýṹ��TYPE�г�Ա����MEMBER�ĵ�ַ��
//��Ϊ����ַΪ0�����Դ�ʱMEMBER�ĵ�ַ����MEMBER��TYPE�е�ƫ��
#define offsetof(TYPE, MEMBER) ((size_t)((TYPE *)0)->MEMBER)

//�ӽṹ��TYPEĳ����Ա����MEMBERָ��PTR������ýṹ��TYPE����ָ��
// C�����е�typeof�Ĳ��������Ǳ��ʽ�������ͣ����ڱ��ʽʱ���ñ��ʽ�ǲ���ִ�е�
// const typeof(((TYPE *)0)->MEMBER) ��Ϊ��ȡ��member��Ա�ı�������
//��Ϊ��ȡ��MEMBER��Ա�ı�������
//����__MPTRָ��PTRΪָ��ó�Ա������ָ��(��ָ��PTR��ָ��ı�����)
//(TYPE *)(char *)__MPTR - offsetof(TYPE, MEMBER)�øó�Ա����
//��ʵ�ʵ�ַ��ȥ�ñ����ڽṹ���еı��ˣ�������ṹ�����ʼ��ַ
#define container_of(PTR, TYPE, MEMBER)             \
  (const typeof(((TYPE *)0)->MEMBER) *__MPTR = PTR; \
   (TYPE *)(char *)__MPTR - offsetof(TYPE, MEMBER));
